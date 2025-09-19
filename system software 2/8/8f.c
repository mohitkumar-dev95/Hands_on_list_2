/*
======================================================================================
Name        : 08f
Author      : Mohit Kumar
Description : Program to catch SIGVTALRM using setitimer() system call
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>      // for exit()
#include <unistd.h>      // for pause()
#include <sys/time.h>    // for setitimer()

void handler(int s) {
    printf("Caught signal SIGVTALRM: Virtual timer expired!\n");
    exit(0);
}

int main() {
    signal(SIGVTALRM, handler);

    struct itimerval t;
    t.it_value.tv_sec = 2;      // fire after 2 seconds of CPU time
    t.it_value.tv_usec = 0;
    t.it_interval.tv_sec = 0;   // no repeat
    t.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &t, NULL);

    printf("Virtual timer set for 2 seconds of CPU time...\n");

    // Busy loop to consume CPU time
    while (1);

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 8f.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 8f.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Virtual timer set for 2 seconds of CPU time...
Caught signal SIGVTALRM: Virtual timer expired!


======================================================================================
*/

