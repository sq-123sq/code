// #include "game.h"
// // 假设 game.h 中定义了 ROW 和 COL
// // 如果未定义，请在此处添加测试用宏
// // #define ROW 15
// // #define COL 15

// void init_board(char board[ROW][COL]){
//     for(int i=0; i<ROW; i++){
//         for(int j=0; j<COL; j++){
//             board[i][j] = ' ';
//         }
//     }
// }

// void print_board(char board[ROW][COL]){
//     // 打印列号
//     printf("   ");
//     for(int j=0; j<COL; j++) {
//         printf("%2d ", j+1);
//     }
//     printf("\n");

//     for(int i=0; i<ROW; i++){
//         // 打印行号
//         printf("%2d ", i+1);
//         for(int j=0; j<COL; j++){
//             printf(" %c ", board[i][j]);
//             if(j < COL-1){
//                 printf("|");
//             }
//         }
//         printf("\n");
        
//         // 打印分隔线
//         if(i < ROW-1){
//             printf("   ");
//             for(int j=0; j<COL; j++){
//                 printf("---");
//                 if(j < COL-1){
//                     printf("|");
//                 }
//             }
//             printf("\n");
//         }
//     }
// }

// void player_move(char board[ROW][COL]){
//     int x, y;
//     while(1) {
//         printf("请输入要下棋的坐标 (行 列): ");
//         if (scanf("%d %d", &x, &y) != 2) {
//             // 清除输入缓冲区中的非法字符
//             while(getchar() != '\n');
//             printf("输入格式错误，请重新输入。\n");
//             continue;
//         }
        
//         // 转换为数组索引 (0-based)
//         int r = x - 1;
//         int c = y - 1;

//         if(r >= 0 && r < ROW && c >= 0 && c < COL){
//             if(board[r][c] == ' '){
//                 board[r][c] = 'X';
//                 break;
//             } else {
//                 printf("该位置已经有棋子了，请重新输入\n");
//             }
//         } else {
//             printf("输入的坐标不合法，请重新输入\n");
//         }
//     }
// }

// /**
//  * 检查在 (r, c) 位置落下 player 棋子后，是否形成连珠
//  * @param win_len 需要连成的珠子数量，五子棋为5，井字棋为3
//  */
// static int check_direction(char board[ROW][COL], int r, int c, char player, int dr, int dc, int win_len) {
//     int count = 1; // 包含当前落子点
    
//     // 向正方向检查
//     for (int k = 1; k < win_len; k++) {
//         int nr = r + k * dr;
//         int nc = c + k * dc;
//         if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || board[nr][nc] != player) {
//             break;
//         }
//         count++;
//     }
    
//     // 向反方向检查
//     for (int k = 1; k < win_len; k++) {
//         int nr = r - k * dr;
//         int nc = c - k * dc;
//         if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || board[nr][nc] != player) {
//             break;
//         }
//         count++;
//     }
    
//     return count >= win_len;
// }

// /**
//  * 评估某个空位对于指定玩家的分数
//  * 用于 AI 决策
//  */
// static int evaluate_pos(char board[ROW][COL], int r, int c, char player, int win_len) {
//     int score = 0;
//     int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}}; // 横、竖、斜、反斜

//     // 临时落子
//     board[r][c] = player;

//     for (int d = 0; d < 4; d++) {
//         int dr = directions[d][0];
//         int dc = directions[d][1];
        
//         int count = 1;
//         int blocked = 0; // 被阻挡的端点数

//         // 正向
//         int k = 1;
//         while (k < win_len) {
//             int nr = r + k * dr;
//             int nc = c + k * dc;
//             if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) {
//                 blocked++;
//                 break;
//             }
//             if (board[nr][nc] == player) {
//                 count++;
//             } else if (board[nr][nc] != ' ') {
//                 blocked++;
//                 break;
//             } else {
//                 break; // 遇到空位
//             }
//             k++;
//         }

//         // 反向
//         k = 1;
//         while (k < win_len) {
//             int nr = r - k * dr;
//             int nc = c - k * dc;
//             if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL) {
//                 blocked++;
//                 break;
//             }
//             if (board[nr][nc] == player) {
//                 count++;
//             } else if (board[nr][nc] != ' ') {
//                 blocked++;
//                 break;
//             } else {
//                 break; // 遇到空位
//             }
//             k++;
//         }

//         // 评分逻辑
//         if (count >= win_len) {
//             score += 100000; // 成五/成三，必胜
//         } else if (count == win_len - 1) {
//             if (blocked == 0) score += 10000; // 活四/活二
//             else if (blocked == 1) score += 1000; // 冲四/眠二
//         } else if (count == win_len - 2) {
//             if (blocked == 0) score += 1000; // 活三
//             else if (blocked == 1) score += 100; // 眠三
//         } else {
//             score += count; // 其他情况，连子越多分越高
//         }
//     }

//     // 恢复棋盘
//     board[r][c] = ' ';
//     return score;
// }

// void computer_move(char board[ROW][COL]){
//     printf("电脑正在思考...\n");
    
//     // 确定连珠长度，五子棋通常为5，如果是3x3井字棋则为3
//     int win_len = 5;
//     if (ROW < 5 || COL < 5) {
//         win_len = 3;
//     }

//     int best_score = -1;
//     int best_r = -1;
//     int best_c = -1;

//     // 遍历所有空位，寻找最佳落子点
//     for (int i = 0; i < ROW; i++) {
//         for (int j = 0; j < COL; j++) {
//             if (board[i][j] == ' ') {
//                 // 进攻分数：电脑下在这里对自己有多好
//                 int attack_score = evaluate_pos(board, i, j, 'O', win_len);
//                 // 防守分数：玩家下在这里对玩家有多好（即电脑需要阻止的程度）
//                 int defense_score = evaluate_pos(board, i, j, 'X', win_len);
                
//                 // 总分 = 进攻 + 防守。通常防守权重可以略高，防止被偷鸡
//                 int total_score = attack_score + defense_score;
                
//                 // 稍微偏好中心区域
//                 if (i > 0 && i < ROW-1 && j > 0 && j < COL-1) {
//                     total_score += 1;
//                 }

//                 if (total_score > best_score) {
//                     best_score = total_score;
//                     best_r = i;
//                     best_c = j;
//                 }
//             }
//         }
//     }

//     // 如果棋盘已满（理论上不会进入此分支，因为调用前会判断）
//     if (best_r == -1) {
//         return;
//     }

//     board[best_r][best_c] = 'O';
//     printf("电脑下在: %d %d\n", best_r + 1, best_c + 1);
// }

// char is_win(char board[ROW][COL]){
//     int win_len = 5;
//     if (ROW < 5 || COL < 5) {
//         win_len = 3;
//     }

//     int is_full = 1;
//     int directions[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};

//     for (int r = 0; r < ROW; r++) {
//         for (int c = 0; c < COL; c++) {
//             if (board[r][c] == ' ') {
//                 is_full = 0;
//                 continue;
//             }

//             char current = board[r][c];
//             // 只需要检查四个方向
//             for (int d = 0; d < 4; d++) {
//                 if (check_direction(board, r, c, current, directions[d][0], directions[d][1], win_len)) {
//                     return current;
//                 }
//             }
//         }
//     }

//     if (is_full) {
//         return 'Q'; // 平局
//     }

//     return 'C'; // 继续
// }