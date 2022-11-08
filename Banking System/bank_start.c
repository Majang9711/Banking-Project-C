#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "BankSystem.h"

extern struct personal people[10];

int login(void);  //�α��� �Լ�
void join(void);   //ȸ������ �Լ�

//���α׷� ���� �Լ�
int start(void)
{
	int i;
	int key;             //Ű���� �Է� ��
	int X = 20, Y = 10;  //Ŀ�� ��ġ

	//ȭ�� ����
	screen();
	gotoxy(17, 5);
	printf("���� ���� �ý���");
	gotoxy(21, 10);
	printf("�α���");
	gotoxy(21, 11);
	printf("ȸ������");
	gotoxy(21, 12);
	printf("���α׷� ����");
	gotoxy(X, Y);
	printf(">");

	//�޴� ����
	while (1)
	{
		key = _getch();
		switch (key)
		{
		case UP:              //UP ����Ű ���� ��� ���� �޴� �̵�
			if (Y > 10)
			{
				gotoxy(X, Y);
				printf(" ");
				Y--;
				gotoxy(X, Y);
				printf(">");
			}
			break;
		case DOWN:            //DOWN ����Ű ���� ��� �Ʒ��� �޴� �̵�
			if (Y < 12)
			{
				gotoxy(X, Y);
				printf(" ");
				Y++;
				gotoxy(X, Y);
				printf(">");
			}
			break;
		case SPACE:           //�����̽��� ���� ��� �޴� ����
			system("cls");
			switch (Y)
			{
			case 10:           //�α��� ����
				return login();
			case 11:           //ȸ������ ����
				join();
				return login();
			default:           //���α׷� ���� ����
				return -1;      
			}
			break;
		}
	}
}

//�α��� �Լ�
int login(void)
{
	int i;
	int account, password;  //���¹�ȣ, ��й�ȣ
retry:
	//ȭ�� ����
	screen();
	gotoxy(22, 5);
	printf("�α���");
	gotoxy(17, 10);
	printf("���¹�ȣ ________");
	gotoxy(17, 11);
	printf("��й�ȣ ________");

	gotoxy(26, 10);
	scanf_s("%d", &account);   //���¹�ȣ �Է�
	gotoxy(26, 11);
	scanf_s("%d", &password);  //��й�ȣ �Է�

	//���¹�ȣ �� ��й�ȣ�� ��ġ ���� Ȯ��
	for (i = 0; i < 10; i++)
	{
		if (account == people[i].account)
		{
			if (password == people[i].password)
			{
				system("cls");
				return i;     //�α��� ���� -> ���� ȭ������ �̵�
			}
			else
			{
				gotoxy(12, 7);
				printf("��й�ȣ�� �ùٸ��� �ʽ��ϴ�.");
				goto retry;  //�α��� �ٽ� �ϱ�
			}
		}
	}
	gotoxy(12, 7);
	printf("���¹�ȣ�� �ùٸ��� �ʽ��ϴ�.");
	goto retry;  //�α��� �ٽ� �ϱ�
}

//ȸ������ �Լ�
void join(void)
{
	static int N = 2;           //����� �ĺ� ��ȣ

	//ȭ�� ����
	screen();
	gotoxy(21, 5);
	printf("ȸ������");
	gotoxy(17, 9);
	printf("�̸� ____");
	gotoxy(17, 10);
	printf("���¹�ȣ ________");
	gotoxy(17, 11);
	printf("��й�ȣ ________");
	gotoxy(17, 12);
	printf("���� ���� �ܾ� ________________��");

	gotoxy(22, 9);
	scanf_s("%s", people[N].name, 10);   //�̸� �Է�
	gotoxy(26, 10);
	scanf_s("%d", &people[N].account);   //���¹�ȣ �Է�
	gotoxy(26, 11);
	scanf_s("%d", &people[N].password);  //��й�ȣ �Է�
	gotoxy(32, 12);
	scanf_s("%d", &people[N].cash);  //���� ���� �ܾ� �Է�

	N++;
	system("cls");
}