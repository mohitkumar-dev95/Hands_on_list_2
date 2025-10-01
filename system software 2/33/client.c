/*
======================================================================================
Name        : 33_socket_communication_client
Author      : Mohit Kumar
Description : Client program to connect to server and exchange messages.
======================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    // 1. Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Define server address (change IP if server is remote)
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // 3. Connect to server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // 4. Send message
    char *hello = "Hello from client";
    send(sock, hello, strlen(hello), 0);
    printf("Message sent to server\n");

    // 5. Receive reply
    read(sock, buffer, 1024);
    printf("Server: %s\n", buffer);

    close(sock);
    return 0;
}

/*
======================================================================================
OUTPUT (Client):
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~$ cd Hands_on_list2
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ gcc client.c -o client
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./client
Message sent to server
Server: Hello from server
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 


======================================================================================
*/

