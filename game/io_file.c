#include "game.h"
#include "io_file.h"

int readclick(int* x, int* y) 
{
    if (x == NULL || y == NULL) return 0;
    FILE* fp = fopen("click.txt", "r");
    if (fp == NULL) return 0; 
    if (fscanf(fp, "%d %d", x, y) != 2) 
    {
        fclose(fp);
        return 0; 
    }
    fclose(fp);
    return 1; 
}

// 修改后的 writemap：将玩家和敌人画入地图
void writemap(char* show, int row, int col, int actual_cols, player* p, enemy* e) {
    FILE* f = fopen("map.txt", "w");
    if (!f) return;

    fprintf(f, "[\n"); // 开始整个大数组
    for (int i = 1; i <= row; i++) {
        fprintf(f, "  ["); // 开始一行
        for (int j = 1; j <= col; j++) {
            int index = i * actual_cols + j;
            char val = show[index];

            // 【关键新增】：如果当前坐标是玩家的位置，强制覆写为 'P'
            if (p != NULL && p->x == i && p->y == j) {
                val = 'P';
            }
            // 【关键新增】：如果当前坐标是敌人的位置，强制覆写为 'E'
            if (e != NULL && e->x == i && e->y == j) {
                val = 'E';
            }

            fprintf(f, "\"%c\"", val);
            // 如果不是这一行的最后一个元素，加逗号
            if (j < col) {
                fprintf(f, ", ");
            }
        }
        fprintf(f, "]"); // 结束一行
        // 如果不是最后一行，加逗号换行
        if (i < row) {
            fprintf(f, ",\n");
        } else {
            fprintf(f, "\n");
        }
    }
    fprintf(f, "]"); // 结束整个大数组
    fclose(f);
}

// 写入游戏状态，补全坐标，修复末尾逗号
void writestatus(player* p, enemy* e, int game_over, int winner)
{
    FILE* fp = fopen("status.txt", "w");
    if (fp == NULL) return;

    fprintf(fp, "{\n");
    fprintf(fp, "  \"game_over\": %d,\n", game_over);
    fprintf(fp, "  \"winner\": %d,\n", winner);
    // 增加坐标 x, y (注意：如果你的结构体里坐标变量名不是 x 和 y，请自行修改 p->x 和 p->y)
    fprintf(fp, "  \"player\": {\"health\": %d, \"attack\": %d, \"defense\": %d, \"x\": %d, \"y\": %d},\n", p->health, p->attack, p->defense, p->x, p->y);
    fprintf(fp, "  \"enemy\": {\"health\": %d, \"attack\": %d, \"x\": %d, \"y\": %d}\n", e->health, e->attack, e->x, e->y);
    fprintf(fp, "}\n");

    fclose(fp);
}
