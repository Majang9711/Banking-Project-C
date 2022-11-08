#pragma once

#define UP 72       //Ű���� UP ����Ű
#define DOWN 80     //Ű���� DOWN ����Ű
#define SPACE ' '   //Ű���� �����̽���

//�� ���� ���� ����ü
struct personal {
	char name[10];
	int cash;
	int account;
	int password;
};

void gotoxy(int x, int y);  //Ŀ�� �̵� �Լ�
void screen(void);          //ȭ�� �⺻ Ʋ ��� �Լ�

int start(void);            //���α׷� ���� �Լ�

void PLUS(struct personal* ptr, int money);  //�ݾ� ���ϱ� �Լ�
void MINUS(struct personal* ptr, int money);  //�ݾ� ���� �Լ�

void deposit(int ID);  //�Ա� �Լ�
void withdraw(int ID); //��� �Լ�
void transfer(int ID); //��ü �Լ�