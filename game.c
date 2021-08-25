#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void Displayboard(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}
void Initboard(char arr[ROW][COL], int row, int col)
{
	int i,j;
	for (i=0;i<row;i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void Playermove(char arr[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("请输入落子坐标 (行和列间加空格)");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row&&y >= 1 && y <= col)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该处已经落子，请重新输入\n");
			}
		}
		else
		{
			printf("输入坐标超出范围，请重新输入\n");
		}
	}
}
void Computermove(char arr[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑走\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}
char Iswin(char arr[ROW][COL], int row, int col)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];
		}
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
		{
			return arr[0][i];
		}
		if ((arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != ' ') || (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[0][2] != ' '))
		{
			return arr[1][1];
		}

	}
	if (1==Isfull(arr,ROW,COL))
	{
		return 'Q';
	}
	return 'C';
}
int Isfull(char arr[ROW][COL], int row, int col)
{
	int i, j;
	for (i=0;i<row;i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}