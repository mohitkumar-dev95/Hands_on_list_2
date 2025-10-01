/*
======================================================================================
Name        : 32
Author      : Mohit Kumar
Description : Protect critical section using semaphore (ticket number creation)
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    key_t key;
    int semid;
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } sem_attr;

    key = ftok(".", 'T');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    sem_attr.val = 1;  // binary semaphore
    semctl(semid, 0, SETVAL, sem_attr);

    int ticket = 0;

    for (int i = 0; i < 5; i++) {
        struct sembuf p = {0, -1, 0};  // wait
        struct sembuf v = {0, 1, 0};   // signal

        semop(semid, &p, 1);   // enter critical section
        ticket++;
        printf("Process %d issued ticket number: %d\n", getpid(), ticket);
        sleep(1);               // simulate work in critical section
        semop(semid, &v, 1);   // leave critical section
    }

    semctl(semid, 0, IPC_RMID); // remove semaphore
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list2
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 32.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 32.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Process 3734 issued ticket number: 1
Process 3734 issued ticket number: 2
Process 3734 issued ticket number: 3
Process 3734 issued ticket number: 4
Process 3734 issued ticket number: 5
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 


======================================================================================
*/

