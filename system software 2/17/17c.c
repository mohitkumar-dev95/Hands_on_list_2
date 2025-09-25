/*
======================================================================================
Name        : 17c
Author      : Mohit Kumar
Description : Program to execute ls -l | wc using fcntl
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child 1: ls -l
        close(fd[0]);
        int newfd = fcntl(fd[1], F_DUPFD, 1); // duplicate fd[1] to >=1
        if (newfd != 1) {
            close(1);
            dup(newfd);
        }
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
    }

    if (fork() == 0) {
        // Child 2: wc
        close(fd[1]);
        int newfd = fcntl(fd[0], F_DUPFD, 0); // duplicate fd[0] to >=0
        if (newfd != 0) {
            close(0);
            dup(newfd);
        }
        close(fd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp failed");
    }

    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 17c.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
     32     281    1903
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$


======================================================================================
*/

