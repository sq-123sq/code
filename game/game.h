#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

#define namesize 200
#define playername "正义的战士"
#define playerattack 233
#define playerdefense 100
#define playerhealth 1000
#define enemyname "邪恶的敌人"
#define enemyattack 130
#define enemydefense 200
#define enemyhealth 2000

#define ROW 10
#define COL 10
#define ROWS (ROW+2)
#define COLS (COL+2)
#define blesscount_health 10
#define blesscount_attack 10
#define blesscount_defense 10
#define blesscount (blesscount_health+blesscount_attack+blesscount_defense)

typedef struct player{
    char name[namesize];
    int health;
    int attack;
    int defense;
}player;
typedef struct enemy{
    char name[namesize];
    int health;
    int attack;
    int defense;
}enemy;
player* createplayer();
enemy* createenemy();
void initplayer(player* p);
void initenemy(enemy* e);
void displayplayer(player* p);
void displayenemy(enemy* e);
void destoryplayer(player* p);
void destoryenemy(enemy* e);


void displayboard(char* board,int rows,int cols);
void initboard(char* board,int rows,int cols,char c);
void setbless(char* board,int rows,int cols);

void findbless(player* p,enemy* e,char* mine,char* show,int rows,int cols);


#endif // GAME_H