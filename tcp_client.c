#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd;
    struct sockaddr_in server;
    char buffer[1024];

    // 1. Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error Creating Socket");
        exit(1);
    }

    // 2. Set server info
    server.sin_family = AF_INET;
    server.sin_port = htons(8051);

    // 3. Convert IP address
    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        perror("Invalid Address");
        exit(1);
    }

    // 4. Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection Failed");
        exit(1);
    }

    // 5. Send message
    send(sockfd, "Hello from client", 17, 0);

    // 6. Receive response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    printf("%s\n", buffer);

    // 7. Close socket
    close(sockfd);

    return 0;
}
