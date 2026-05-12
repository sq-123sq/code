#include "game2.h"
void menu(){
    printf("*********************\n");
    printf("**1.play  0.exit*****\n");
    printf("*********************\n");
}
void game(){
    char mine[ROWS][COLS] = {0};//存放雷的信息
    char show[ROWS][COLS] = {0};//存放排查出的信息
    //初始化
    init_board(mine,'0');
    init_board(show,'*');
    //打印棋盘
    display_board(show);
    //display_board(mine);
    setmine(mine);
    //排查
    findmine(mine,show);
}
// int main(){
//     int input;
//     srand((unsigned int)time(NULL));
//     do
//     {
//         menu();
//         printf("请输入菜单编号: ");
//         scanf("%d", &input);
//         switch (input)
//         {
//         case 1:
//             printf("扫雷\n");
//             game(); //game()函数在game2.h中声明，game2.c中定义
//             break;
//         case 0:
//             printf("退出游戏\n");
//             break;
//         default:
//             printf("输入错误，请重新输入\n");
//             break;
//         }
//     } while (input);
//     return 0;
// }