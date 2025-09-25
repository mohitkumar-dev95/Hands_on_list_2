/*
======================================================================================
Name        : 10b_sigint
Author      : Mohit Kumar
Description : Program to catch SIGINT using sigaction system call
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught SIGINT: Interrupt Signal (Ctrl+C)\n");
}

int main() {
    struct sigaction sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGINT, &sa, NULL);

    printf("Running program... Press Ctrl+C to trigger SIGINT.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 10b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 10b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Running program... Press Ctrl+C to trigger SIGINT.
^CCaught SIGINT: Interrupt Signal (Ctrl+C)
^CCaught SIGINT: Interrupt Signal (Ctrl+C)

======================================================================================
*/

