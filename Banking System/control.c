#include <Windows.h>
#include "BankSystem.h"

//Ŀ�� �̵� �Լ�
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//ȭ�� �⺻ Ʋ ��� �Լ�
void screen(void)
{
	int i;
	gotoxy(0, 0);
	for (i = 1; i <= 50; i++)
		printf("=");
	gotoxy(0, 15);
	for (i = 1; i <= 50; i++)
		printf("=");
}