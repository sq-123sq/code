#pragma once // 防止头文件重复包含

// 读取网页传来的点击坐标
int readclick(int* x, int* y);

// 将棋盘内容写入文件供网页读取
void writemap(char* board, int row, int col, int actual_cols,player* p, enemy* e);

void writestatus(player* p, enemy* e, int game_over, int winner);
