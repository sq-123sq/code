#pragma once // 防止头文件重复包含
#include "game.h"
// 读取网页传来的点击坐标
int readclick(int* x, int* y);

// 增加 room_id 参数
void writemap(char* show, int row, int col, int actual_cols, player* p, enemy* e, int room_id);
void writestatus(player* p, enemy* e, int game_over, int winner, int e_click_x, int e_click_y, int room_id);
