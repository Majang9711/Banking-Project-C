#pragma once

#define UP 72       //키보드 UP 방향키
#define DOWN 80     //키보드 DOWN 방향키
#define SPACE ' '   //키보드 스페이스바

//고객 개인 정보 구조체
struct personal {
	char name[10];
	int cash;
	int account;
	int password;
};

void gotoxy(int x, int y);  //커서 이동 함수
void screen(void);          //화면 기본 틀 출력 함수

int start(void);            //프로그램 시작 함수

void PLUS(struct personal* ptr, int money);  //금액 더하기 함수
void MINUS(struct personal* ptr, int money);  //금액 빼기 함수

void deposit(int ID);  //입금 함수
void withdraw(int ID); //출금 함수
void transfer(int ID); //이체 함수