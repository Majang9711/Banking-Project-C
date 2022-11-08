#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "BankSystem.h"

extern struct personal people[10];

int main(void)
{
	int i;
	int ID;                //사용자 식별 번호
	int key;               //키보드 입력 값
	int X = 0, Y = 8;      //커서 위치
	system("title Banking System");
restart:
	ID = start();  //프로그램 시작 함수로부터 사용자 식별 번호 반환

	if (ID == -1)
	{
		return 0;  //사용자가 프로그램 종료 선택할 경우 프로그램 종료
	}
	else
	{
	re_main:
		//화면 구성
		screen();
		gotoxy(0, 3);
		printf("%s님 환영합니다.\n\n통장 계좌번호 : %d\n통장 잔액 : %d원\n", people[ID].name, people[ID].account, people[ID].cash);
		gotoxy(1, 8);
		printf("거래 내역");
		gotoxy(1, 9);
		printf("입금");
		gotoxy(1, 10);
		printf("출금");
		gotoxy(1, 11);
		printf("이체");
		gotoxy(1, 12);
		printf("포인트 게임");
		gotoxy(1, 13);
		printf("로그아웃");
		gotoxy(X, Y);
		printf(">");

		//메뉴 조작
		while (1)
		{
			key = _getch();
			switch (key)
			{
			case UP:                 //UP 방향키 누를 경우 위로 메뉴 이동
				if (Y > 8)
				{
					gotoxy(X, Y);
					printf(" ");
					Y--;
					gotoxy(X, Y);
					printf(">");
				}
				break;
			case DOWN:               //DOWN 방향키 누를 경우 아래로 메뉴 이동
				if (Y < 13)
				{
					gotoxy(X, Y);
					printf(" ");
					Y++;
					gotoxy(X, Y);
					printf(">");
				}
				break;
			case SPACE:              //스페이스바 누를 경우 메뉴 선택
				system("cls");
				switch (Y)
				{
				case 8:       //거래 내역 선택
					printf("서비스 준비 중입니다.");
					Sleep(2000);
					goto re_main;
				case 9:       //입금 선택
					deposit(ID);
					goto re_main;
				case 10:      //출금 선택
					withdraw(ID);
					goto re_main;
				case 11:      //이체 선택
					transfer(ID);
					goto re_main;
				case 12:      //포인트 게임 선택
					printf("서비스 준비 중입니다.");
					Sleep(2000);
					goto re_main;
				default:      //로그아웃 선택 -> 프로그램 시작 화면으로 이동
					goto restart;
					break;
				}
				break;
			}

		}
	}
}