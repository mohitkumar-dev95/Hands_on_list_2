/*
======================================================================================
Name        : 19d
Author      : Mohit Kumar
Description : Program to create FIFO using mknod system call
======================================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (mknod("myfifo3", S_IFIFO | 0666, 0) == -1) {
        perror("mknod failed");
        return 1;
    }
    printf("FIFO myfifo3 created using mknod system call\n");
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 19d.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 19d.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
FIFO myfifo3 created using mknod system call
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ls -l myfifo3
prw-rw-r-- 1 mohit-kumar mohit-kumar 0 Sep 21 19:39 myfifo3
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$


======================================================================================
*/

