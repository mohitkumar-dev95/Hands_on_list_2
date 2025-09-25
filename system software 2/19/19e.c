/*
======================================================================================
Name        : 19e
Author      : Mohit Kumar
Description : Program to create FIFO using mkfifo library function
======================================================================================
*/

#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("myfifo4", 0666) == -1) {
        perror("mkfifo failed");
        return 1;
    }
    printf("FIFO myfifo4 created using mkfifo library function\n");
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 19e.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 19e.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
FIFO myfifo4 created using mkfifo library function
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ls -l myfifo4
prw-rw-r-- 1 mohit-kumar mohit-kumar 0 Sep 21 19:41 myfifo4


======================================================================================
*/

