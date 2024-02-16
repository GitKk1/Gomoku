#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int Coord_Judge(char board[ROW][COL], int x, int y)//�ж���������
{ 
	if (x <= ROW && y <= COL)//�������������̷�Χ��
	{
		if(board[x-1][y-1]==' ')//����λ���Ƿ�Ϊ��
			return 1;
	}
	return 0;//�����������������
}

void Board_Init(char board[ROW][COL])//���̳�ʼ��
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = ' ';//����������λ�ö��ÿ�
		}
	}
}

void Board_Display(char board[ROW][COL], int row, int col)//������ʾ
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);//��ӡ�����е�����
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

void Play_Move(char board[ROW][COL])//�������
{
	int x, y;
	printf("�����������������:>");
	
	while (1)
	{
		scanf("%d %d", &x, &y);
		//�ж����������
		int PlayNum_Judge = Coord_Judge(board, x, y);
		if (PlayNum_Judge)
		{
			board[x - 1][y - 1] = '*';
			break;
		}
		else
			printf("������������,����������\n");
	}
}

void Bot_Play(char board[ROW][COL])//��������
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

char Game_Judge(char board[ROW][COL])//�ж���Ϸ�Ƿ����
{
	//0_������Խ��߼�����  1_�������Խ��߼����� 2_��Һ�������� 3_���Ժ��������  4_������������  5_�������������
	//6_��Ҹ��Խ��߼���  7_���Ը��Խ��߼���  8_����������
	int count_arr[9] = { 0 };

	for (int row = 0; row < ROW; row++)        //��ţ�Ƶ��жϣ��������㣡������
	{
		for (int col = 0; col < COL; col++)
		{
			if (board[col][col] == '*')//������Խ����ж�
			{
				count_arr[0]++;
				if (count_arr[0] == ROW)
				{
					return '*';
				}
			}

			if (board[col][col] == '#')//�������Խ����ж�
			{
				count_arr[1]++;
				if (count_arr[1] == ROW)
				{
					return '#';
				}
			}

			if(board[ROW - 1 - col][col]=='*')//��Ҹ��Խ����ж�
			{
				count_arr[6]++;
				if (count_arr[6] == ROW)
				{
					return '*';
				}
			}

			if (board[ROW - 1 - col][col] == '#')//���Ը��Խ����ж�
			{
				count_arr[7]++;
				if (count_arr[7] == ROW)
				{
					return '*';
				}
			}
	
			if (board[row][col] == '*')//��Һ����ж�
			{
				count_arr[2]++;
				if (count_arr[2] == ROW)
				{
					return '*';
				}
			}
			
			if (board[row][col] == '#')//���Ժ����ж�
			{
				count_arr[3]++;
				if (count_arr[3] == ROW)
				{
					return '#';
				}
			}

			if (board[col][row] == '*')//��������ж�
			{
				count_arr[4]++;
				if (count_arr[4] == ROW)
				{
					return '*';
				}
			}

			if (board[col][row] == '#')//���Ժ����ж�
			{
				count_arr[5]++;
				if (count_arr[5] == ROW)
				{
					return '#';
				}
			}
			
			if (board[row][col] == ' ')//�Ƿ������ж�
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