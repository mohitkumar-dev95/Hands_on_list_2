/*
======================================================================================
Name        : 08b
Author      : Mohit Kumar
Description : Program to catch interrupt signal (SIGINT) using signal()
======================================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>   // for exit()
#include <unistd.h>   // for sleep()

void handler(int s) {
    printf("Caught signal SIGINT: Interrupt from keyboard (Ctrl+C)\n");
    exit(0);
}

int main() {
    signal(SIGINT, handler);
    while (1) {
        printf("Running... Press Ctrl+C to stop\n");
        sleep(2);
    }
    return 0;
}

/*
======================================================================================
OUTPUT:mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 8b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 8b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Running... Press Ctrl+C to stop
Running... Press Ctrl+C to stop
Running... Press Ctrl+C to stop
Running... Press Ctrl+C to stop
Running... Press Ctrl+C to stop
Running... Press Ctrl+C to stop
Running... Press Ctrl+C to stop
^CCaught signal SIGINT: Interrupt from keyboard (Ctrl+C)


======================================================================================
*/

