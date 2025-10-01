/*
======================================================================================
Name        : 21
Author      : Mohit Kumar
Description : Two-way communication between parent and child using two FIFOs
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
    int fd1, fd2;

    // Create two FIFOs
    mkfifo("fifo_pc", 0666);  // Parent -> Child
    mkfifo("fifo_cp", 0666);  // Child -> Parent

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // ---- Child process ----
        char msg[100];

        // Read from parent
        fd1 = open("fifo_pc", O_RDONLY);
        read(fd1, msg, sizeof(msg));
        printf("Child received: %s\n", msg);
        close(fd1);

        // Write to parent
        fd2 = open("fifo_cp", O_WRONLY);
        char reply[] = "Hello from Child!";
        write(fd2, reply, sizeof(reply));
        close(fd2);
    } else {
        // ---- Parent process ----
        char msg[] = "Hello from Parent!";

        // Write to child
        fd1 = open("fifo_pc", O_WRONLY);
        write(fd1, msg, sizeof(msg));
        close(fd1);

        // Read from child
        char reply[100];
        fd2 = open("fifo_cp", O_RDONLY);
        read(fd2, reply, sizeof(reply));
        printf("Parent received: %s\n", reply);
        close(fd2);

        wait(NULL); // wait for child
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 21.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 21.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Child received: Hello from Parent!
Parent received: Hello from Child!

======================================================================================
*/

