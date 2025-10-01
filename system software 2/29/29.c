/*
======================================================================================
Name        : 29
Author      : Mohit Kumar
Description : Remove an existing message queue
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;

    key = ftok(".", 'A');  // same path and project ID used to create queue
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666);  // get existing queue
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    if (msgctl(msgid, IPC_RMID, NULL) == -1) {  // remove the queue
        perror("msgctl - IPC_RMID");
        return 1;
    }

    printf("Message queue removed successfully!\n");

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 29.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 29.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Message queue removed successfully!
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 

======================================================================================
*/

