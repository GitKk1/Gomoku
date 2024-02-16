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
	//������ά�����Ա�����������
	char Board_Data[ROW][COL];
	//���̳�ʼ��
	Board_Init(Board_Data);
	//��ӡ����
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
	printf("�Ƿ����¿�ʼ��Ϸ :> 0 / 1\n");
}

int main()
{
	int i = 0;
	srand((unsigned int)time(NULL));
	//��ӡ��Ϸ�˵�
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
			printf("�˳��ɹ�");
			break;
		default:
			printf("����������");
		}
	}while (i);
	return 0;
}