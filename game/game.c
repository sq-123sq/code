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
    for(int i=0;i<cols;i++)
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
void set_countbless(int count,int rows,int cols,char c,char* board)
{
    while (count)
    {
        int x = rand() % rows + 1;
        int y = rand() % cols + 1;
        int index = x * (cols + 2) + y; // 核心修复：适配实际数组大小
        
        if (board[index] == '0') // 修复逻辑：如果当前位置为'0'，则布置
        {
            board[index] = c;
            count--;
        }
    }
}
void setbless(char* board, int rows, int cols)
{
    if (board == NULL || rows <= 0 || cols <= 0)
    {
        return;
    }

    // 提前校验宏常量的合法性，防止无效的放置逻辑
    if (blesscount_health <= 0 || blesscount_attack <= 0 || blesscount_defense <= 0)
    {
        return;
    }

    // 修复多字节字符问题，使用单字符标识
    set_countbless(blesscount_health, rows, cols, 'H', board);
    set_countbless(blesscount_attack, rows, cols, 'A', board);
    set_countbless(blesscount_defense, rows, cols, 'D', board);
}

// 判断是否为祝福格子的辅助函数
static int is_bless(char c) {
    return (c == 'H' || c == 'A' || c == 'D');
}

int get_bless_count(char* board, int x, int y, int cols)
{
    if (board == NULL || x <= 0 || y <= 0 || cols <= 0)
    {
        printf("参数不合法\n");
        return -1;
    }

    int count = 0;
    // 遍历周围8个方向的偏移量
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        // 边界安全检查，防止数组越界
        if (nx >= 1 && nx <= ROW && ny >= 1 && ny <= COL)
        {
            if (is_bless(board[nx * cols + ny]))
            {
                count++;
            }
        }
    }

    return count;
}

void findbless(player* p, enemy* e, char* mine, char* show, int rows, int cols)
{
    if (p == NULL || e == NULL || mine == NULL || show == NULL || rows <= 0 || cols <= 0)
    {
        printf("参数不合法\n");
        return;
    }

    int x = 0;
    int y = 0;
    int battle_round=0; // 战斗轮数
    int found_bless_count = 0;
    const int bless_value = 100;
    const int decay_value = 10; // 每次战斗攻防衰减量
    int has_health_bless = 0;   // 标记是否获得过生命祝福

    while (found_bless_count < blesscount)
    {
        printf("请玩家输入要祈福的坐标: ");
        
        if (scanf("%d %d", &x, &y) != 2)
        {
            printf("输入格式错误，请输入两个整数！\n");
            while (getchar() != '\n');
            continue;
        }

        if (x >= 1 && x <= rows && y >= 1 && y <= cols)
        {
            int index = x * COLS + y; // 修复索引，使用实际数组宽度COLS

            if (show[index] != '*')
            {
                printf("该坐标已经被祈福过，请不要重复选择\n");
            }
            else
            {
                char bless_type = mine[index];
                int is_bless = 0;
                
                if (bless_type == 'H')
                {
                    printf("恭喜你，获得生命祝福！攻防不再降低！\n");
                    p->health += bless_value;
                    has_health_bless = 1; // 激活保护状态
                    is_bless = 1;
                }
                else if (bless_type == 'A')
                {
                    printf("恭喜你，获得攻击祝福！\n");
                    p->attack += bless_value;
                    is_bless = 1;
                }
                else if (bless_type == 'D')
                {
                    printf("恭喜你，获得防御祝福！\n");
                    p->defense += bless_value;
                    is_bless = 1;
                }

                if (is_bless)
                {
                    battle_round++;
                    // 触发战斗逻辑
                    printf("--- 第%d轮战斗开始 ---\n", battle_round);
                    
                    // 未获得生命祝福时，攻防随战斗次数衰减
                    if (!has_health_bless)
                    {
                        p->attack -= decay_value;
                        p->defense -= decay_value;
                        
                        // 防止属性下溢为负数
                        if (p->attack < 0) p->attack = 0;
                        if (p->defense < 0) p->defense = 0;
                        
                        printf("由于未获得生命祝福，玩家攻防降低！当前攻击:%d, 当前防御:%d\n", p->attack, p->defense);
                    }

                    // 结算战斗伤害
                    p->health -= e->attack;
                    e->health -= p->attack;
                    printf("战斗结束！玩家当前生命值为:%d，敌人当前生命值为:%d\n", p->health, e->health);
                    
                    if (p->health <= 0)
                    {
                        printf("玩家已死亡，游戏结束\n");
                        return;
                    }
                    if (e->health <= 0)
                    {
                        printf("敌人已死亡，玩家挑战成功\n");
                        return;
                    }
                    
                    show[index] = bless_type;
                    found_bless_count++;
                }
                else
                {
                    int count = get_bless_count(mine, x, y, cols);
                    printf("当前坐标的周围有%d个祝福\n", count);
                    show[index] = count + '0';
                }
                
                displayboard(show, rows, cols);
            }
        }
        else
        {
            printf("坐标不合法，请重新输入\n");
        }
    }

    printf("恭喜你，找到所有祝福\n");
    displayboard(mine, rows, cols);
}

