/*
======================================================================================
Name        : 05
Author      : Mohit Kumar
Description : Program to print various system limitations using sysconf()
======================================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Maximum length of arguments to exec: %ld\n", sysconf(_SC_ARG_MAX));
    printf("Maximum number of simultaneous processes per user ID: %ld\n", sysconf(_SC_CHILD_MAX));
    printf("Number of clock ticks per second: %ld\n", sysconf(_SC_CLK_TCK));
    printf("Maximum number of open files: %ld\n", sysconf(_SC_OPEN_MAX));
    printf("Page size (bytes): %ld\n", sysconf(_SC_PAGESIZE));
    printf("Total number of pages in physical memory: %ld\n", sysconf(_SC_PHYS_PAGES));
    printf("Currently available pages in physical memory: %ld\n", sysconf(_SC_AVPHYS_PAGES));

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 5.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 5.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Maximum length of arguments to exec: 2097152
Maximum number of simultaneous processes per user ID: 62037
Number of clock ticks per second: 100
Maximum number of open files: 1024
Page size (bytes): 4096
Total number of pages in physical memory: 4015469
Currently available pages in physical memory: 2859045
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 


======================================================================================
*/

