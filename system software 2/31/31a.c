/*
======================================================================================
Name        : 31a_binary_semaphore
Author      : Mohit Kumar
Description : Create a binary semaphore and initialize its value to 1
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main() {
    key_t key;
    int semid;
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } sem_attr;

    key = ftok(".", 'B');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    sem_attr.val = 1;
    if (semctl(semid, 0, SETVAL, sem_attr) == -1) {
        perror("semctl");
        return 1;
    }

    printf("Binary semaphore created and initialized to 1\n");
    return 0;
}

/*
======================================================================================
OUTPUT:
======================================================================================
*/

