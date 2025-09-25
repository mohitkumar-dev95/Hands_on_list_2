/*
======================================================================================
Name        : 17b
Author      : Mohit Kumar
Description : Program to execute ls -l | wc using dup2
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child 1: ls -l
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
    }

    if (fork() == 0) {
        // Child 2: wc
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
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
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 17b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 17b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
     31     272    1841
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 

======================================================================================
*/

