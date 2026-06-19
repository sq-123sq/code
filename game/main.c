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

// // 全局游戏数据
// player* g_p = NULL;
// enemy* g_e = NULL;
// char* g_mine = NULL;
// char* g_show = NULL;

// // ==========================================
// // 2. 游戏初始化逻辑
// // ==========================================
// void init_game()
// {
//     // 如果是重新开局，先释放旧资源
//     if (g_mine) free(g_mine);
//     if (g_show) free(g_show);
//     if (g_p) destoryplayer(g_p);
//     if (g_e) destoryenemy(g_e);

//     // 1. 创建场地
//     g_mine = (char*)malloc(sizeof(char) * ROWS * COLS);
//     g_show = (char*)malloc(sizeof(char) * ROWS * COLS);
//     if(g_mine == NULL || g_show == NULL)
//     {
//         printf("malloc error\n");
//         exit(1);
//     }
//     initboard(g_mine, ROWS, COLS, '0');
//     initboard(g_show, ROWS, COLS, '*');
//     setbless(g_mine, ROW, COL, COLS);

//     // 2. 创建玩家，敌人
//     g_p = createplayer();
//     initplayer(g_p);
//     g_e = createenemy();
//     initenemy(g_e);

//     // 3. 设置玩家，敌人位置
//     spawn_player(g_p, g_mine, g_show, ROW, COL, COLS);
//     spawn_enemy(g_e, g_mine, g_show, ROW, COL, COLS);

//     // 4. 生成初始地图文件给网页看
//     writemap(g_show, ROW, COL, COLS,g_p,g_e);
//     writestatus(g_p, g_e, 0, 0,-1,-1);
    
//     printf("游戏初始化完成！\n");
// }
// 1. 定义常量 (推荐)
#define MAX_ROOMS 10  // 最大房间数
// --- 全局模式控制 ---
int g_mode = 0;        // 0: 人机对战(PVE), 1: 匹配对战(PVP)
int g_pvp_room_id = 0; // 当前匹配对战的房间号

// 2. 定义全局变量 (放在 main 函数外面)
player* g_p[MAX_ROOMS] = {NULL}; 
enemy* g_e[MAX_ROOMS] = {NULL};
char* g_mine[MAX_ROOMS] = {NULL};
char* g_show[MAX_ROOMS] = {NULL};

// 3. 辅助函数 (也放在 main 外面)
// 根据 room_id 查找对应的数组索引
int find_room_index(int room_id) {
    // 遍历所有房间，匹配 room_id
    for (int i = 0; i < MAX_ROOMS; i++) {
        // 检查该位置是否已初始化，且 room_id 匹配
        if (g_p[i] != NULL && g_p[i]->room_id == room_id) {
            return i;
        }
    }
    return -1; // 没找到
}

// 人机对战初始化 (固定使用索引0)
void init_game_pve() {
    int idx = 0; // PVE 默认使用索引 0
    
    // 1. 清理旧内存
    if (g_mine[idx]) free(g_mine[idx]);
    if (g_show[idx]) free(g_show[idx]);
    if (g_p[idx]) destoryplayer(g_p[idx]);
    if (g_e[idx]) destoryenemy(g_e[idx]);

    // 2. 分配新内存
    g_mine[idx] = (char*)malloc(sizeof(char) * ROWS * COLS);
    g_show[idx] = (char*)malloc(sizeof(char) * ROWS * COLS);
    
    // 3. 初始化地图数据
    initboard(g_mine[idx], ROWS, COLS, '0');
    initboard(g_show[idx], ROWS, COLS, '*');
    setbless(g_mine[idx], ROW, COL, COLS);

    // 4. 创建并初始化实体
    g_p[idx] = createplayer(); 
    initplayer(g_p[idx]); 
    // 修复：设置 room_id 为 1
    g_p[idx]->room_id = 1; 
    
    g_e[idx] = createenemy(); 
    initenemy(g_e[idx]); 
    // 修复：设置 room_id 为 1
    g_e[idx]->room_id = 1;

    // 5. 生成位置
    spawn_player(g_p[idx], g_mine[idx], g_show[idx], ROW, COL, COLS);
    spawn_enemy(g_e[idx], g_mine[idx], g_show[idx], ROW, COL, COLS);

    // 6. 写入文件/状态
    // 修复：写入 room_id 为 1
    writemap(g_show[idx], ROW, COL, COLS, g_p[idx], g_e[idx], 1);
    writestatus(g_p[idx], g_e[idx], 0, 0, -1, -1, 1);
    
    printf("人机对战房间初始化完成！\n");
}


// 匹配对战初始化 (动态分配索引)
void init_game_pvp(int room_id) {
    int idx = -1;
    for (int i = 1; i < MAX_ROOMS; i++) { // 从1开始找空位，0留给PVE
        if (g_p[i] == NULL) { idx = i; break; }
    }
    if (idx == -1) { printf("服务器已满！\n"); return; }

    // 【关键补充】：安全释放旧资源 (防止内存泄漏)
    if (g_mine[idx]) free(g_mine[idx]);
    if (g_show[idx]) free(g_show[idx]);
    if (g_p[idx]) destoryplayer(g_p[idx]);
    if (g_e[idx]) destoryenemy(g_e[idx]);

    // 资源分配逻辑
    g_mine[idx] = (char*)malloc(sizeof(char) * ROWS * COLS);
    g_show[idx] = (char*)malloc(sizeof(char) * ROWS * COLS);
    if(g_mine[idx] == NULL || g_show[idx] == NULL) {
        printf("malloc error\n");
        return;
    }
    
    initboard(g_mine[idx], ROWS, COLS, '0');
    initboard(g_show[idx], ROWS, COLS, '*');
    setbless(g_mine[idx], ROW, COL, COLS);

    g_p[idx] = createplayer(); initplayer(g_p[idx]); g_p[idx]->room_id = room_id;
    g_e[idx] = createenemy(); initenemy(g_e[idx]); g_e[idx]->room_id = room_id;

    spawn_player(g_p[idx], g_mine[idx], g_show[idx], ROW, COL, COLS);
    spawn_enemy(g_e[idx], g_mine[idx], g_show[idx], ROW, COL, COLS);

    writemap(g_show[idx], ROW, COL, COLS, g_p[idx], g_e[idx], room_id);
    writestatus(g_p[idx], g_e[idx], 0, 0, -1, -1, room_id);
    printf("匹配对战房间 %d 初始化完成！\n", room_id);
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
        
        int net_json_len;
        memcpy(&net_json_len, len_buf, 4);
        int json_len = ntohl(net_json_len);
        
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

        // 3. 解析 JSON 获取坐标和模式
        cJSON *req = cJSON_Parse(json_buf);
        int x = -1, y = -1;
        int req_mode = 0;     // 默认人机
        int req_room_id = 1;  // 默认房间1

        if (req) {
            cJSON *x_item = cJSON_GetObjectItem(req, "x");
            cJSON *y_item = cJSON_GetObjectItem(req, "y");
            cJSON *mode_item = cJSON_GetObjectItem(req, "mode");
            cJSON *room_item = cJSON_GetObjectItem(req, "room_id");
            if (cJSON_IsNumber(x_item)) x = x_item->valueint;
            if (cJSON_IsNumber(y_item)) y = y_item->valueint;
            if (cJSON_IsString(mode_item) && strcmp(mode_item->valuestring, "pvp") == 0) req_mode = 1;
            if (cJSON_IsNumber(room_item)) req_room_id = room_item->valueint;
            cJSON_Delete(req);
        }
        free(json_buf);

        // ==========================================
        // 4. 查找或初始化房间 (修复核心 Bug)
        // ==========================================
        int idx = -1;
        if (req_mode == 0) { // PVE 模式
            idx = 0;
            // 关键修复：只要 g_p[0] 是空的，说明没初始化，必须初始化！
            // 不能依赖 g_mode 是否变化，因为服务器重启后第一次请求必须初始化
            if (g_p[idx] == NULL) {
                printf("[C Server] PVE房间未初始化，开始初始化...\n");
                init_game_pve();
            }
        } else { // PVP 模式
            idx = find_room_index(req_room_id);
            if (idx == -1) {
                printf("[C Server] PVP房间 %d 未初始化，开始初始化...\n", req_room_id);
                init_game_pvp(req_room_id);
                idx = find_room_index(req_room_id);
            }
        }

        // ==========================================
        // 5. 执行游戏逻辑
        // ==========================================
        int game_status = 0;
        int winner = 0;

        if (idx != -1 && g_p[idx] != NULL && x != -1 && y != -1) {
            game_status = process_click(req_room_id, req_mode, x, y, g_p[idx], g_e[idx], g_mine[idx], g_show[idx], ROW, COL, COLS);
        }

        // ==========================================
        // 6. 写入文件存档 (可选，仅用于断线恢复或调试)
        // ==========================================
        if (idx != -1 && (game_status == 1 || (x != -1 && y != -1))) {
            writemap(g_show[idx], ROW, COL, COLS, g_p[idx], g_e[idx], req_room_id);
            writestatus(g_p[idx], g_e[idx], game_status, winner, -1, -1, req_room_id);
        }

        // ==========================================
        // 7. 从内存构造响应 JSON (绝对不要读文件！)
        // ==========================================
        cJSON *res = cJSON_CreateObject();
        cJSON_AddNumberToObject(res, "status", game_status);

        if (idx != -1 && g_p[idx] != NULL) {
            // --- 构造地图数组 ---
            cJSON *map_arr = cJSON_CreateArray();
            for (int r = 1; r <= ROW; r++) {
                cJSON *row_arr = cJSON_CreateArray();
                for (int c = 1; c <= COL; c++) {
                    int index = r * COLS + c;
                    char val[2] = {g_show[idx][index], '\0'}; // 从内存读取
                    cJSON_AddItemToArray(row_arr, cJSON_CreateString(val));
                }
                cJSON_AddItemToArray(map_arr, row_arr);
            }
            cJSON_AddItemToObject(res, "map", map_arr);

            // --- 构造状态对象 ---
            cJSON *status_data = cJSON_CreateObject();
            cJSON_AddNumberToObject(status_data, "game_over", game_status);
            cJSON_AddNumberToObject(status_data, "winner", winner);

            // 玩家对象 (从内存读取)
            cJSON *player_obj = cJSON_CreateObject();
            cJSON_AddNumberToObject(player_obj, "health", g_p[idx]->health);
            cJSON_AddNumberToObject(player_obj, "attack", g_p[idx]->attack);
            cJSON_AddNumberToObject(player_obj, "defense", g_p[idx]->defense);
            cJSON_AddNumberToObject(player_obj, "x", g_p[idx]->x);
            cJSON_AddNumberToObject(player_obj, "y", g_p[idx]->y);
            cJSON_AddItemToObject(status_data, "player", player_obj);

            // 敌人对象 (从内存读取)
            cJSON *enemy_obj = cJSON_CreateObject();
            cJSON_AddNumberToObject(enemy_obj, "health", g_e[idx]->health);
            cJSON_AddNumberToObject(enemy_obj, "attack", g_e[idx]->attack);
            cJSON_AddNumberToObject(enemy_obj, "defense", g_e[idx]->defense);
            cJSON_AddNumberToObject(enemy_obj, "x", g_e[idx]->x);
            cJSON_AddNumberToObject(enemy_obj, "y", g_e[idx]->y);
            cJSON_AddItemToObject(status_data, "enemy", enemy_obj);

            cJSON_AddItemToObject(res, "status_data", status_data);
            
            printf("[C Server] 返回数据: P_HP=%d, E_HP=%d\n", g_p[idx]->health, g_e[idx]->health);

        } else {
            // 房间初始化失败时的兜底返回
            cJSON_AddItemToObject(res, "map", cJSON_CreateArray());
            cJSON_AddItemToObject(res, "status_data", cJSON_Parse("{\"game_over\":0, \"winner\":0, \"player\":{\"health\":0}, \"enemy\":{\"health\":0}}"));
        }

        // 8. 序列化并发送响应
        char *resp_str = cJSON_PrintUnformatted(res);
        cJSON_Delete(res);
        if (resp_str) {
            int resp_len = strlen(resp_str);
            int net_len = htonl(resp_len); 
            send(client_socket, (char*)&net_len, 4, 0);
            send(client_socket, resp_str, resp_len, 0);
            free(resp_str);
        }

        // 9. 游戏结束重置
        if (game_status == 1) {
            if (req_mode == 0) {
                printf("人机对战结束，重置地图...\n");
                init_game_pve(); 
            } else {
                printf("匹配对战房间 %d 结束，释放资源...\n", req_room_id);
                if (idx != -1) {
                    if (g_mine[idx]) free(g_mine[idx]);
                    if (g_show[idx]) free(g_show[idx]);
                    if (g_p[idx]) destoryplayer(g_p[idx]);
                    if (g_e[idx]) destoryenemy(g_e[idx]);
                    g_mine[idx] = NULL; g_show[idx] = NULL;
                    g_p[idx] = NULL; g_e[idx] = NULL;
                }
            }
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
    init_game_pve();

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
    for (int i = 0; i < 10; i++) {
        if (g_mine[i]) free(g_mine[i]);
        if (g_show[i]) free(g_show[i]);
        if (g_p[i]) destoryplayer(g_p[i]);
        if (g_e[i]) destoryenemy(g_e[i]);
    }    
    
    #ifdef _WIN32
        WSACleanup();
    #endif
    
    return 0;
}
