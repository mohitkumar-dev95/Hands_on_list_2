/*
======================================================================================
Name        : 14
Author      : Mohit Kumar
Description : Program to create a pipe, write to it, read from it, and display on monitor
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char msg[] = "Hello Pipe";
    char buf[50];

    pipe(fd);

    write(fd[1], msg, strlen(msg)+1);

    read(fd[0], buf, sizeof(buf));

    printf("Message from pipe: %s\n", buf);

    return 0;
}

/*
======================================================================================
OUTPUT:

======================================================================================
*/

