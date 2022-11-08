#include <Windows.h>
#include "BankSystem.h"

//커서 이동 함수
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//화면 기본 틀 출력 함수
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