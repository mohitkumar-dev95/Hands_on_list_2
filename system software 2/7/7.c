/*
======================================================================================
Name        : 07
Author      : Mohit Kumar
Description : Simple program to create threads and print their thread IDs
======================================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* mythread(void* arg) {
    printf("Thread started. ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, mythread, NULL);
    pthread_create(&t2, NULL, mythread, NULL);
    pthread_create(&t3, NULL, mythread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 7.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 7.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Thread started. ID: 138606066792128
Thread started. ID: 138606058399424
Thread started. ID: 138606050006720
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$

======================================================================================
*/

