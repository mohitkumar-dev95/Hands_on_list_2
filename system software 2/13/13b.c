/*
======================================================================================
Name        : 13b
Author      : Mohit Kumar
Description : Program sends SIGSTOP signal to target process.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID>\n", argv[0]);
        exit(1);
    }

    pid_t pid = atoi(argv[1]);
    if (kill(pid, SIGSTOP) == 0) {
        printf("Sent SIGSTOP to process %d\n", pid);
    } else {
        perror("kill failed");
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 13b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out 18172
Sent SIGSTOP to process 18172


======================================================================================
*/

