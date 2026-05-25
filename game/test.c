#include "game.h"
void menu()
{
    printf("***************************\n");
    printf("***** 1. 开始游戏 *******\n");
    printf("***** 0. 退出游戏 *******\n");
    printf("***************************\n");
}
void game()
{
    //游戏函数 1.创建场地
    char* mine=(char*)malloc(sizeof(char)*ROWS*COLS);
    char* show=(char*)malloc(sizeof(char)*ROWS*COLS);
    if(mine==NULL||show==NULL)
    {
        printf("malloc error\n");
        free(mine);
        free(show);
        return;
    }
    memset(mine,0,sizeof(char)*ROWS*COLS);
    memset(show,0,sizeof(char)*ROWS*COLS);
    initboard(mine,ROWS,COLS,'0');
    initboard(show,ROWS,COLS,'*');
    setbless(mine,ROWS,COLS);
    //displayboard(mine,ROWS,COLS);
    displayboard(show,ROWS,COLS);
    //2.创建玩家，敌人
    player* p=createplayer();
    initplayer(p);
    enemy* e=createenemy();
    initenemy(e);
    displayplayer(p);
    displayenemy(e);
    //3.游戏逻辑
    findbless(p,e,mine,show,ROWS,COLS);

    
    free(mine);
    free(show);
    destoryplayer(p);
    destoryenemy(e);
}
int main()
{
    int input = 0;
    srand(time(NULL));
    do
    {
        menu();
        printf("请选择：");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("输入错误，请重新输入\n");
            break;
        }
    }while(input);
    return 0;
}