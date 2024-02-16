#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int Coord_Judge(char board[ROW][COL], int x, int y)//判读棋子坐标
{ 
	if (x <= ROW && y <= COL)//棋子坐标在棋盘范围内
	{
		if(board[x-1][y-1]==' ')//落棋位置是否为空
			return 1;
	}
	return 0;//不符合棋子输入规则
}

void Board_Init(char board[ROW][COL])//棋盘初始化
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';//将棋盘所有位置都置空
		}
	}
}

void Board_Display(char board[ROW][COL], int row, int col)//棋盘显示
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);//打印棋盘中的棋子
			if (j < col - 1)
			{
				printf("|");
			}
			
		}	
		printf("\n");
		
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
	printf("\n");
}

void Play_Move(char board[ROW][COL])//玩家下棋
{
	int x, y;
	printf("请玩家输入棋子坐标:>");
	
	while (1)
	{
		scanf("%d %d", &x, &y);
		//判断坐标可行性
		int PlayNum_Judge = Coord_Judge(board, x, y);
		if (PlayNum_Judge)
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else
			printf("输入坐标有误,请重新输入\n");
	}
}

void Bot_Play(char board[ROW][COL])//电脑下棋
{
	while (1)
	{	int x = rand() % ROW;
		int y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char Game_Judge(char board[ROW][COL])//判断游戏是否继续
{
	//0_玩家主对角线计数器  1_电脑主对角线计数器 2_玩家横向计数器 3_电脑横向计数器  4_玩家纵向计数器  5_电脑纵向计数器
	//6_玩家副对角线计数  7_电脑副对角线计数  8_棋满计数器
	int count_arr[9] = { 0 };

	for (int row = 0; row < ROW; row++)        //很牛逼的判断，不愧是你！！！！
	{
		for (int col = 0; col < COL; col++)
		{
			if (board[col][col] == '*')//玩家主对角线判断
			{
				count_arr[0]++;
				if (count_arr[0] == ROW)
				{
					return '*';
				}
			}

			if (board[col][col] == '#')//电脑主对角线判断
			{
				count_arr[1]++;
				if (count_arr[1] == ROW)
				{
					return '#';
				}
			}

			if(board[ROW - 1 - col][col]=='*')//玩家副对角线判断
			{
				count_arr[6]++;
				if (count_arr[6] == ROW)
				{
					return '*';
				}
			}

			if (board[ROW - 1 - col][col] == '#')//电脑副对角线判断
			{
				count_arr[7]++;
				if (count_arr[7] == ROW)
				{
					return '*';
				}
			}
	
			if (board[row][col] == '*')//玩家横向判断
			{
				count_arr[2]++;
				if (count_arr[2] == ROW)
				{
					return '*';
				}
			}
			
			if (board[row][col] == '#')//电脑横向判断
			{
				count_arr[3]++;
				if (count_arr[3] == ROW)
				{
					return '#';
				}
			}

			if (board[col][row] == '*')//玩家纵向判断
			{
				count_arr[4]++;
				if (count_arr[4] == ROW)
				{
					return '*';
				}
			}

			if (board[col][row] == '#')//电脑横向判断
			{
				count_arr[5]++;
				if (count_arr[5] == ROW)
				{
					return '#';
				}
			}
			
			if (board[row][col] == ' ')//是否满格判断
			{
				count_arr[8]++;
			}
		}
		for (int i = 0; i < 8; i++)
		{
			count_arr[i] = 0;
		}
	}
	if (!count_arr[8])
	{
		return 'E';
	}
	count_arr[8] = 0;
}