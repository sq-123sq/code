#include "game.h"
#include "io_file.h"
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
    initboard(mine,ROWS,COLS,'0');
    initboard(show,ROWS,COLS,'*');
    setbless(mine,ROW,COL,COLS);
    //displayboard(mine,ROWS,COLS);
    displayboard(show,ROW,COL,COLS);
    //2.创建玩家，敌人
    player* p=createplayer();
    initplayer(p);
    enemy* e=createenemy();
    initenemy(e);
    //3.显示玩家，敌人
    displayplayer(p);
    displayenemy(e);
    //3.设置玩家，敌人位置
    spawn_player(p,mine,show,ROW,COL,COLS);
    spawn_enemy(e,mine,show,ROW,COL,COLS);
    // 【关键】：在进入游戏逻辑前，生成一次初始地图文件给网页看
    writemap(show, ROW, COL, COLS);
    writestatus(p, e, 0, 0);
    //4.游戏逻辑
    findbless(p,e,mine,show,ROW,COL,COLS);
    //5释放资源
    free(mine);
    free(show);
    destoryplayer(p);
    destoryenemy(e);
}
// int main()
// {
//     int input = 0;
//     srand(time(NULL));
//     do
//     {
//         menu();
//         printf("请选择：");
//         scanf("%d", &input);
//         switch (input)
//         {
//         case 1:
//             game();
//             break;
//         case 0:
//             printf("退出游戏\n");
//             break;
//         default:
//             printf("输入错误，请重新输入\n");
//             break;
//         }
//     }while(input);
//     return 0;
// }


int main()
{
    // 初始化随机数种子
    srand((unsigned int)time(NULL));
    
    // 直接启动游戏，去掉菜单和scanf阻塞
    printf("游戏正在启动...\n"); 
    
    game();
    
    return 0;
}