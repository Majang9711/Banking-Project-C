#include <stdio.h>
#include <Windows.h>
#include "BankSystem.h"

extern struct personal people[10];

//입금 함수
void deposit(int ID)
{
	int money = 0;  //입금할 금액

	//화면 구성
	screen();
	gotoxy(23, 5);
	printf("입금");
	gotoxy(12, 10);
	printf("입금할 금액 _____________원");

	gotoxy(24, 10);
	scanf_s("%d", &money);   //입금할 금액 입력

	PLUS(&people[ID], money);  //입금 처리

	//이체 결과 출력
	system("cls");
	screen();
	gotoxy(15, 5);
	printf("입금이 완료되었습니다.");
	gotoxy(15, 8);
	printf("입금 : %d원", money);
	gotoxy(15, 9);
	printf("통장 잔액 : %d원", people[ID].cash);
	Sleep(2000);

	system("cls");
	return;
}

//출금 함수
void withdraw(int ID)
{
	int money = 0;  //출금할 금액

	//화면 구성
	screen();
	gotoxy(23, 5);
	printf("출금");
	gotoxy(12, 10);
	printf("출금할 금액 _____________원");

	gotoxy(24, 10);
	scanf_s("%d", &money);   //출금할 금액 입력

	MINUS(&people[ID], money);  //출금 처리

	//이체 결과 출력
	system("cls");
	screen();
	gotoxy(15, 5);
	printf("출금이 완료되었습니다.");
	gotoxy(15, 8);
	printf("출금 : %d원", money);
	gotoxy(15, 9);
	printf("통장 잔액 : %d원", people[ID].cash);
	Sleep(2000);

	system("cls");
	return;
}

//이체 함수
void transfer(int ID)
{
	int i;
	int money = 0;  //이체할 금액
	int recieve_account = 0;  //받는 분 계좌번호

	//화면 구성
retry:
	screen();
	gotoxy(23, 5);
	printf("이체");
	gotoxy(12, 10);
	printf("받는 분의 계좌번호 ________");
	gotoxy(12, 11);
	printf("이체할 금액 _____________원");

	gotoxy(31, 10);
	scanf_s("%d", &recieve_account);   //받는 분 계좌번호 입력
	gotoxy(24, 11);
	scanf_s("%d", &money);   //이체할 금액 입력

	//계좌번호에 맞는 사용자 검색
	for (i = 0; i < 10; i++)
	{
		if (recieve_account == people[i].account)
		{
			MINUS(&people[ID], money);  //출금 처리
			PLUS(&people[i], money);  //입금 처리
			break;
		}
	}

	//계좌번호가 검색되지 않을 경우
	if (i == 10)
	{
		system("cls");
		gotoxy(10, 6);
		printf("계좌번호가 올바르지 않습니다.");
		goto retry;
	}

	//이체 결과 출력
	system("cls");
	screen();
	gotoxy(15, 5);
	printf("이체가 완료되었습니다.");
	gotoxy(15, 8);
	printf("이체한 금액 : %d원", money);
	gotoxy(15, 9);
	printf("통장 잔액 : %d원", people[ID].cash);
	Sleep(2000);

	system("cls");
	return;
}