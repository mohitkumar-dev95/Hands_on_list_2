/*
======================================================================================
Name        : 08c
Author      : Mohit Kumar
Description : Program to catch floating point exception (SIGFPE)
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>   // for exit()

void handler(int s) {
    printf("Caught signal SIGFPE: Floating Point Exception (e.g., divide by zero)\n");
    exit(1);
}

int main() {
    signal(SIGFPE, handler);
    int a = 5;
    int b = 0;
    int c = a / b;   // generates SIGFPE
    printf("Result: %d\n", c);
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 8.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 8.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Caught signal SIGFPE: Floating Point Exception (e.g., divide by zero)
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 


======================================================================================
*/

