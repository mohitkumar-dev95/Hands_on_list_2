/*
======================================================================================
Name        : 20.c
Author      : Mohit Kumar
Description : One-way communication using FIFO without using variable
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd;

    // Create FIFO named "fifo20"
    if (mkfifo("fifo20", 0666) == -1) {
        perror("mkfifo");
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // ---- Child process: Reader ----
        fd = open("fifo20", O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        char buffer[100];
        read(fd, buffer, sizeof(buffer));
        printf("Child (Reader): Message received from FIFO: %s\n", buffer);

        close(fd);
    } else {
        // ---- Parent process: Writer ----
        fd = open("fifo20", O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(1);
        }

        char message[] = "Hello from parent via FIFO!";
        write(fd, message, sizeof(message));
        printf("Parent (Writer): Message sent to FIFO\n");

        close(fd);

        wait(NULL); // wait for child to finish
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list2
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 20.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 20.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Parent (Writer): Message sent to FIFO
Child (Reader): Message received from FIFO: Hello from parent via FIFO!

======================================================================================
*/

