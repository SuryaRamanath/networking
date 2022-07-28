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

    int sock;
    struct sockaddr_in addr;
    char buffer[1024];
    int n;
    socklen_t addr_size;


    sock=socket(AF_INET,SOCK_STREAM,0);

    memset(&addr,'\0',sizeof(addr));
    addr.sin_family=AF_INET;
    addr.sin_port=htons(port);
    addr.sin_addr.s_addr =inet_addr(ip);

    n=bind(sock,(struct sockaddr*)&addr,sizeof(addr));

    

    while(1){
        addr_size=sizeof(addr);
        connect(sock,(struct sockaddr*)&addr,sizeof(addr));
         bzero(buffer,1024);
        strcpy(buffer,"hello client");
        send(sock,buffer,1024,0);
        bzero(buffer,1024);
        recv(sock,buffer,1024,0);
        printf("%s",buffer);
       

        close(sock);
    }


    return 0;
}