/*
======================================================================================
Name        : 02_timer_virtual
Author      : Mohit Kumar
Description : Program to set an interval timer using ITIMER_VIRTUAL with 10 sec and 10 microsec
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

void handler(int a) {
    printf("ITIMER_VIRTUAL alarm triggered\n");
}

int main() {
    struct itimerval t;
    signal(SIGVTALRM, handler);
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    setitimer(ITIMER_VIRTUAL, &t, NULL);
    while (1);
    return 0;
}

/*
======================================================================================
output:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list2
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 1b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 1b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
ITIMER_VIRTUAL alarm triggered
ITIMER_VIRTUAL alarm triggered
ITIMER_VIRTUAL alarm triggered
ITIMER_VIRTUAL alarm triggered



======================================================================================
*/

