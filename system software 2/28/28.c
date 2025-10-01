/*
======================================================================================
Name        : 28
Author      : Mohit Kumar
Description : Change permissions of an existing message queue
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgid;
    struct msqid_ds buf;
    int new_perm;

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

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {  // get current queue info
        perror("msgctl - IPC_STAT");
        return 1;
    }

    printf("Current permissions: %o\n", buf.msg_perm.mode);

    printf("Enter new permission in octal (e.g., 644): ");
    scanf("%o", &new_perm);

    buf.msg_perm.mode = new_perm;

    if (msgctl(msgid, IPC_SET, &buf) == -1) {  // set new permissions
        perror("msgctl - IPC_SET");
        return 1;
    }

    printf("Permissions updated successfully!\n");

    if (msgctl(msgid, IPC_STAT, &buf) == -1) {
        perror("msgctl - IPC_STAT");
        return 1;
    }

    printf("Updated permissions: %o\n", buf.msg_perm.mode);

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 28.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 28.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Current permissions: 666
Enter new permission in octal (e.g., 644): 644
Permissions updated successfully!
Updated permissions: 644


======================================================================================
*/

