/*
======================================================================================
Name        : 27
Author      : Mohit Kumar
Description : Receive messages from a message queue (blocking or non-blocking)
======================================================================================
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

int main() {
    key_t key;
    int msgid;
    struct msg_buffer message;
    int choice;

    key = ftok(".", 'A');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    msgid = msgget(key, 0666);
    if (msgid == -1) {
        perror("msgget");
        return 1;
    }

    printf("Choose receive mode: 1-Blocking, 2-Non-blocking: ");
    scanf("%d", &choice);
    getchar(); // consume newline after scanf

    if (choice == 1) {
        if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0) == -1) {
            perror("msgrcv");
            return 1;
        }
        printf("Received message (blocking): %s", message.msg_text);
    } else if (choice == 2) {
        if (msgrcv(msgid, &message, sizeof(message.msg_text), 1, IPC_NOWAIT) == -1) {
            if (errno == ENOMSG) {
                printf("No message in the queue right now.\n");
            } else {
                perror("msgrcv");
                return 1;
            }
        } else {
            printf("Received message (non-blocking): %s", message.msg_text);
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

/*
======================================================================================
OUTPUT:
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim 27.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ cc 27.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Choose receive mode: 1-Blocking, 2-Non-blocking: 1
Received message (blocking): mohit is my favourite person
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./a.out
Choose receive mode: 1-Blocking, 2-Non-blocking: 2
Received message (non-blocking): fav

======================================================================================
*/

