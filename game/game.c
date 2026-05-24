#include "game.h"
player* createplayer()
{
    player* p=(player*)malloc(sizeof(player));
    if(p==NULL)
    {
        perror("createplayer");
        return NULL;
    }
    memset(p,0,sizeof(player));
    return p;
}
enemy* createenemy()
{
    enemy* e=(enemy*)malloc(sizeof(enemy));
    if(e==NULL)
    {
        perror("createenemy");
        return NULL;
    }
    memset(e,0,sizeof(enemy));
    return e;
}
void initplayer(player* p)
{
    if(p==NULL)
    {
        perror("initplayer");
        return;
    }
    strcpy(p->name,playername);
    p->attack=playerattack;
    p->defense=playerdefense;
    p->health=playerhealth;
}
void initenemy(enemy* e)
{
    if(e==NULL)
    {
        perror("initenemy");
        return;
    }
    strcpy(e->name,enemyname);
    e->attack=enemyattack;
    e->defense=enemydefense;
    e->health=enemyhealth;
}
void displayenemy(enemy* e)
{
    if(e==NULL)
    {
        perror("displayenemy");
        return;
    }
    printf("敌人属性:名称:%s 攻击:%d 防御:%d 生命:%d\n",e->name,e->attack,e->defense,e->health);
}
void displayplayer(player* p)
{
    if(p==NULL)
    {
        perror("displayplayer");
        return;
    }
    printf("玩家属性:名称:%s 攻击:%d 防御:%d 生命:%d\n",p->name,p->attack,p->defense,p->health);
}
void destoryplayer(player* p)
{
    if(p==NULL)
    {
        perror("destoryplayer");
        return;
    }
    free(p);
    p=NULL;
}
void destoryenemy(enemy* e)
{
    if(e==NULL)
    {
        perror("destoryenemy");
        return;
    }
    free(e);
    e=NULL;
}

void initboard(char* board,int rows,int cols,char c)
{
    if(board==NULL||rows<=0||cols<=0)
    {
        printf("参数不合法\n");
        return;
    }
    memset(board,c,rows*cols*sizeof(char));
}
void displayboard(char* board,int rows,int cols)
{
    if(board==NULL||rows<=0||cols<=0)
    {
        printf("参数不合法\n");
        return;
    }
    printf("-----------游戏开始-----------\n");
    printf(" ");
    for(int i=1;i<cols;i++)
    {
        printf("%d ",i);
    }
    printf("\n");
    for(int i=1;i<rows;i++)
    {
        printf("%d ",i);
        for(int j=1;j<cols;j++)
        {
            printf("%c ",board[i*cols+j]);
        }
        printf("\n");
    }
}
void setbless(char* board,int rows,int cols)
{
    int count=blesscount;
    if (board == NULL || rows <= 0 || cols <= 0 ||count <= 0)
    {
        return;
    }

    while (count)
    {
        int x = rand() % rows + 1;
        int y = rand() % cols + 1;
        int index = x * (cols + 2) + y; // 核心修复：适配实际数组大小
        
        if (board[index] == '0') // 修复逻辑：如果当前位置为'0'，则布置
        {
            board[index] = 'B';
            count--;
        }
    }
}