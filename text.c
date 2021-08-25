#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("*********************\n");
	printf("*****   1.play  *****\n");
	printf("*****   0.exit  *****\n");
	printf("*********************\n");

}
void game()
{
	char ret;
	char arr[ROW][COL] = { 0 };
	Initboard(arr, ROW, COL);
	Displayboard(arr, ROW, COL);
	while (1)
	{
		Playermove(arr, ROW, COL);
		Displayboard(arr, ROW, COL);
		ret = Iswin(arr,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		Computermove(arr, ROW, COL);
		Displayboard(arr, ROW, COL);
		ret = Iswin(arr,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("恭喜，你赢了!\n");
	}
	else if (ret == '#')
	{
		printf("真遗憾，你输了\n");
	}
	else
	{
		printf("平局");
	}
}
void text()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择 1 或 0\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("三子棋开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
}
int main()
{
	srand((unsigned int)time(0));
	text();
	return 0;
}