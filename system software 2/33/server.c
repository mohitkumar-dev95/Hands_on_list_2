/*
======================================================================================
Name        : 33
Author      : Mohit Kumar
Description : Program to communicate between two machines using TCP sockets.
              One acts as a server, the other as a client.
======================================================================================
*/

/// ============================= SERVER CODE =============================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    // 1. Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. Bind socket to IP and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;  // any local IP
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // 3. Listen for connections
    listen(server_fd, 3);
    printf("Server listening on port %d...\n", PORT);

    // 4. Accept client connection
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    // 5. Read message from client
    read(new_socket, buffer, 1024);
    printf("Client: %s\n", buffer);

    // 6. Send reply
    send(new_socket, hello, strlen(hello), 0);
    printf("Message sent to client\n");

    close(new_socket);
    close(server_fd);
    return 0;
}

/*
======================================================================================
OUTPUT (Server):
======================================================================================
ohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim server.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ vim client.c
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ^C
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ gcc server.c -o server
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ ./server
Server listening on port 8080...
Client: Hello from client
Message sent to client
mohit-kumar@mohit-kumar-IdeaPad-Slim-3-15IAH8:~/Hands_on_list2$ 

======================================================================================
*/


