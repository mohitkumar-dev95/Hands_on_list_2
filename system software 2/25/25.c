/*
======================================================================================
Name        : 25
Author      : Mohit Kumar
Description : Print message queue details using msqid_ds and ipc_perm
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;

    key = ftok(".", 'A');  // same path and proj_id as queue creation
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666);  // get the existing queue
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        return 1;
    }

    printf("Access permissions: %o\n", buf.msg_perm.mode);
    printf("UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);
    printf("Last message sent: %s", ctime(&buf.msg_stime));
    printf("Last message received: %s", ctime(&buf.msg_rtime));
    printf("Last change in queue: %s", ctime(&buf.msg_ctime));
    printf("Maximum bytes allowed: %ld\n", buf.msg_qbytes);
    printf("Current number of bytes in queue: %ld\n", buf.__msg_cbytes);
    printf("Number of messages in queue: %ld\n", buf.msg_qnum);
    printf("PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 25.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 25.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Access permissions: 666
UID: 1000, GID: 1000
Last message sent: Thu Jan  1 05:30:00 1970
Last message received: Thu Jan  1 05:30:00 1970
Last change in queue: Tue Sep 23 14:13:12 2025
Maximum bytes allowed: 16384
Current number of bytes in queue: 0
Number of messages in queue: 0
PID of last msgsnd: 0
PID of last msgrcv: 0



======================================================================================
*/

