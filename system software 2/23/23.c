/*
======================================================================================
Name        : 23
Author      : Mohit Kumar
Description : Print maximum files a process can open and size of a pipe
======================================================================================
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>

int main() {
    struct rlimit l;

    // Maximum number of files
    getrlimit(RLIMIT_NOFILE, &l);
    printf("Maximum number of files a process can open: Soft=%ld Hard=%ld\n", 
           (long)l.rlim_cur, (long)l.rlim_max);

    // Size of a pipe
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }
    int pipe_size = fcntl(fd[0], F_GETPIPE_SZ);
    printf("Size of pipe (circular buffer): %d bytes\n", pipe_size);

    close(fd[0]);
    close(fd[1]);
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 23.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 23.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Maximum number of files a process can open: Soft=1024 Hard=1048576
Size of pipe (circular buffer): 65536 bytes


======================================================================================
*/

