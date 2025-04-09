#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, newsock;
    char buffer[1024];
    char filename[1024];
    struct sockaddr_in server, client;
    socklen_t len = sizeof(client);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8087);

    if (bind(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(1);
    }

    listen(sockfd, 5);
    printf("Waiting for connection...\n");

    newsock = accept(sockfd, (struct sockaddr*)&client, &len);
    if (newsock < 0) {
        perror("Accept failed");
        close(sockfd);
        exit(1);
    }

    int recv_len = recv(newsock, filename, sizeof(filename) - 1, 0);
    if (recv_len < 0) {
        perror("Receive failed");
        close(newsock);
        close(sockfd);
        exit(1);
    }

    filename[recv_len] = '\0';  // Null-terminate filename
    printf("Received filename: %s\n", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("File open error");
        send(newsock, "File Not Found", strlen("File Not Found"), 0);
    } else {
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            send(newsock, buffer, strlen(buffer), 0);
            usleep(10000);  // slight delay to avoid buffer mix
        }
        fclose(file);
    }

    close(newsock);
    close(sockfd);

    return 0;
}
