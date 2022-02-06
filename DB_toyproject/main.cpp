//debug, x64
#include <iostream>
#include <string>
#include <mysql.h>
#include <iomanip> //출력 정렬
#include <windows.h> //system("cls")
#include <conio.h>   //getch()

#pragma comment(lib, "libmySQL.lib")

#define DB_HOST "localhost" //외부에서 접소하고싶으면 컴터 켜놓고 포트열어놓고, 공인아이피
#define DB_USER "root"
#define DB_PASS "root"
#define DB_NAME "univdb"

MYSQL Conn; //mysql 정보를 담을 구조체
MYSQL* ConnPtr = NULL; //mysql 핸들
MYSQL_RES* Result; //쿼리성공식 결과를 담는 구조체 포인터
MYSQL_ROW Row; //쿼리성공시 결과로 나온 행의 정보를 담는 구조체

int bin;

int menu = 0; // 검색

//쿼리문
const char* Query = "SELECT * FROM 과목2;";							    //과목전체
const char* Monday = "select * from 과목2 where 요일검색 ='월요일';";    //월요일
const char* Tuesday = "select * from 과목2 where 요일검색 ='화요일';";   //화요일
const char* Wednesday = "select * from 과목2 where 요일검색 ='수요일';"; //수요일
const char* Thursday = "select * from 과목2 where 요일검색 ='목요일';";  //목요일
const char* Friday = "select * from 과목2 where 요일검색 ='금요일';";    //금요일

using namespace std;


int Print_menu() {
	int menu = 0;

	cout << "=====수강신청 검색 시스템======" << endl << endl;
	cout << "1. 전체 과목 조회" << endl;
	cout << "2. 과목 요일별 검색" << endl;
	cout << "3. 과목 정보" << endl;
	cout << "4. 종료" << endl << endl;
	cout << "=============================" << endl;
	cin >> menu;

	return menu;
}

void Print_all_subect() {
	int stat; //쿼리요청 후 결과 (성공, 실패)
	stat = mysql_query(ConnPtr, Query);
	if (stat != 0) {
		fprintf(stderr, "Mysql query error : %s\n", mysql_error(&Conn));
		return ;
	}

	Result = mysql_store_result(ConnPtr);			  // 결과 확인하기
	cout << "과목번호\t\t과목명\t   교수이름\t요일" << endl;
	cout << "====================================================================" << endl;
	while ((Row = mysql_fetch_row(Result)) != NULL) { // 결과 출력하기
		cout << Row[0] << "\t" << setw(25) << Row[1] << setw(10) << Row[2] << setw(10) << Row[3] << endl;
		cout << endl << endl;
	}
	mysql_free_result(Result);

	bin = _getch();
}

void Print_weekday() {
	int stat; //쿼리요청 후 결과 (성공, 실패)
	system("cls");
	int choice = 0;
	cout << "1. 월요일" << endl << "2. 화요일" << endl << "3. 수요일" << endl;
	cout << "4. 목요일" << endl << "5. 금요일" << endl;

	cin >> choice;
	system("cls");

	if (choice == 1) {
		stat = mysql_query(ConnPtr, Monday);
		if (stat != 0) {
			fprintf(stderr, "Mysql query error : %s\n", mysql_error(&Conn));
			return;
		}

		Result = mysql_store_result(ConnPtr);			  // 결과 확인하기
		cout << "과목번호\t\t과목명\t   교수이름\t요일" << endl;
		cout << "====================================================================" << endl;
		while ((Row = mysql_fetch_row(Result)) != NULL) { // 결과 출력하기
			cout << Row[0] << "\t" << setw(25) << Row[1] << setw(10) << Row[2] << setw(10) << Row[3] << endl;
			cout << endl << endl;
		}
		mysql_free_result(Result);
	}

	else if (choice == 2) {
		stat = mysql_query(ConnPtr, Tuesday);
		if (stat != 0) {
			fprintf(stderr, "Mysql query error : %s\n", mysql_error(&Conn));
			return;
		}

		Result = mysql_store_result(ConnPtr);			  // 결과 확인하기
		cout << "과목번호\t\t과목명\t   교수이름\t요일" << endl;
		cout << "====================================================================" << endl;
		while ((Row = mysql_fetch_row(Result)) != NULL) { // 결과 출력하기
			cout << Row[0] << "\t" << setw(25) << Row[1] << setw(10) << Row[2] << setw(10) << Row[3] << endl;
			cout << endl << endl;
		}
		mysql_free_result(Result);
	}

	else if (choice == 3) {
		stat = mysql_query(ConnPtr, Wednesday);
		if (stat != 0) {
			fprintf(stderr, "Mysql query error : %s\n", mysql_error(&Conn));
			return;
		}

		Result = mysql_store_result(ConnPtr);			  // 결과 확인하기
		cout << "과목번호\t\t과목명\t   교수이름\t요일" << endl;
		cout << "====================================================================" << endl;
		while ((Row = mysql_fetch_row(Result)) != NULL) { // 결과 출력하기
			cout << Row[0] << "\t" << setw(25) << Row[1] << setw(10) << Row[2] << setw(10) << Row[3] << endl;
			cout << endl << endl;
		}
		mysql_free_result(Result);
	}

	else if (choice == 4) {
		stat = mysql_query(ConnPtr, Thursday);
		if (stat != 0) {
			fprintf(stderr, "Mysql query error : %s\n", mysql_error(&Conn));
			return;
		}

		Result = mysql_store_result(ConnPtr);			  // 결과 확인하기
		cout << "과목번호\t\t과목명\t   교수이름\t요일" << endl;
		cout << "====================================================================" << endl;
		while ((Row = mysql_fetch_row(Result)) != NULL) { // 결과 출력하기
			cout << Row[0] << "\t" << setw(25) << Row[1] << setw(10) << Row[2] << setw(10) << Row[3] << endl;
			cout << endl << endl;
		}
		mysql_free_result(Result);
	}

	else if (choice == 5) {
		stat = mysql_query(ConnPtr, Friday);
		if (stat != 0) {
			fprintf(stderr, "Mysql query error : %s\n", mysql_error(&Conn));
			return;
		}

		Result = mysql_store_result(ConnPtr);			  // 결과 확인하기
		cout << "과목번호\t\t과목명\t   교수이름\t요일" << endl;
		cout << "====================================================================" << endl;
		while ((Row = mysql_fetch_row(Result)) != NULL) { // 결과 출력하기
			cout << Row[0] << "\t" << setw(25) << Row[1] << setw(10) << Row[2] << setw(10) << Row[3] << endl;
			cout << endl << endl;
		}
		mysql_free_result(Result);
	}

	bin = _getch();
}

void Subject_information() {
	int stat; //쿼리요청 후 결과 (성공, 실패)
	stat = mysql_query(ConnPtr, Query);
	if (stat != 0) {
		fprintf(stderr, "Mysql query error : %s\n", mysql_error(&Conn));
		return;
	}

	Result = mysql_store_result(ConnPtr);			  // 결과 확인하기
	cout << "과목번호\t\t과목명\t   교수이름\t요일" << endl;
	cout << "====================================================================" << endl;
	while ((Row = mysql_fetch_row(Result)) != NULL) { // 결과 출력하기
		cout << Row[0] << "\t" << setw(25) << Row[1] << setw(10) << Row[2] << setw(10) << Row[3] << endl;
		cout << endl << endl;
	}

	mysql_free_result(Result);

	cout << endl;

	int number;
	cin >> number;
	system("cls");
	stat = mysql_query(ConnPtr, Query);
	Result = mysql_store_result(ConnPtr);
	for (int i = 1; i <= 16; i++) {
		Row = mysql_fetch_row(Result);
		if (number == i) {
			cout << "과목번호\t\t과목명\t   교수이름\t요일\t   시수\t\t선행과목\t학생의견" << endl;
			cout << "===========================================================================================================" << endl;
			cout << Row[0] << "\t" << setw(25) << Row[1] << setw(10) << Row[2] << setw(10) << Row[3] << setw(10) << Row[4]<< "\t\t" << Row[5]<< "\t" << setw(25) << Row[6] << endl;
			cout << endl << endl;
			continue;
		}
	}
	bin = _getch();
}

int main() {


	mysql_init(&Conn);		//Mysql 정보 초기화

	// 데이터베이스와 연결
	ConnPtr = mysql_real_connect(&Conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
	mysql_query(ConnPtr, "set session character_set_connection=euckr;");
	mysql_query(ConnPtr, "set session character_set_results=euckr;");
	mysql_query(ConnPtr, "set session character_set_client=euckr;");

	//연결 결과 확인. NULL일 경우 연결실패한것.
	if (ConnPtr == NULL) {
		fprintf(stderr, "Mysql connection error : %s", mysql_error(&Conn));
		return 1;
	}


	while (1) {
		system("cls");
		int menu_choice;

		menu_choice = Print_menu();

		if (menu_choice == 1) //전체과목
		{
			Print_all_subect();
		}
		else if (menu_choice == 2) //요일 검색
		{
			Print_weekday();
		}
		else if (menu_choice == 3) //과목 정보
		{
			Subject_information();
		}

		else if (menu_choice == 4)
		{
			break;
		}
	
	}

	// 데이터베이스와 연결해제
	mysql_close(ConnPtr);


	return 0;
}