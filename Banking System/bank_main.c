#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "BankSystem.h"

extern struct personal people[10];

int main(void)
{
	int i;
	int ID;                //����� �ĺ� ��ȣ
	int key;               //Ű���� �Է� ��
	int X = 0, Y = 8;      //Ŀ�� ��ġ
	system("title Banking System");
restart:
	ID = start();  //���α׷� ���� �Լ��κ��� ����� �ĺ� ��ȣ ��ȯ

	if (ID == -1)
	{
		return 0;  //����ڰ� ���α׷� ���� ������ ��� ���α׷� ����
	}
	else
	{
	re_main:
		//ȭ�� ����
		screen();
		gotoxy(0, 3);
		printf("%s�� ȯ���մϴ�.\n\n���� ���¹�ȣ : %d\n���� �ܾ� : %d��\n", people[ID].name, people[ID].account, people[ID].cash);
		gotoxy(1, 8);
		printf("�ŷ� ����");
		gotoxy(1, 9);
		printf("�Ա�");
		gotoxy(1, 10);
		printf("���");
		gotoxy(1, 11);
		printf("��ü");
		gotoxy(1, 12);
		printf("����Ʈ ����");
		gotoxy(1, 13);
		printf("�α׾ƿ�");
		gotoxy(X, Y);
		printf(">");

		//�޴� ����
		while (1)
		{
			key = _getch();
			switch (key)
			{
			case UP:                 //UP ����Ű ���� ��� ���� �޴� �̵�
				if (Y > 8)
				{
					gotoxy(X, Y);
					printf(" ");
					Y--;
					gotoxy(X, Y);
					printf(">");
				}
				break;
			case DOWN:               //DOWN ����Ű ���� ��� �Ʒ��� �޴� �̵�
				if (Y < 13)
				{
					gotoxy(X, Y);
					printf(" ");
					Y++;
					gotoxy(X, Y);
					printf(">");
				}
				break;
			case SPACE:              //�����̽��� ���� ��� �޴� ����
				system("cls");
				switch (Y)
				{
				case 8:       //�ŷ� ���� ����
					printf("���� �غ� ���Դϴ�.");
					Sleep(2000);
					goto re_main;
				case 9:       //�Ա� ����
					deposit(ID);
					goto re_main;
				case 10:      //��� ����
					withdraw(ID);
					goto re_main;
				case 11:      //��ü ����
					transfer(ID);
					goto re_main;
				case 12:      //����Ʈ ���� ����
					printf("���� �غ� ���Դϴ�.");
					Sleep(2000);
					goto re_main;
				default:      //�α׾ƿ� ���� -> ���α׷� ���� ȭ������ �̵�
					goto restart;
					break;
				}
				break;
			}

		}
	}
}