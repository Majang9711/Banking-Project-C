#include "BankSystem.h"

//�� ���� ����
struct personal people[10] = { { "�׽�Ʈ1", 100000, 12345678, 12345678 }, { "�׽�Ʈ2", 200000, 87654321, 87654321 } };

//�ݾ� ���ϱ� �Լ�
void PLUS(struct personal* ptr, int money)
{
	ptr->cash += money;
}

//�ݾ� ���� �Լ�
void MINUS(struct personal* ptr, int money)
{
	ptr->cash -= money;
}