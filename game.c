#include "game.h"
void init_board(char board[ROW][COL]){
    int i,j;
    for(i=0;i<ROW;i++){
        for(j=0;j<COL;j++){
            board[i][j]=' ';
        }
    }
}
void print_board(char board[ROW][COL]){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf(" %c ",board[i][j]);
            if(j<COL-1){
                printf("|");
            }
        }
        printf("\n");
        if(i<ROW-1){
            for(int j=0;j<COL;j++){
                printf("---");
                if(j<COL-1){
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}
void player_move(char board[ROW][COL]){
    int x,y;
    printf("请输入要下棋的坐标：");
    scanf("%d %d",&x,&y);
    if(x>=1 && x<=ROW && y>=1 && y<=COL){
        if(board[x-1][y-1]==' '){
            board[x-1][y-1]='X';
        }else{
            printf("该位置已经有棋子了，请重新输入\n");
            player_move(board);
        }
    }else{
        printf("输入的坐标不合法，请重新输入\n");
        player_move(board);
    }
}
void computer_move(char board[ROW][COL]){
    int x,y;
    printf("电脑正在下棋...\n");
    do{
        x=rand()%ROW;
        y=rand()%COL;
    }while(board[x][y]!=' ');
    board[x][y]='O';
}
void is_win(char board[ROW][COL],char player){
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            if(board[i][j]==player){
                if(i==0 && j==0 && board[i+1][j+1]==player && board[i+2][j+2]==player){
                    return;
                }
                if(i==0 && j==COL-1 && board[i+1][j-1]==player && board[i+2][j-2]==player){
                    return;
                }
                if(i==0 && board[i+1][j]==player && board[i+2][j]==player){
                    return;
                }
    }
}
}