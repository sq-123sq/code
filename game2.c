#include "game2.h"
void init_board(char board[ROWS][COLS],char c){
    int i,j;
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            board[i][j]=c;
        }
    }
}
void display_board(char board[ROWS][COLS]){
    int i,j;
    printf("---------扫雷·-------------\n");
    for(i=0;i<=COL;i++){
        printf("%d ",i);//打印列号
    }
    printf("\n");
    for(i=1;i<=ROW;i++){
        printf("%d ",i);//打印行号
        for(j=1;j<=COL;j++){
            printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}
void setmine(char board[ROWS][COLS]){
    int count=MINES;
    int x,y;
    while(count){
        x=rand()%ROW+1;
        y=rand()%COL+1;
        if(board[x][y]=='0'){
            board[x][y]='1';
            count--;
        }
    }
}
int get_mine_count(char mine[ROWS][COLS],int x,int y){
    return  (mine[x-1][y-1]+
    mine[x-1][y]+
    mine[x-1][y+1]+
    mine[x][y-1]+
    mine[x][y+1]+
    mine[x+1][y-1]+
    mine[x+1][y]+
    mine[x+1][y+1])-8*'0';
}
void open_area(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *win_count){
    // 1. 边界检查
    if(x < 1 || x > ROW || y < 1 || y > COL) return;
    
    // 2. 如果已经显示过，直接返回
    if(show[x][y] != '*') return;

    // 3. 计算周围雷数
    int count = get_mine_count(mine, x, y);
    
    
    (*win_count)++; // 增加已排查格子计数
    if(count>0){
        show[x][y] = count + '0'; // 显示数字
    } else{// 5. 如果周围没有雷 (count == 0)，则递归打开周围8个格子
        show[x][y] = ' ';
        open_area(mine, show, x-1, y-1, win_count);
        open_area(mine, show, x-1, y,   win_count);
        open_area(mine, show, x-1, y+1, win_count);
        open_area(mine, show, x,   y-1, win_count);
        open_area(mine, show, x,   y+1, win_count);
        open_area(mine, show, x+1, y-1, win_count);
        open_area(mine, show, x+1, y,   win_count);
        open_area(mine, show, x+1, y+1, win_count);
    }
}
void findmine(char mine[ROWS][COLS],char show[ROWS][COLS]){
    int x,y;
    int win=0;
    while(win<ROW*COL-MINES){
       printf("请输入行和列：");
       scanf("%d%d",&x,&y);
       if(x>=1&&x<=ROW&&y>=1&&y<=COL)
       {   if(show[x][y]!='*'){
            printf("请勿重复输入！\n");
       }else{
        if(mine[x][y]=='1'){
            printf("很遗憾，你踩到雷了！\n");
            display_board(mine);
            break;
        }
        else{
            open_area(mine, show, x, y, &win);
            display_board(show);
       }
    }
}else{
        printf("输入的行或列超出范围！\n");
    }
}
if(win==ROW*COL-MINES){
    printf("恭喜，你赢了！\n");
    display_board(mine);
}
}