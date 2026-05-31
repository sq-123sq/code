// #include "game.h"
// #include "io_file.h"
// void menu()
// {
//     printf("***************************\n");
//     printf("***** 1. 开始游戏 *******\n");
//     printf("***** 0. 退出游戏 *******\n");
//     printf("***************************\n");
// }
// void game()
// {
//     //游戏函数 1.创建场地
//     char* mine=(char*)malloc(sizeof(char)*ROWS*COLS);
//     char* show=(char*)malloc(sizeof(char)*ROWS*COLS);
//     if(mine==NULL||show==NULL)
//     {
//         printf("malloc error\n");
//         free(mine);
//         free(show);
//         return;
//     }
//     initboard(mine,ROWS,COLS,'0');
//     initboard(show,ROWS,COLS,'*');
//     setbless(mine,ROW,COL,COLS);
//     //displayboard(mine,ROWS,COLS);
//     displayboard(show,ROW,COL,COLS);
//     //2.创建玩家，敌人
//     player* p=createplayer();
//     initplayer(p);
//     enemy* e=createenemy();
//     initenemy(e);
//     //3.显示玩家，敌人
//     displayplayer(p);
//     displayenemy(e);
//     //3.设置玩家，敌人位置
//     spawn_player(p,mine,show,ROW,COL,COLS);
//     spawn_enemy(e,mine,show,ROW,COL,COLS);
//     // 【关键】：在进入游戏逻辑前，生成一次初始地图文件给网页看
//     writemap(show, ROW, COL, COLS);
//     writestatus(p, e, 0, 0);
//     //4.游戏逻辑
//     findbless(p,e,mine,show,ROW,COL,COLS);
//     //5释放资源
//     free(mine);
//     free(show);
//     destoryplayer(p);
//     destoryenemy(e);
// }
// // int main()
// // {
// //     int input = 0;
// //     srand(time(NULL));
// //     do
// //     {
// //         menu();
// //         printf("请选择：");
// //         scanf("%d", &input);
// //         switch (input)
// //         {
// //         case 1:
// //             game();
// //             break;
// //         case 0:
// //             printf("退出游戏\n");
// //             break;
// //         default:
// //             printf("输入错误，请重新输入\n");
// //             break;
// //         }
// //     }while(input);
// //     return 0;
// // }


// int main()
// {
//     // 初始化随机数种子
//     srand((unsigned int)time(NULL));
    
//     // 直接启动游戏，去掉菜单和scanf阻塞
//     printf("游戏正在启动...\n"); 
    
//     game();
    
//     return 0;
// }


// ==========================================
// 1. 跨平台头文件与宏定义适配
// ==========================================
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>

    #include "game.h"
    #include "io_file.h"
    #include <string.h>
    #include <time.h>
    #include "cJSON.h"  // 引入 cJSON 库

    typedef int socklen_t;
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <unistd.h>
    #define SOCKET int
    #define INVALID_SOCKET -1
    #define SOCKET_ERROR -1
    #define closesocket close
#endif

#define PORT 1234

// 全局游戏数据
player* g_p = NULL;
enemy* g_e = NULL;
char* g_mine = NULL;
char* g_show = NULL;

// ==========================================
// 2. 游戏初始化逻辑
// ==========================================
void init_game()
{
    // 如果是重新开局，先释放旧资源
    if (g_mine) free(g_mine);
    if (g_show) free(g_show);
    if (g_p) destoryplayer(g_p);
    if (g_e) destoryenemy(g_e);

    // 1. 创建场地
    g_mine = (char*)malloc(sizeof(char) * ROWS * COLS);
    g_show = (char*)malloc(sizeof(char) * ROWS * COLS);
    if(g_mine == NULL || g_show == NULL)
    {
        printf("malloc error\n");
        exit(1);
    }
    initboard(g_mine, ROWS, COLS, '0');
    initboard(g_show, ROWS, COLS, '*');
    setbless(g_mine, ROW, COL, COLS);

    // 2. 创建玩家，敌人
    g_p = createplayer();
    initplayer(g_p);
    g_e = createenemy();
    initenemy(g_e);

    // 3. 设置玩家，敌人位置
    spawn_player(g_p, g_mine, g_show, ROW, COL, COLS);
    spawn_enemy(g_e, g_mine, g_show, ROW, COL, COLS);

    // 4. 生成初始地图文件给网页看
    writemap(g_show, ROW, COL, COLS,g_p,g_e);
    writestatus(g_p, g_e, 0, 0);
    
    printf("游戏初始化完成！\n");
}

// ==========================================
// 3. 安全读取指定字节数（解决 TCP 半包问题）
// ==========================================
int read_exact(SOCKET sock, char* buffer, int len) {
    int total_read = 0;
    while (total_read < len) {
        int n = recv(sock, buffer + total_read, len - total_read, 0);
        if (n <= 0) return 0; // 连接断开或出错
        total_read += n;
    }
    return 1; // 成功读满
}

// ==========================================
// 4. 处理客户端请求的函数
// ==========================================
void handle_client_request(SOCKET client_socket) {
    char len_buf[4];
    
    while (1) {
        // 1. 先读取 4 字节长度
        if (!read_exact(client_socket, len_buf, 4)) break;
        
        // 安全转换网络字节序为主机字节序（避免未对齐访问和符号问题）
        int net_json_len;
        memcpy(&net_json_len, len_buf, 4);
        int json_len = ntohl(net_json_len);
        
        // 防御性编程：限制最大请求体大小
        if (json_len <= 0 || json_len > 65536) break; 

        // 2. 读取 JSON 数据
        char *json_buf = (char*)malloc(json_len + 1);
        if (!json_buf) break;
        
        if (!read_exact(client_socket, json_buf, json_len)) {
            free(json_buf);
            break;
        }
        json_buf[json_len] = '\0';
        
        printf("收到网页指令: %s\n", json_buf);

        // 3. 解析 JSON 获取坐标
        cJSON *req = cJSON_Parse(json_buf);
        int x = -1, y = -1;
        if (req) {
            cJSON *x_item = cJSON_GetObjectItem(req, "x");
            cJSON *y_item = cJSON_GetObjectItem(req, "y");
            if (cJSON_IsNumber(x_item) && cJSON_IsNumber(y_item)) {
                x = x_item->valueint;
                y = y_item->valueint;
            }
            cJSON_Delete(req);
        }
        free(json_buf);

        // 4. 执行游戏逻辑（仅在坐标有效时执行）
        int game_status = 0;
        if (x != -1 && y != -1) {
            game_status = process_click(x, y, g_p, g_e, g_mine, g_show, ROW, COL, COLS);
            writemap(g_show, ROW, COL, COLS,g_p,g_e);
            writestatus(g_p, g_e, game_status, 0); 
        }

        // 5. 构造响应 JSON
        cJSON *res = cJSON_CreateObject();
        cJSON_AddNumberToObject(res, "status", game_status);

        // 读取并添加 map 数据
        FILE *map_file = fopen("map.txt", "r");
        if (map_file) {
            fseek(map_file, 0, SEEK_END);
            long file_size = ftell(map_file);
            fseek(map_file, 0, SEEK_SET);
            if (file_size > 0) {
                char *map_buf = (char*)malloc(file_size + 1);
                if (map_buf) {
                    fread(map_buf, 1, file_size, map_file);
                    map_buf[file_size] = '\0';
                    cJSON *map_json = cJSON_Parse(map_buf);
                    cJSON_AddItemToObject(res, "map", map_json ? map_json : cJSON_CreateArray());
                    free(map_buf);
                } else {
                    cJSON_AddItemToObject(res, "map", cJSON_CreateArray());
                }
            } else {
                cJSON_AddItemToObject(res, "map", cJSON_CreateArray());
            }
            fclose(map_file);
        } else {
            cJSON_AddItemToObject(res, "map", cJSON_CreateArray());
        }

        // 读取并添加 status 数据
        FILE *status_file = fopen("status.txt", "r");
        if (status_file) {
            fseek(status_file, 0, SEEK_END);
            long file_size = ftell(status_file);
            fseek(status_file, 0, SEEK_SET);
            if (file_size > 0) {
                char *status_buf = (char*)malloc(file_size + 1);
                if (status_buf) {
                    fread(status_buf, 1, file_size, status_file);
                    status_buf[file_size] = '\0';
                    cJSON *status_json = cJSON_Parse(status_buf);
                    if (status_json) {
                        cJSON_AddItemToObject(res, "status_data", status_json);
                    } else {
                        cJSON_AddItemToObject(res, "status_data", cJSON_Parse("{\"game_over\":0, \"winner\":0, \"player\":{\"health\":0}, \"enemy\":{\"health\":0}}"));
                    }
                    free(status_buf);
                } else {
                    cJSON_AddItemToObject(res, "status_data", cJSON_Parse("{\"game_over\":0, \"winner\":0, \"player\":{\"health\":0}, \"enemy\":{\"health\":0}}"));
                }
            } else {
                cJSON_AddItemToObject(res, "status_data", cJSON_Parse("{\"game_over\":0, \"winner\":0, \"player\":{\"health\":0}, \"enemy\":{\"health\":0}}"));
            }
            fclose(status_file);
        } else {
            cJSON_AddItemToObject(res, "status_data", cJSON_Parse("{\"game_over\":0, \"winner\":0, \"player\":{\"health\":0}, \"enemy\":{\"health\":0}}"));
        }

        // 6. 序列化并发送响应
        char *resp_str = cJSON_PrintUnformatted(res);
        cJSON_Delete(res);
        
        if (resp_str) {
            int resp_len = strlen(resp_str);
            int net_len = htonl(resp_len); 
            send(client_socket, (char*)&net_len, 4, 0);
            send(client_socket, resp_str, resp_len, 0);
            free(resp_str);
        }

        // 7. 如果游戏结束，重置游戏供下一局使用
        if (game_status == 1) {
            printf("本局游戏结束，正在重置地图...\n");
            init_game(); 
            break; 
        }
    }
}


// ==========================================
// 5. main 函数：负责网络监听
// ==========================================
int main()
{
    // Windows 下初始化 Winsock
    #ifdef _WIN32
        WSADATA wsa_data;
        if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0) {
            perror("WSAStartup");
            return -1;
        }
    #endif

    srand((unsigned int)time(NULL));
    
    // 1. 初始化游戏数据
    init_game();

    // 2. 创建 Socket
    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) { perror("socket"); return -1; }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        perror("bind"); closesocket(server_fd); return -1;
    }

    if (listen(server_fd, 5) == SOCKET_ERROR) {
        perror("listen"); closesocket(server_fd); return -1;
    }

    printf("C Server 启动成功，等待网页/Python连接...\n");

    // 3. 主循环：死循环等待客户端连接
    while(1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        SOCKET client_socket = accept(server_fd, (struct sockaddr*)&client_addr, &client_len);
        
        if (client_socket == INVALID_SOCKET) continue;

        char ip_str[INET_ADDRSTRLEN];
        printf("Python网关已连接: %s\n", inet_ntop(AF_INET, &client_addr.sin_addr, ip_str, sizeof(ip_str)));

        // 4. 处理该客户端的请求
        handle_client_request(client_socket);
        
        closesocket(client_socket);
        printf("Python网关断开连接，等待重新连接...\n");
    }

    // 5. 释放资源 (死循环后很少执行，但保持好习惯)
    closesocket(server_fd);
    if(g_mine) free(g_mine);
    if(g_show) free(g_show);
    if(g_p) destoryplayer(g_p);
    if(g_e) destoryenemy(g_e);
    
    #ifdef _WIN32
        WSACleanup();
    #endif
    
    return 0;
}
