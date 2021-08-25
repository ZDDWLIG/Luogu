#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void Displayboard(char arr[ROW][COL], int row, int col);
void Initboard(char arr[ROW][COL], int row, int col);
void Playermove(char arr[ROW][COL], int row, int col);
void Computermove(char arr[ROW][COL], int row, int col);
char Iswin(char arr[ROW][COL], int row, int col);
int Isfull(char arr[ROW][COL], int row, int col);
