#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<time.h>



int main(){

    char *ip ="127.0.0.1";
    int port=5566;

    int server_sock,client_sock;
    struct sockaddr_in server_addr;
    char buffer[1024];
    socklen_t addr_size;
    int n;


    server_sock=socket(AF_INET,SOCK_DGRAM,0);

    memset(&server_addr,'\0',sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_port =htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    n=bind(server_sock,(struct sockaddr*)&server_addr,sizeof(server_addr));

    

    recvfrom(server_sock,buffer,1024,0);
    sendto(server_sock,buffer,1024,0)


    return 0;
}