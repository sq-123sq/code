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
    if (!show) return; // 防御性校验

    FILE* f = fopen("map.txt", "w");
    if (!f) return;

    fprintf(f, "[\n");
    for (int i = 1; i <= row; i++) {
        fprintf(f, "  [");
        for (int j = 1; j <= col; j++) {
            int index = i * actual_cols + j;
            char val = show[index];

            // 优先级处理：如果坐标重叠，优先显示玩家 P
            if (e != NULL && e->x == i && e->y == j) {
                val = 'E';
            }
            if (p != NULL && p->x == i && p->y == j) {
                val = 'P'; // 后赋值覆盖，保证玩家可见
            }

            fprintf(f, "\"%c\"%s", val, (j < col) ? ", " : "");
        }
        fprintf(f, "]%s", (i < row) ? ",\n" : "\n");
    }
    fprintf(f, "]\n");
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
