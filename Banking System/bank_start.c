#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "BankSystem.h"

extern struct personal people[10];

int login(void);  //로그인 함수
void join(void);   //회원가입 함수

//프로그램 시작 함수
int start(void)
{
	int i;
	int key;             //키보드 입력 값
	int X = 20, Y = 10;  //커서 위치

	//화면 구성
	screen();
	gotoxy(17, 5);
	printf("은행 관리 시스템");
	gotoxy(21, 10);
	printf("로그인");
	gotoxy(21, 11);
	printf("회원가입");
	gotoxy(21, 12);
	printf("프로그램 종료");
	gotoxy(X, Y);
	printf(">");

	//메뉴 조작
	while (1)
	{
		key = _getch();
		switch (key)
		{
		case UP:              //UP 방향키 누를 경우 위로 메뉴 이동
			if (Y > 10)
			{
				gotoxy(X, Y);
				printf(" ");
				Y--;
				gotoxy(X, Y);
				printf(">");
			}
			break;
		case DOWN:            //DOWN 방향키 누를 경우 아래로 메뉴 이동
			if (Y < 12)
			{
				gotoxy(X, Y);
				printf(" ");
				Y++;
				gotoxy(X, Y);
				printf(">");
			}
			break;
		case SPACE:           //스페이스바 누를 경우 메뉴 선택
			system("cls");
			switch (Y)
			{
			case 10:           //로그인 선택
				return login();
			case 11:           //회원가입 선택
				join();
				return login();
			default:           //프로그램 종료 선택
				return -1;      
			}
			break;
		}
	}
}

//로그인 함수
int login(void)
{
	int i;
	int account, password;  //계좌번호, 비밀번호
retry:
	//화면 구성
	screen();
	gotoxy(22, 5);
	printf("로그인");
	gotoxy(17, 10);
	printf("계좌번호 ________");
	gotoxy(17, 11);
	printf("비밀번호 ________");

	gotoxy(26, 10);
	scanf_s("%d", &account);   //계좌번호 입력
	gotoxy(26, 11);
	scanf_s("%d", &password);  //비밀번호 입력

	//계좌번호 및 비밀번호의 일치 여부 확인
	for (i = 0; i < 10; i++)
	{
		if (account == people[i].account)
		{
			if (password == people[i].password)
			{
				system("cls");
				return i;     //로그인 성공 -> 메인 화면으로 이동
			}
			else
			{
				gotoxy(12, 7);
				printf("비밀번호가 올바르지 않습니다.");
				goto retry;  //로그인 다시 하기
			}
		}
	}
	gotoxy(12, 7);
	printf("계좌번호가 올바르지 않습니다.");
	goto retry;  //로그인 다시 하기
}

//회원가입 함수
void join(void)
{
	static int N = 2;           //사용자 식별 번호

	//화면 구성
	screen();
	gotoxy(21, 5);
	printf("회원가입");
	gotoxy(17, 9);
	printf("이름 ____");
	gotoxy(17, 10);
	printf("계좌번호 ________");
	gotoxy(17, 11);
	printf("비밀번호 ________");
	gotoxy(17, 12);
	printf("현재 통장 잔액 ________________원");

	gotoxy(22, 9);
	scanf_s("%s", people[N].name, 10);   //이름 입력
	gotoxy(26, 10);
	scanf_s("%d", &people[N].account);   //계좌번호 입력
	gotoxy(26, 11);
	scanf_s("%d", &people[N].password);  //비밀번호 입력
	gotoxy(32, 12);
	scanf_s("%d", &people[N].cash);  //현재 통장 잔액 입력

	N++;
	system("cls");
}