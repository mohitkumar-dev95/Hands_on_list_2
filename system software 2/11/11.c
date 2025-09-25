/*
======================================================================================
Name        : 11
Author      : Mohit Kumar
Description : Program to ignore a SIGINT signal, then reset it to default using sigaction
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    struct sigaction sa;

    // Step 1: Ignore SIGINT
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT is ignored for 10 seconds... Press Ctrl+C (it won't terminate)\n");
    sleep(10);

    // Step 2: Reset SIGINT to default
    sa.sa_handler = SIG_DFL;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("SIGINT reset to default. Now Ctrl+C will terminate.\n");

    while (1) {
        printf("Running... Press Ctrl+C to exit.\n");
        sleep(3);
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 11.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 11.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
SIGINT is ignored for 10 seconds... Press Ctrl+C (it won't terminate)
^C
^C
^C
^CSIGINT reset to default. Now Ctrl+C will terminate.
Running... Press Ctrl+C to exit.
^C
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$


======================================================================================
*/

