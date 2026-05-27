#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#define handle_error(cmd,result)\
if(result<0)\
{\
    perror(cmd);\
    return -1;\
}
int main() {
    struct sockaddr_in server,client;
    memset(&server,0,sizeof(server));
    memset(&client,0,sizeof(client));

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(1234);

    SOCKET s = socket(AF_INET,SOCK_STREAM,0);
    handle_error("socket",s);

    int ret= bind(s,(struct sockaddr*)&server,sizeof(server));
    handle_error("bind",ret);

    ret = listen(s,5);
    handle_error("listen",ret);

    int client_len = sizeof(client);
    SOCKET client_socket = accept(s,(struct sockaddr*)&client,&client_len);
    handle_error("accept",client_socket);

    printf("连接到客户端:%s 端口号为:%d 文件描述符为:%d\n",
    inet_ntoa(client.sin_addr),
    ntohs(client.sin_port),
    client_socket,client_socket);

    pthread_t read_tid,write_tid;
    pthread_create(&read_tid,NULL,read_thread,NULL);
    pthread_create(&write_tid,NULL,write_thread,NULL);

    pthread_join(read_tid,NULL);
    pthread_join(write_tid,NULL);
     
}
