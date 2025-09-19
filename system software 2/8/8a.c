/*
======================================================================================
Name        : 08a_sigsegv
Author      : Mohit Kumar
Description : Program to catch segmentation fault (SIGSEGV)
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>   

void handler(int s) {
    printf("Caught signal SIGSEGV: Segmentation Fault\n");
    exit(1);
}

int main() {
    signal(SIGSEGV, handler);
    int *p = NULL;
    *p = 10;   
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 8a.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Caught signal SIGSEGV: Segmentation Fault
 


======================================================================================
*/

