/*
======================================================================================
Name        : 31b_counting_semaphore
Author      : Mohit Kumar
Description : Create a counting semaphore and initialize its values
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

    key = ftok(".", 'C');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    semid = semget(key, 5, 0666 | IPC_CREAT);
    if (semid == -1) {
        perror("semget");
        return 1;
    }

    unsigned short arr[5] = {2, 1, 3, 0, 4};
    sem_attr.array = arr;
    if (semctl(semid, 0, SETALL, sem_attr) == -1) {
        perror("semctl");
        return 1;
    }

    printf("Counting semaphore created and initialized to: 2 1 3 0 4\n");
    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 31b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 31b.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Counting semaphore created and initialized to: 2 1 3 0 4
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 

======================================================================================
*/

