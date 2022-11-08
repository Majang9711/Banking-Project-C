#include <stdio.h>
#include <Windows.h>
#include "BankSystem.h"

extern struct personal people[10];

//�Ա� �Լ�
void deposit(int ID)
{
	int money = 0;  //�Ա��� �ݾ�

	//ȭ�� ����
	screen();
	gotoxy(23, 5);
	printf("�Ա�");
	gotoxy(12, 10);
	printf("�Ա��� �ݾ� _____________��");

	gotoxy(24, 10);
	scanf_s("%d", &money);   //�Ա��� �ݾ� �Է�

	PLUS(&people[ID], money);  //�Ա� ó��

	//��ü ��� ���
	system("cls");
	screen();
	gotoxy(15, 5);
	printf("�Ա��� �Ϸ�Ǿ����ϴ�.");
	gotoxy(15, 8);
	printf("�Ա� : %d��", money);
	gotoxy(15, 9);
	printf("���� �ܾ� : %d��", people[ID].cash);
	Sleep(2000);

	system("cls");
	return;
}

//��� �Լ�
void withdraw(int ID)
{
	int money = 0;  //����� �ݾ�

	//ȭ�� ����
	screen();
	gotoxy(23, 5);
	printf("���");
	gotoxy(12, 10);
	printf("����� �ݾ� _____________��");

	gotoxy(24, 10);
	scanf_s("%d", &money);   //����� �ݾ� �Է�

	MINUS(&people[ID], money);  //��� ó��

	//��ü ��� ���
	system("cls");
	screen();
	gotoxy(15, 5);
	printf("����� �Ϸ�Ǿ����ϴ�.");
	gotoxy(15, 8);
	printf("��� : %d��", money);
	gotoxy(15, 9);
	printf("���� �ܾ� : %d��", people[ID].cash);
	Sleep(2000);

	system("cls");
	return;
}

//��ü �Լ�
void transfer(int ID)
{
	int i;
	int money = 0;  //��ü�� �ݾ�
	int recieve_account = 0;  //�޴� �� ���¹�ȣ

	//ȭ�� ����
retry:
	screen();
	gotoxy(23, 5);
	printf("��ü");
	gotoxy(12, 10);
	printf("�޴� ���� ���¹�ȣ ________");
	gotoxy(12, 11);
	printf("��ü�� �ݾ� _____________��");

	gotoxy(31, 10);
	scanf_s("%d", &recieve_account);   //�޴� �� ���¹�ȣ �Է�
	gotoxy(24, 11);
	scanf_s("%d", &money);   //��ü�� �ݾ� �Է�

	//���¹�ȣ�� �´� ����� �˻�
	for (i = 0; i < 10; i++)
	{
		if (recieve_account == people[i].account)
		{
			MINUS(&people[ID], money);  //��� ó��
			PLUS(&people[i], money);  //�Ա� ó��
			break;
		}
	}

	//���¹�ȣ�� �˻����� ���� ���
	if (i == 10)
	{
		system("cls");
		gotoxy(10, 6);
		printf("���¹�ȣ�� �ùٸ��� �ʽ��ϴ�.");
		goto retry;
	}

	//��ü ��� ���
	system("cls");
	screen();
	gotoxy(15, 5);
	printf("��ü�� �Ϸ�Ǿ����ϴ�.");
	gotoxy(15, 8);
	printf("��ü�� �ݾ� : %d��", money);
	gotoxy(15, 9);
	printf("���� �ܾ� : %d��", people[ID].cash);
	Sleep(2000);

	system("cls");
	return;
}