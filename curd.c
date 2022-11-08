#include "curd.h"
#include "sqlite3.h"
#include "string.h"ㅌ
#include "stdio.h"

sqlite3 *db; //구조체 포인터 데이터베이스 핸들
char *err_msg = 0; //에러 메세지
int *result_money = 0; //반환할 돈
int *result_pwd = 1234; //비밀번호
int *result_id; //ID(계좌번호)
char *result_name; //반환할 이름

//데이터를 읽기위한 서브 함수
int myMoneySub(void *NotUsed, int argc, char **argv, char **azColName);
int readNameSub(void *NotUsed, int argc, char **argv, char **azColName);

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



char sql[100000] = "DROP TABLE IF EXISTS UserData;"
            "CREATE TABLE UserData(Id INT, Name TEXT, Pwd INT, Money INT);"; //계좌번호, 이름, 비밀번호, 돈

void createData(int id, char * name, int pwd, int money) //생성
{
    
    int rc = sqlite3_open("UserData.db", &db); //UserData 이름으로 데이터베이스 생성
    char str[10000];
    sprintf(str, "INSERT INTO UserData VALUES(%d, '%s', %d, %d);", id, name, pwd, money);
//    strcat(sql, str);

    rc = sqlite3_exec(db, str, 0, 0, &err_msg);
    
    sqlite3_close(db);
//    sub_main();
}

void allClear(void) //데이터 모두 지우기
{
    
    int rc = sqlite3_open("UserData.db", &db); //UserData 이름으로 데이터베이스 생성
    
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    sqlite3_close(db);
}

void setName(int id, char * name) //이름 수정 (수정)
{
    
    int rc = sqlite3_open("UserData.db", &db); //UserData 이름으로 데이터베이스 생성
    
    char str[10000];
    sprintf(str, "UPDATE UserData SET Name = '%s' where Id = %d;", name, id); //이름변경


    rc = sqlite3_exec(db, str, 0, 0, &err_msg);
 
    sqlite3_close(db);
}

void addMoney(int id, int nowMoney, int money) //돈 주기
{
    int rc = sqlite3_open("UserData.db", &db); //UserData 이름으로 데이터베이스 생성
    
    char str[10000];
    
    sprintf(str, "UPDATE UserData SET Money = %d where Id = %d;", nowMoney+money, id); //돈 변경

    rc = sqlite3_exec(db, str, 0, 0, &err_msg);
    
    sqlite3_close(db);
}

void reduceMoney(int id, int nowMoney, int money) //돈 주기
{
    int rc = sqlite3_open("UserData.db", &db); //UserData 이름으로 데이터베이스 생성
    
    char str[10000];
    
    sprintf(str, "UPDATE UserData SET Money = %d where Id = %d;", nowMoney-money, id); //돈 변경

    rc = sqlite3_exec(db, str, 0, 0, &err_msg);
    
    sqlite3_close(db);
    
}

void setMoney(int id, int money) //돈 설정
{
    
    int rc = sqlite3_open("UserData.db", &db); //UserData 이름으로 데이터베이스 생성
    
    char str[10000];
    sprintf(str, "UPDATE UserData SET money = %d where Id = %d;", money, id); //특정 돈으로 돈 설정

    rc = sqlite3_exec(db, str, 0, 0, &err_msg);
 
    sqlite3_close(db);
}

int myMoney(int id) //내돈 확인
{
    int rc = sqlite3_open("UserData.db", &db);
    
    char str[10000];
    
    sprintf(str, "SELECT * FROM UserData where id = %d", id);
    
    rc = sqlite3_exec(db, str, myMoneySub, 0, &err_msg);
    
    sqlite3_close(db);
    
    return result_money;
}

int myMoneySub(void *NotUsed, int argc, char **argv, char **azColName) //해당 id의 돈 리턴
{
    NotUsed = 0;
    
    //int to char
    int x;
    sscanf(argv[3], "%d", &x);
    result_money = x;
    
    return 0;
}


int readNameSub(void *NotUsed, int argc, char **argv, char **azColName)
{
    NotUsed = 0;
    result_name = argv[1];
    
    return 0;
}


char *readName(int id) //해당 id의 이름 리턴
{
    
    int rc = sqlite3_open("UserData.db", &db);
    
    char str[10000];
    char str1[10000];
    
    sprintf(str, "SELECT * FROM UserData where id = %d", id);
    
    rc = sqlite3_exec(db, str, readNameSub, 0, &err_msg);
    
    sqlite3_close(db);
    
    return result_name;
}


int readPwdSub(void *NotUsed, int argc, char **argv, char **azColName) //해당 id의 돈 리턴
{
    NotUsed = 0;
    
    //int to char
    int x;
    sscanf(argv[2], "%d", &x);
    result_pwd = x;
    return 0;
}

int readPwd(int id) //해당 id의 비밀번호 반환
{
    int rc = sqlite3_open("UserData.db", &db);
    
    char str[10000];
    
    sprintf(str, "SELECT * FROM UserData where id = %d", id);
    
    rc = sqlite3_exec(db, str, readPwdSub, 0, &err_msg);
    
    sqlite3_close(db);
    
    return result_pwd;
}

void setPwd(int id, int pwd) //돈 설정
{
    
    int rc = sqlite3_open("UserData.db", &db); //UserData 이름으로 데이터베이스 생성
    
    char str[10000];
    sprintf(str, "UPDATE UserData SET pwd = %d where Id = %d;", pwd, id); //특정 돈으로 돈 설정


    rc = sqlite3_exec(db, str, 0, 0, &err_msg);
 
    sqlite3_close(db);
}

int readIdSub(void *NotUsed, int argc, char **argv, char **azColName) //id sub
{
    NotUsed = 0;
    
    //int to char
    int x;
    sscanf(argv[0], "%d", &x);
    result_id = x;
    return 0;
}

int readId(char * name, int pwd) //해당 이름과 비밀번호로 id 반환
{
    int rc = sqlite3_open("UserData.db", &db);
    
    char str[10000];
    
    sprintf(str, "SELECT * FROM UserData where name = '%s' and pwd = %d", name, pwd);
    
    rc = sqlite3_exec(db, str, readIdSub, 0, &err_msg);
    
    sqlite3_close(db);
    
    return result_id;
}

void setId(char * name, int pwd, int id) //아이디 설정
{
    
    int rc = sqlite3_open("UserData.db", &db); //UserData 이름으로 데이터베이스 생성
    
    char str[10000];
    sprintf(str, "UPDATE UserData SET id = %d where pwd = %d and name = '%s';", id, pwd, name); //특정 돈으로 돈 설정


    rc = sqlite3_exec(db, str, 0, 0, &err_msg);
 
    sqlite3_close(db);
}
