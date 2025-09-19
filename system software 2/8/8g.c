/*
======================================================================================
Name        : 08g
Author      : Mohit Kumar
Description : Program to catch SIGPROF using setitimer system call
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>

void handler(int sig) {
    printf("Caught signal SIGPROF: Profiling Timer Expired\n");
    exit(0);
}

int main() {
    struct itimerval timer;
    signal(SIGPROF, handler);
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);

    while (1) { }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 8g.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 8g.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Caught signal SIGPROF: Profiling Timer Expired


======================================================================================
*/

