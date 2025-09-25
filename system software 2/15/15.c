/*
======================================================================================
Name        : 15
Author      : Mohit Kumar
Description : Program to send data from parent to child process using pipe
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char msg[] = "Hello Child";
    char buf[50];
    pipe(fd);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(fd[0]); // close read end
        write(fd[1], msg, strlen(msg)+1);
    } else {
        // Child process
        close(fd[1]); // close write end
        read(fd[0], buf, sizeof(buf));
        printf("Child received: %s\n", buf);
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 15.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 15.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Child received: Hello Child
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$


======================================================================================
*/

