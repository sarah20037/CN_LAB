#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int sockfd;
    struct sockaddr_in server;
    char buffer[1024];
    char filename[1024];

    sockfd=socket(AF_INET,SOCK_STREAM,0);
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    server.sin_port=htons(8087);

    connect(sockfd,(struct sockaddr*)&server,sizeof(server));

    printf("Enter a filename");
    scanf("%s",filename);

    send(sockfd,filename,strlen(filename),0);
    
    while(recv(sockfd,buffer,sizeof(buffer),0)>0)
    {
        printf("%s",buffer);
        memset(buffer,0,sizeof(buffer));

    }
    close(sockfd);
    return 0;
}