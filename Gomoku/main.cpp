#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void Menu(void)
{
	printf("***************************************\n");
	printf("********     1.Play     ***************\n");
	printf("********     0.Exit     ***************\n");
	printf("***************************************\n");

}

void Game()
{
	//创建二维数组以保存棋盘数据
	char Board_Data[ROW][COL];
	//棋盘初始化
	Board_Init(Board_Data);
	//打印棋盘
	Board_Display(Board_Data,ROW,COL);
	
	while (1)
	{
		Play_Move(Board_Data);
		Board_Display(Board_Data, ROW, COL);
		char J = Game_Judge(Board_Data);
		if (J == '*')
		{
			printf("Game over,Winner is player\n");
			break;
		}
		else if (J == '#')
		{
			printf("Game over,Bot is player\n");
			break;
		}
		else if (J == 'E')
		{
			printf("Game over,Dead heat\n");
			break;
		}
		Bot_Play(Board_Data);
		Board_Display(Board_Data, ROW, COL);
		J = Game_Judge(Board_Data);

		if (J == '*')
		{
			printf("Game over,Winner is player\n");
			break;
		}
		else if (J == '#')
		{
			printf("Game over,Bot is player\n");
			break;
		}
		else if (J == 'E')
		{
			printf("Game over,Dead heat\n");
			break;
		}
	}
	printf("是否重新开始游戏 :> 0 / 1\n");
}

int main()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	//打印游戏菜单
	Menu();
	do
	{
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出成功");
			break;
		default:
			printf("请重新输入");
		}
	}while (i);
	return 0;
}