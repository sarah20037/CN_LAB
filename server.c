#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

void main()
{
    int sockfd,newsock;
    struct sockaddr_in server,client;
    socklen_t len = sizeof(client);
    char buffer[1024];
    
    sockfd=(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=INADDR_ANY;
    server.sin_port=htons(8080);
    
    bind(sockfd,struct(sockaddr)&server,sizeof(server));
    
    listen(sockfd.5);
    printf("Waiting for message...\n");
    
    newsock=accept(sockfd,struct(sockaddr)&client,sizeof(client));
    read(newsock,buffer,sizeof(buffer));
    printf("%s",buffer);
    send(newsock,"Hello from server",17,0);
    
    close(newsock);
    close(sockfd);
    
}