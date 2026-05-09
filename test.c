#include "game.h"
void menu(){
    printf("*********************\n");
    printf("**1.play  0.exit*****\n");
    printf("*********************\n");
}
void game(){
    //游戏函数
    char board[ROW][COL] = {0};
    //初始化棋盘
    init_board(board);
    //打印棋盘
    print_board(board);
    //游戏开始
    while (1)
    {
        //玩家下棋
        player_move(board);
        print_board(board);
        //判断玩家是否胜利
        if (is_win(board) == 'X')
        {
            printf("玩家胜利\n");
            break;
        }
        //电脑下棋
        computer_move(board);
        print_board(board);
        //判断电脑是否胜利
        if (is_win(board) == 'O')
        {
            printf("电脑胜利\n");
            break;
        }
    }
}
int main(){
    srand((unsigned int)time(NULL));
    int input;
    do
    {
       menu();
       printf("请输入你的选择: ");
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
           printf("选择错误，请重新选择\n");
           break;
       }
    } while (input);
    
    return 0;
}