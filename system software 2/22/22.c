/*
======================================================================================
Name        : 22
Author      : Mohit Kumar
Description : Wait for data on FIFO with 10 second timeout using select()
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    char *fifo = "fifo22";
    int fd;

    mkfifo(fifo, 0666);

    fd = open(fifo, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    fd_set readfds;
    struct timeval timeout;

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;  // 10 seconds
    timeout.tv_usec = 0;

    int ret = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (ret == -1) {
        perror("select");
    } else if (ret == 0) {
        printf("Timeout: No data written into FIFO in 10 seconds\n");
    } else {
        char buffer[100];
        read(fd, buffer, sizeof(buffer));
        printf("Data received from FIFO: %s\n", buffer);
    }

    close(fd);
    return 0;
}

/*
======================================================================================
OUTPUT:

from terminal 1:

mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list2
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 22.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Timeout: No data written into FIFO in 10 seconds
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Data received from FIFO: Hello from terminal 2

mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Data received from FIFO: Hello from terminal 2

mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$


 from terminal 2:

 mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ echo "Hello from terminal 2" > fifo22
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ echo "Hello from terminal 2" > fifo22
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ echo "Hello from terminal 2" > fifo22



======================================================================================
*/

