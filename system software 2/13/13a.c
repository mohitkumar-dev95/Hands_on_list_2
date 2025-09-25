/*
======================================================================================
Name        : 13a
Author      : Mohit Kumar
Description : Program tries to catch SIGSTOP signal.
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main() {
    printf("Program PID: %d\n", getpid());
    signal(SIGSTOP, handler);   // attempt to catch SIGSTOP (will not work)

    while (1) {
        printf("Waiting for SIGSTOP...\n");
        sleep(2);
    }
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 13a.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Program PID: 18172
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...
Waiting for SIGSTOP...

[2]+  Stopped                 ./a.out
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 

======================================================================================
*/

