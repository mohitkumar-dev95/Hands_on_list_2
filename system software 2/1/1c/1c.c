/*
======================================================================================
Name        : 03_timer_prof
Author      : Mohit Kumar
Description : Program to set an interval timer using ITIMER_PROF with 10 sec and 10 microsec
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(int a) {
    printf("ITIMER_PROF alarm triggered\n");
}

int main() {
    struct itimerval t;
    signal(SIGPROF, handler);
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    setitimer(ITIMER_PROF, &t, NULL);
    while (1);
    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 1c.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 1c.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
ITIMER_PROF alarm triggered
ITIMER_PROF alarm triggered
ITIMER_PROF alarm triggered

======================================================================================
*/

