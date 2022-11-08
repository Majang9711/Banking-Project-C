#include <sqlite3.h>
#include <stdio.h>
#include "submain.h"
#include "curd.h"

//curd.h함수
void createData(int id, char * name, int pwd, int money);   //데이터 생성
void allClear(void);                                        //데이터 모두 삭제

int myMoney(int id);                                        //내 돈
void addMoney(int id, int nowMoney, int money);             //돈 주기
void reduceMoney(int id, int nowMoney, int money);          //돈 뺏기
void setMoney(int id, int money);                           //돈 설정

char *readName(int id);                                     //이름 읽기
void setName(int id, char * name);                          //이름 설정

int readPwd(int id);                                        //비밀번호 읽기
void setPwd(int id, int pwd);                               //비밀번호 설정

int readId(char * name, int pwd);                           //아이디 읽기
void setId(char * name, int pwd, int id);                   //아이디 설정


int main()
{
//    setPwd(1234567, 9711);
//    setMoney(1234567, 1000);
    printf("내 아이디 : %d \n", readId("apple", 9711));
    printf("내 이름 : %s \n", readName(12345678)); //이름값이 이상하게 출력...ㅠㅠㅠ
    printf("내 돈 : %d \n", myMoney(12345678));
    printf("내 비밀번호 : %d \n", readPwd(12345678));
//    addMoney(1234567, myMoney(1234567), 100);
//    allClear();
//    createData(1234567, "이정진2", 1000, 1000);
//    setName(12345, "dd김정진ddddd");
    
    
    
    return 0;
}
