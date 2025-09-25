/*
======================================================================================
Name        : 17a
Author      : Mohit Kumar
Description : Program to execute ls -l | wc using dup (fixed to behave correctly)
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
        close(1);         // close stdout
        dup(fd[1]);       // duplicate fd[1] to stdout (fd 1)
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp failed");
    }

    if (fork() == 0) {
        // Child 2: wc
        close(fd[1]);
        close(0);         // close stdin
        dup(fd[0]);       // duplicate fd[0] to stdin (fd 0)
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
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 17a.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
     31     272    1841
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 


======================================================================================
*/


