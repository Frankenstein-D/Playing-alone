#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* 달력 검색기
1. 사용자가 년도를 입력하면 그해의 달력을 출력한다.
2. 한 행당 3개월 단위로 출력한다.  ex) 1, 2, 3월 출력 후 다음 줄 4, 5, 6월 출력... 10, 11, 12월 출력

< 참고 >
- 서기 1월 1일 월요일
- 윤년 계산법 적용   */

int inputYear();						// 연도 입력 
bool isLeapyear(int year);				// 윤년 판단 함수
int findFirstday(int year);				// 선택한 연도의 1월 1일을 알려주는 함수
void printCalender(int day, int year);	// 달력을 출력하는 함수

int main() { 

	int year, day;

	year = inputYear();

	day = findFirstday(year);

	printCalender(day, year);

}

// 연도 입력 함수
int inputYear() {
	int year;
	printf("출력하고 싶은 연도를 입력하세요 : ");
	scanf_s("%d", &year);
	return year;
}

// 윤년 판단 함수
bool bIsLeapyear(int year) {
	if ((year % 100 == 0) != (year % 400 == 0)) {
		return false;
	}
	else if ((year % 4 == 0) && (year % 400 == 0)) {
		return true;
	}
	else if ((year % 4 == 0) != (year % 100 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

// 해당 연도의 1월 1일을 반환하는 함수
int findFirstday(int year) {				
	int i, firstday, countLeapYear = 0;
	char date[3] = { 0 };
	bool bleapYear;

	bleapYear = bIsLeapyear(year);
	if (bleapYear == false)
		printf("윤년 : False\n");
	else
		printf("윤년 : True\n");

	for (i = 1; i < year; i++) {
		bleapYear = bIsLeapyear(i);
		if (bleapYear == true) {
			countLeapYear++;
		}
	}

	firstday = ((year - 1) + countLeapYear) % 7; // 첫해의 시작요일

	switch (firstday)
	{
	case 0:
		printf("해당 연도 1월 1월은 월요일로 시작합니다.\n");
		printf("\n");
		firstday = 2;
		break;
	case 1:
		printf("해당 연도 1월 1월은 화요일로 시작합니다.\n");
		printf("\n");
		firstday = 3;
		break;
	case 2:
		printf("해당 연도 1월 1월은 수요일로 시작합니다.\n");
		printf("\n");
		firstday = 4;
		break;
	case 3:
		printf("해당 연도 1월 1월은 목요일로 시작합니다.\n");
		printf("\n");
		firstday = 5;
		break;
	case 4:
		printf("해당 연도 1월 1월은 금요일로 시작합니다.\n");
		printf("\n");
		firstday = 6;
		break;
	case 5:
		printf("해당 연도 1월 1월은 토요일로 시작합니다.\n");
		printf("\n");
		firstday = 7;
		break;
	case 6:
		printf("해당 연도 1월 1월은 일요일로 시작합니다.\n");
		printf("\n");
		firstday = 1;
		break;
	}
	return firstday;
}

// 출력 함수
void printCalender(int day, int year) {
	int totalDate[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char date[7][4] = { {"Sun"},{"Mon"},{"Tue"},{"Wed"},{"Thu"},{"Fri"},{"Sat"} };
	char month[12][4] = { {"Jan"}, {"Feb"}, {"Mar"}, {"Apr"}, {"May"}, {"Jun"}, {"Jul"}, {"Aug"}, {"Sep"}, {"Oct"}, {"Nov"}, {"Dec"} };
	int i, k, l, m, n = 0; // 반복문에 사용하는 변수
	int dateCount = 0;
	int monthCount = 0;
	bool bleapYear;

	bleapYear = bIsLeapyear(year);
	if (bleapYear == false)
	{
		totalDate[1] = 28;
	}
	else
	{
		totalDate[1] = 29;
	}

	printf("=====================================================================================\n");
	printf("			              [%d] year\n", year);
	printf("=====================================================================================\n");

	for (i = 1; i <= 12; i++) {

		if (i % 3 == 0)
		{
			printf("\b\b\b");
		}
				
		printf("[%s] 			     ", month[i - 1]);  // 월 출력

		if (i % 3 == 0)
		{
			printf("\n");
			for (l = 0; l < 3; l++)
			{
				for (k = 0; k < 7; k++)
				{
					printf("%s ", date[k]);				// 요일 출력
				}
				printf(" ");
			}
			printf("\n");

			for (m = 0; m < 3; m++)
			{
				printf("===========================  ");
			}
			printf("\n");

			int nextDate[3];
			char deliveryMonth[12][42];
			int emptyMonth[42] = { 0 };

			for (int z = 0; z < 3; z++)
			{
				printf("\b");
				dateCount = totalDate[n]; // 한달의 총 날수
								
				for (int x = 0; x < 42; x++)   // 각 월에 1일 ~ 말일까지 날짜를 부여
				{
					if (x < dateCount)
					{
						emptyMonth[x] = x + 1;
						deliveryMonth[n][x] = emptyMonth[x];
					}
					else if (dateCount <= x)
					{
						deliveryMonth[n][x] = 0;
					}
				}
				n++;

				int emptyDate = 0;
				int dateStart = 0;
				int x = 0;
				int y = 0;

				for (m = 1; m <= 7; m++)   // 각 월의 첫 주를 출력
				{
					if (day > m)
					{
						printf("    ");
						emptyDate++;
					}
					else
					{
						printf("%3d ", emptyMonth[dateStart]);   
						dateStart++;
						if (m == 7)
						{
							printf("  ");
						}
					}
				}

				nextDate[z] = dateStart;

				// 다음달에 시작하는 요일을 전달
				day = (dateCount + emptyDate) % 7 + 1; 
			}
			printf("\n");

			for (int i = 0; i < 5; i++) // 각 월의 두번째 주부터 말일까지 출력
			{
				printf("\b");
				for (int j = 0; j < 3; j++)
				{
					int beforeSat = nextDate[j];
					for (int k = 0; k < 7; k++)
					{
						if (deliveryMonth[monthCount + j][beforeSat] == 0)
						{
							printf("    ");
						}
						else
						{
							printf("%3d ", deliveryMonth[monthCount + j][beforeSat]);
							++beforeSat;
						}
					}
					printf(" ");
					nextDate[j] = beforeSat;
				}
				printf("\n");
			}
			printf("\n");
			monthCount += 3;
		}
	}
}

