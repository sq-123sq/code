// #include <winsock2.h>
// #include <WS2tcpip.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <Windows.h>

// #define BUFFER_SIZE 1024
// #define PORT 1234

// void* read_thread(void* arg) {
//     SOCKET client_socket = (SOCKET)(uintptr_t)arg;
//     char read_buffer[BUFFER_SIZE];
    
//     while(1) {
//         int ret = recv(client_socket, read_buffer, BUFFER_SIZE - 1, 0);
//         if (ret < 0) {
//             perror("recv");
//             break;
//         }
//         if (ret == 0) {
//             printf("服务端断开连接\n");
//             break;
//         }
//         read_buffer[ret] = '\0';
//         printf("收到服务端消息: %s", read_buffer);
//     }
    
//     closesocket(client_socket);
//     return NULL;
// }

// void* write_thread(void* arg) {
//     SOCKET client_socket = (SOCKET)(uintptr_t)arg;
//     char write_buffer[BUFFER_SIZE];
    
//     while(1) {
//         if (fgets(write_buffer, BUFFER_SIZE, stdin) == NULL) {
//             continue;
//         }
        
//         int total_len = strlen(write_buffer);
//         int sent_len = 0;
        
//         // 处理部分发送的情况
//         while (sent_len < total_len) {
//             int ret = send(client_socket, write_buffer + sent_len, total_len - sent_len, 0);
//             if (ret < 0) {
//                 perror("send");
//                 closesocket(client_socket);
//                 return NULL;
//             }
//             sent_len += ret;
//         }
//     }
// }

// int main() {
//     WSADATA wsa_data;
//     if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
//         perror("WSAStartup");
//         return -1;
//     }

//     struct sockaddr_in server;
//     memset(&server, 0, sizeof(server));

//     server.sin_family = AF_INET;
//     server.sin_port = htons(PORT);
//     // 将字符串IP转换为网络地址格式，这里连接本机
//     inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

//     SOCKET client_socket = socket(AF_INET, SOCK_STREAM, 0);
//     if (client_socket == INVALID_SOCKET) {
//         perror("socket");
//         WSACleanup();
//         return -1;
//     }

//     // 向服务端发起连接请求
//     int ret = connect(client_socket, (struct sockaddr*)&server, sizeof(server));
//     if (ret < 0) {
//         perror("connect");
//         closesocket(client_socket);
//         WSACleanup();
//         return -1;
//     }

//     printf("成功连接到服务端！\n");

//     // 创建读写线程实现全双工通信
//     HANDLE read_tid = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)read_thread, (LPVOID)client_socket, 0, NULL);
//     HANDLE write_tid = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)write_thread, (LPVOID)client_socket, 0, NULL);

//     if (read_tid) WaitForSingleObject(read_tid, INFINITE);
//     if (write_tid) WaitForSingleObject(write_tid, INFINITE);

//     if (read_tid) CloseHandle(read_tid);
//     if (write_tid) CloseHandle(write_tid);

//     closesocket(client_socket);
//     WSACleanup();

//     return 0;
// }
