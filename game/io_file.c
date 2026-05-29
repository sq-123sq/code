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

    // 【删除清空文件的代码！】不要再以 "w" 模式打开它了！
    return 1; 
}





void writemap(char* show, int row, int col, int actual_cols) {
    FILE* f = fopen("map.txt", "w");
    if (!f) return;

    fprintf(f, "[");
    int first = 1;
    // 注意：从 1 遍历到 row/col，跳过边界哨兵
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            int index = i * actual_cols + j;
            if (!first) fprintf(f, ", ");
            fprintf(f, "\"%c\"", show[index]);
            first = 0;
        }
    }
    fprintf(f, "]");
    fclose(f);
}


// 写入游戏状态（血量、攻防、胜负）供网页读取
void writestatus(player* p, enemy* e, int game_over, int winner)
{
    // game_over: 0-游戏中, 1-游戏结束
    // winner: 0-无, 1-玩家胜, 2-敌人胜(玩家死)
    
    FILE* fp = fopen("status.txt", "w");
    if (fp == NULL) return;

    // 输出JSON格式
    fprintf(fp, "{\n");
    fprintf(fp, "  \"game_over\": %d,\n", game_over);
    fprintf(fp, "  \"winner\": %d,\n", winner);
    fprintf(fp, "  \"player\": {\"health\": %d, \"attack\": %d, \"defense\": %d},\n", p->health, p->attack, p->defense);
    fprintf(fp, "  \"enemy\": {\"health\": %d, \"attack\": %d}\n", e->health, e->attack);
    fprintf(fp, "}\n");

    fclose(fp);
}


