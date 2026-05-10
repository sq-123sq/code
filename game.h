#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 3
#define COL 3
void init_board(char board[ROW][COL]);
void print_board(char board[ROW][COL]);
void player_move(char board[ROW][COL]);
void computer_move(char board[ROW][COL]);
char is_win(char board[ROW][COL]);
