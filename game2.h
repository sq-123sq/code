#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define MINES 10
void init_board(char board[ROWS][COLS],char c);
void display_board(char board[ROWS][COLS]);
void setmine(char board[ROWS][COLS]);
void findmine(char mine[ROWS][COLS],char show[ROWS][COLS]);