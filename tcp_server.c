#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, newsock;
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);
    char buffer[1024];

    // 1. Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Server address setup
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8051);

    // 3. Bind socket
    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error Binding");
        exit(EXIT_FAILURE);
    }

    // 4. Listen
    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connection...\n");

    // Optional delay
    sleep(15);

    // 5. Accept connection
    newsock = accept(sockfd, (struct sockaddr *)&client, &len);
    if (newsock < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // 6. Receive message
    memset(buffer, 0, sizeof(buffer));
    if (recv(newsock, buffer, sizeof(buffer) - 1, 0) < 0) {
        perror("Receive failed");
        close(newsock);
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    printf("Client says: %s\n", buffer);

    // 7. Send reply
    if (send(newsock, "Hello from server", 17, 0) < 0) {
        perror("Send failed");
    }

    // 8. Close sockets
    close(newsock);
    close(sockfd);

    return 0;
}
