/*
======================================================================================
Name        : 06
Author      : Mohit Kumar
Description : Simple program to create three threads using pthreads
======================================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* mythread(void* arg) {
    int n = *(int*)arg;
    printf("Hello from thread %d\n", n);
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    int a = 1, b = 2, c = 3;
    pthread_create(&t1, NULL, mythread, &a);
    pthread_create(&t2, NULL, mythread, &b);
    pthread_create(&t3, NULL, mythread, &c);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}

/*
======================================================================================
OUTPUT:

======================================================================================
*/

