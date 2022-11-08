#include "BankSystem.h"

//고객 개인 정보
struct personal people[10] = { { "테스트1", 100000, 12345678, 12345678 }, { "테스트2", 200000, 87654321, 87654321 } };

//금액 더하기 함수
void PLUS(struct personal* ptr, int money)
{
	ptr->cash += money;
}

//금액 빼기 함수
void MINUS(struct personal* ptr, int money)
{
	ptr->cash -= money;
}