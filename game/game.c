#include "game.h"
#include "io_file.h"
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
    p->x=0;
    p->y=0;
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
    e->x=0;
    e->y=0;
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
void displayboard(char* board, int row, int col, int actual_cols)
{
    if (board == NULL || row <= 0 || col <= 0 || actual_cols <= 0)
    {
        printf("参数不合法\n");
        return;
    }

    // row, col: 逻辑游戏区域大小 (如 10)
    // actual_cols: 底层数组实际列宽 (如 12, 用于计算索引)

    printf("============= 游戏面板 =============\n");

    // 1. 打印列头 (对齐行号占用的2个字符宽度)
    printf("   "); // 3个空格对齐后续的行号 "x "
    for (int j = 1; j <= col; j++)
    {
        printf("%2d ", j); // %2d 保证两位数列头对齐
    }
    printf("\n");

    // 2. 打印棋盘内容
    for (int i = 1; i <= row; i++)
    {
        printf("%2d ", i); // %2d 保证两位数行号对齐
        for (int j = 1; j <= col; j++)
        {
            int index = i * actual_cols + j; // 核心修复：适配实际数组大小
            printf("%2c ", board[index]); // %2c 保证两位数字符对齐
        }
        printf("\n");
    }
}
void set_countbless(int count,int row,int col,int cols,char c,char* board)
{
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        int index = x * cols + y; // 核心修复：适配实际数组大小
        
        if (board[index] == '0') // 修复逻辑：如果当前位置为'0'，则布置
        {
            board[index] = c;
            count--;
        }
    }
}
void setbless(char* board, int row, int col,int cols)
{
    if (board == NULL || row <= 0||col<=0 || cols <= 0)
    {
        return;
    }

    // 提前校验宏常量的合法性，防止无效的放置逻辑
    if (blesscount_health <= 0 || blesscount_attack <= 0 || blesscount_defense <= 0)
    {
        return;
    }

    // 修复多字节字符问题，使用单字符标识
    set_countbless(blesscount_health, row, col,cols, 'H', board);
    set_countbless(blesscount_attack, row, col,cols, 'A', board);
    set_countbless(blesscount_defense, row, col,cols, 'D', board);
}
void spawn_player(player* p, char* mine, char* show, int row, int col, int actual_cols)
{
    if (p == NULL || mine == NULL || show == NULL || row <= 0 || col <= 0 || actual_cols <= 0)
    {
        printf("参数不合法\n");
        return;
    }

    // 定义魔法字符常量，增强可读性
    const char BLESS_ATTACK = 'A';
    const char BLESS_HEALTH = 'H';
    const char BLESS_DEFENSE = 'D';
    const char PLAYER_MARK = 'P';

    int x, y, index;
    int attempts = 0;
    const int max_attempts = row * col; // 防止死循环的最大尝试次数

    // 循环随机，直到找到合法的空位放置玩家
    do {
        // 假设逻辑游戏区域是从 1~rows, 1~cols（标准扫雷设计）
        x = rand() % row + 1;
        y = rand() % col + 1;
        index = x * actual_cols + y; // 使用传入的实际列宽计算索引，消除隐式+2
        attempts++;

        if (attempts > max_attempts) {
            printf("地图已满，无法放置玩家！\n");
            return;
        }
    } while (mine[index] == BLESS_ATTACK || mine[index] == BLESS_HEALTH || mine[index] == BLESS_DEFENSE);

    // 成功找到空位，在 show 数组中标记玩家位置
    show[index] = PLAYER_MARK;
    
    // 如果 player 结构体需要记录坐标，可在此更新：
    p->x = x;
    p->y = y;
}

void spawn_enemy(enemy* e, char* mine, char* show, int row, int col, int actual_cols)
{
    // row, col 对应宏 ROW, COL (逻辑大小 10)
    // actual_cols 对应宏 COLS (物理大小 12)
    if (e == NULL || mine == NULL || show == NULL || row <= 0 || col <= 0 || actual_cols <= 0)
    {
        printf("参数不合法\n");
        return;
    }

    const char BLESS_ATTACK  = 'A';
    const char BLESS_HEALTH  = 'H';
    const char BLESS_DEFENSE = 'D';
    const char PLAYER_MARK   = 'P';
    const char ENEMY_MARK    = 'E';
    const char EMPTY_SPACE   = '0'; 

    int x, y, index;
    int attempts = 0;
    const int max_attempts = row * col; 

    do {
        // 核心修复：坐标范围必须是 1 ~ row 和 1 ~ col，绝不能是 0！
        x = rand() % row + 1; 
        y = rand() % col + 1; 
        
        // 核心修复：使用实际物理列宽 actual_cols (即 COLS=12) 计算索引
        index = x * actual_cols + y; 
        
        attempts++;

        if (attempts > max_attempts) {
            printf("地图已满，无法放置敌人！\n");
            return;
        }
    } while (mine[index] != EMPTY_SPACE || show[index] == PLAYER_MARK);

    show[index] = ENEMY_MARK;
    e->x = x;
    e->y = y;
}


// 判断是否为祝福格子的辅助函数
static int is_bless(char c) {
    return (c == 'H' || c == 'A' || c == 'D');
}

int get_bless_count(char* board, int x, int y, int row, int col, int actual_cols)
{
    // row, col: 逻辑大小 (10)
    // actual_cols: 物理列宽 (12)
    if (board == NULL || x < 1 || x > row || y < 1 || y > col || actual_cols <= 0)
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
        
        // 边界安全检查：使用传入的逻辑大小 row 和 col，不再使用硬编码宏
        if (nx >= 1 && nx <= row && ny >= 1 && ny <= col)
        {
            // 核心修复：使用物理大小 actual_cols 计算一维数组索引
            int index = nx * actual_cols + ny;
            if (is_bless(board[index]))
            {
                count++;
            }
        }
    }

    return count;
}


// 递归展开函数
void expand_bless(char* mine, char* show, int x, int y, int row, int col, int actual_cols) 
{
    // 1. 边界检查：使用逻辑大小 row, col (10)
    // 确保递归不会进入边界哨兵区域（0行0列，11行11列）
    if (x < 1 || x > row || y < 1 || y > col) 
    {
        return;
    }

    // 2. 状态检查：使用物理大小 actual_cols (12) 计算索引
    // 防止死循环递归，同时兼容 'P' 和 'E' 被排查过的情况
    int index = x * actual_cols + y;
    if (show[index] != '*' && show[index] != 'P' && show[index] != 'E') 
    {
        return;
    }

    // 3. 统计当前坐标周围的祝福数量：使用物理大小 actual_cols (12)
    int count = get_bless_count(mine, x, y, row,col,actual_cols);

    // 4. 根据祝福数量决定是否继续递归
    if (count == 0) 
    {
        // 周围没有祝福，显示空格
        show[index] = ' ';
        
        // 递归排查周围8个坐标：传入逻辑大小和物理大小
        for (int i = -1; i <= 1; i++) 
        {
            for (int j = -1; j <= 1; j++) 
            {
                if (i == 0 && j == 0) continue; // 跳过自身
                expand_bless(mine, show, x + i, y + j, row, col, actual_cols);
            }
        }
    } 
    else 
    {
        // 周围有祝福，显示祝福个数，停止递归
        show[index] = count + '0';
    }
}


void findbless(player* p, enemy* e, char* mine, char* show, int row, int col, int actual_cols)
{
    if (p == NULL || e == NULL || mine == NULL || show == NULL || row <= 0 || col <= 0 || actual_cols <= 0)
    {
        printf("参数不合法\n");
        return;
    }

    int x = 0;
    int y = 0;
    int battle_round = 0; // 战斗轮数
    int found_bless_count = 0;
    const int bless_value = 100;
    const int decay_value = 10; // 每次战斗攻防衰减量
    int has_health_bless = 0;   // 标记是否获得过生命祝福

    int game_over = 0;
    int winner = 0;
    // 【新增】游戏刚进入循环前，必须先把初始棋盘写给网页，否则网页是黑屏
    writemap(show,row,col, actual_cols);
    writestatus(p, e, game_over, winner);

    while (found_bless_count < blesscount)
    {
        //printf("请玩家输入要祈福的坐标: ");
        
        // if (scanf("%d %d", &x, &y) != 2)
        // {
        //     printf("输入格式错误，请输入两个整数！\n");
        //     while (getchar() != '\n');
        //     continue;
        // }
        printf("等待玩家点击...");
        if (!readclick(&x, &y)) 
        {
        // 没有读取到点击，可以稍微休眠一下避免CPU占用过高
         SLEEP_MS(100); // Windows下使用
        // usleep(100000); // Linux下使用
        continue; // 继续循环检测
        }
        printf("接收到玩家点击坐标: (%d, %d)\n", x, y);
        // 1. 坐标合法性判断：使用逻辑大小 row, col (10)
        // 2. 修复排除玩家/敌人坐标的逻辑：必须同时满足 x 和 y 都相等
        if (x >= 1 && x <= row && y >= 1 && y <= col && 
            !(x == p->x && y == p->y) && !(x == e->x && y == e->y))
        {
            // 计算索引：必须使用物理大小 actual_cols (12)
            int index = x * actual_cols + y;

            if (show[index] != '*' && show[index] != 'P' && show[index] != 'E')
            {
                printf("该坐标已经被祈福过，请不要重复选择\n");
                // 【修改点1】：重复点击不需要更新地图，直接continue
                continue; 
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
                        show[index] = bless_type;
                        game_over = 1;
                        winner = 2; // 【修改点2】：标记玩家输
                        writemap(show, row, col, actual_cols);
                        writestatus(p, e, game_over, winner); // 必须在return前写状态！
                        return;
                    }
                    if (e->health <= 0)
                    {
                        printf("敌人已死亡，玩家挑战成功\n");
                        show[index] = bless_type;
                        game_over = 1;
                        winner = 1; // 【修改点2】：标记玩家输
                        writemap(show, row, col, actual_cols);
                        writestatus(p, e, game_over, winner); // 必须在return前写状态！
                        return;
                    }
                    
                    show[index] = bless_type;
                    found_bless_count++;
                }
                else
                {
                    // 当前坐标没有祝福，调用递归展开函数：传入逻辑大小和物理大小
                    expand_bless(mine, show, x, y, row, col, actual_cols);
                }
                
                // 打印棋盘：传入逻辑大小和物理大小
                displayboard(show, row, col, actual_cols);
                // 【修改点4】：只有发生了有效操作，才更新地图和状态给网页
                writemap(show, row, col, actual_cols);
                writestatus(p, e, game_over, winner);
            }
        }
        else
        {
            printf("坐标不合法或该位置被占用\n");
        }
    }

    printf("恭喜你，找到所有祝福\n");
    displayboard(mine, row, col, actual_cols);
    game_over=1;
    winner=1;
    // 【修正位置】无论坐标是否合法、是否重复，只要进行了一轮读取，就更新一次地图文件给网页
    // 这样网页可以据此清空点击状态或给出错误提示反馈
    writemap(show, row, col, actual_cols);
    writestatus(p, e, game_over, winner);
    //writemap(mine, row, col, actual_cols); // 游戏通关后，把底层雷区也写给网页看看
}