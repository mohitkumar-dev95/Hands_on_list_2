/*
======================================================================================
Name        : 30
Author      : Mohit Kumar
Description : Create a shared memory, write data, attach read-only, detach and remove
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main() {
    key_t key;
    int shmid;
    char *shm_ptr;

    key = ftok(".", 'B');  // generate unique key
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);  // create shared memory
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    shm_ptr = (char*) shmat(shmid, NULL, 0);  // attach with read-write
    if (shm_ptr == (char*) -1) {
        perror("shmat");
        return 1;
    }

    strcpy(shm_ptr, "Hello shared memory!");  // write some data
    printf("Data written to shared memory: %s\n", shm_ptr);

    // Attach read-only
    char *shm_ptr_ro = (char*) shmat(shmid, NULL, SHM_RDONLY);
    if (shm_ptr_ro == (char*) -1) {
        perror("shmat - read-only");
        return 1;
    }

    printf("Read-only attach reads: %s\n", shm_ptr_ro);
    // shm_ptr_ro[0] = 'X';  // Uncommenting this line will cause a segmentation fault

    shmdt(shm_ptr);       // detach write attach
    shmdt(shm_ptr_ro);    // detach read-only attach

    if (shmctl(shmid, IPC_RMID, NULL) == -1) {  // remove shared memory
        perror("shmctl - IPC_RMID");
        return 1;
    }

    printf("Shared memory removed successfully!\n");

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 30.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 30.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Data written to shared memory: Hello shared memory!
Read-only attach reads: Hello shared memory!
Shared memory removed successfully!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 30.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Data written to shared memory: Hello shared memory!
Read-only attach reads: Hello shared memory!
Shared memory removed successfully!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 30.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Data written to shared memory: Hello shared memory!
Read-only attach reads: Hello shared memory!
Segmentation fault (core dumped)


======================================================================================
*/

