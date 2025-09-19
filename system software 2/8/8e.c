/*
======================================================================================
Name        : 08e_sigalrm_setitimer
Author      : Mohit Kumar
Description : Program to catch SIGALRM using setitimer() system call
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>      // for exit()
#include <unistd.h>      // for pause()
#include <sys/time.h>    // for setitimer()

void handler(int s) {
    printf("Caught signal SIGALRM: Timer expired!\n");
    exit(0);
}

int main() {
    signal(SIGALRM, handler);

    struct itimerval t;
    t.it_value.tv_sec = 3;      // first alarm after 3 seconds
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0;   // no repeat
    t.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &t, NULL);

    printf("Timer set for 3 seconds...\n");
    pause();   // wait until signal arrives
    return 0;
}
/*
======================================================================================
OUTPUT:

======================================================================================
*/
