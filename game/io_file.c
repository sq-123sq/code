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





void writemap(char* board, int row, int col, int actual_cols)
{
    if (board == NULL || row <= 0 || col <= 0 || actual_cols <= 0) return;

    FILE* fp = fopen("map.txt", "w"); 
    if (fp == NULL) return;

    // 输出JSON数组格式，例如：[["*","*","1"],["*"," ","0"]]
    fprintf(fp, "[\n");
    for (int i = 1; i <= row; i++)
    {
        fprintf(fp, "  ["); // 每行开始
        for (int j = 1; j <= col; j++)
        {
            int index = i * actual_cols + j;
            char ch = board[index];
            
            // JSON中字符串需要加双引号
            fprintf(fp, "\"%c\"", ch);
            
            // 如果不是本行最后一个元素，加逗号
            if (j < col) fprintf(fp, ", ");
        }
        // 如果不是最后一行，加逗号
        fprintf(fp, "]%s\n", (i < row) ? "," : "");
    }
    fprintf(fp, "]\n");
    fclose(fp);
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


