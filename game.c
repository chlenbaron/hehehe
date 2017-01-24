# define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
void display(char arr[ROWS + 2][COLS + 2], int rows, int cols)
{
	int i = 0;
	int j = 0;
	printf("    ");
	for (i = 1; i <= 10; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i <= rows; i++)
	{
		printf(" %2d ", i);
		for (j = 1; j <= cols; j++)


		{
			printf(" %c ", arr[i][j]);
		}
		printf("\n");

	}

}
int randd()
{
	return  (rand() % 10 + 1);
}
void make_mine(char arr[ROWS + 2][COLS + 2], int rows, int cols)
{
	int count = MINE;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = randd();
		y = randd();
		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
	}
}
int statistics_mine(char arr[ROWS + 2][COLS + 2], char arr2[ROWS + 2][COLS + 2], int x, int y)
{

		return(arr[x - 1][y - 1] - '0' +
			arr[x][y - 1] - '0' +
			arr[x + 1][y - 1] - '0' +
			arr[x + 1][y] - '0' +
			arr[x + 1][y + 1] - '0' +
			arr[x][y + 1] - '0' +
			arr[x - 1][y + 1] - '0' +
			arr[x - 1][y] - '0');

}
void statistics_mines(char arr[ROWS + 2][COLS + 2], char arr2[ROWS + 2][COLS + 2], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = x - 1; i <= x + 1; i++)   //arr2显示棋盘
	{                                  //arr是雷阵
		for (j = y - 1; j <= y + 1; j++)
		{
			if (arr2[i][j] == ' ')
			{
				continue;
			}
			//if (x == i&&y == j)
			//{
			//	arr2[i][j] = ' ';
			//}
			if (arr[i][j] == '1')
			{
				arr2[i][j] = '!'; //表示有雷
			}
			else
				arr2[i][j] = statistics_mine(arr, arr2, i , j ) + '0';

		}

	}
	arr2[x][y] = ' ';
}
void hide_mine(char arr[ROWS + 2][COLS + 2], int x, int y)
{
	int i = 0;
	int j = 0;
	if (arr[x][y] == '1')
	{
		i = x;
		j = y;
		arr[x][y] = '0';
		while (1)
		{
			x = randd();
			y = randd();
			if (arr[x][y] == '0'&&(((x*10)+y)!=((i*10)+j)))
			{
				arr[x][y] = '1';
				break;
			}
		}
	}
}
void win_mine(char arr[ROWS + 2][COLS + 2])
{
	int i = 1;
	int j = 1;
	int num = 0;
	for (i = 1; i <= ROWS; i++)
	{
		for (j = 1; j <= COLS; j++)
		{
			if ('!' == arr[i][j])
			{
				num++;
			}
		}
	}
	if (MINE == num)
	{
		printf("你赢了\n");
	}
}
