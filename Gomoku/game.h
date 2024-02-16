

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3//想玩几子棋把这里改了就好了
#define COL 3

void Board_Init(char board[ROW][COL]);//棋盘初始化
void Board_Display(char board[ROW][COL], int row, int col);//棋盘显示
void Play_Move(char board[ROW][COL]);//玩家下棋
void Bot_Play(char board[ROW][COL]);//电脑下棋
int Coord_Judge(char board[ROW][COL], int x, int y);//坐标判断是否可行
char Game_Judge(char board[ROW][COL]);//判断游戏是否继续
