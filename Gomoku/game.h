

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 3
#define COL 3

void Board_Init(char board[ROW][COL]);//���̳�ʼ��
void Board_Display(char board[ROW][COL], int row, int col);//������ʾ
void Play_Move(char board[ROW][COL]);//�������
void Bot_Play(char board[ROW][COL]);//��������
int Coord_Judge(char board[ROW][COL], int x, int y);//�����ж��Ƿ����
char Game_Judge(char board[ROW][COL]);//�ж���Ϸ�Ƿ����