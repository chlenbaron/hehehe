# define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("**********************************\n");
	printf("*************ɨ��С��Ϸ***********\n");
	printf("***************1.PLAY*************\n");
	printf("***************0.EXIT*************\n");
	printf("**********************************\n");
	printf("**********************************\n");
}
void game()
{
	char arrg1[ROWS + 2][COLS + 2] = { 0 };
	char arrg2[ROWS + 2][COLS + 2] = { 0 };
	memset(arrg1, '*', sizeof(char)*(ROWS + 2)*(COLS + 2));
	memset(arrg2, '0', sizeof(char)*(ROWS + 2)*(COLS + 2));
	display(arrg1, ROWS, COLS);
	make_mine(arrg2, ROWS, COLS);
	display(arrg2, ROWS, COLS);
	int i = 0;
	while (i < ROWS*COLS - MINE)
	{
		int x = 0;
		int y = 0;
		int count = 0;
		//if (MINE == i)
		//{
		//	void win_mine(arrg2);
		//}
		printf("���������� �� 1 3\n");
		scanf("%d %d", &x, &y);
		fflush(stdin);
		system("cls");
		printf("��ȥǰ��̽̽·\n");
		Sleep(2000);
		system("cls");
		if (i == 0)
		{
			hide_mine(arrg2, x, y);
		}
		if (arrg2[x][y] == '1')
		{
			printf("�㱻ը����\n");
			display(arrg1, ROWS, COLS);
			break;
		}
		else
		{
			i++;
		   statistics_mines(arrg2, arrg1, x, y);
		   display(arrg1, ROWS, COLS);
		}
	}
	if (i >= ROWS*COLS - MINE)
	{
		printf("!!!ʤ����������������\n");
		display(arrg2, ROWS, COLS);
	}
}
enum Option
{
	EXIT,
	PLAY
};
int main()
{
	int input = 0;
	srand((int unsigned)time(NULL));
	do
	{
		menu();
		printf("�Ƿ�Ҫ��ʼ��Ϸ\n");
		scanf("%d", &input);
		fflush(stdin);
		switch (input)
		{
		case PLAY:

			while (1)
			{
				game();
				//Sleep(3000);
				//system("cls");
				break;
			}
		case EXIT:
			break;
		default:
			printf("ѡ����� ����������\n");
			break;

		}
	} while (input);
	return 0;
}

