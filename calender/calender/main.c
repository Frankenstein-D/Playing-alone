#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* �޷� �˻���
1. ����ڰ� �⵵�� �Է��ϸ� ������ �޷��� ����Ѵ�.
2. �� ��� 3���� ������ ����Ѵ�.  ex) 1, 2, 3�� ��� �� ���� �� 4, 5, 6�� ���... 10, 11, 12�� ���

< ���� >
- ���� 1�� 1�� ������
- ���� ���� ����   */

int inputYear();						// ���� �Է� 
bool isLeapyear(int year);				// ���� �Ǵ� �Լ�
int findFirstday(int year);				// ������ ������ 1�� 1���� �˷��ִ� �Լ�
void printCalender(int day, int year);	// �޷��� ����ϴ� �Լ�

int main() { 

	int year, day;

	year = inputYear();

	day = findFirstday(year);

	printCalender(day, year);

}

// ���� �Է� �Լ�
int inputYear() {
	int year;
	printf("����ϰ� ���� ������ �Է��ϼ��� : ");
	scanf_s("%d", &year);
	return year;
}

// ���� �Ǵ� �Լ�
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

// �ش� ������ 1�� 1���� ��ȯ�ϴ� �Լ�
int findFirstday(int year) {				
	int i, firstday, countLeapYear = 0;
	char date[3] = { 0 };
	bool bleapYear;

	bleapYear = bIsLeapyear(year);
	if (bleapYear == false)
		printf("���� : False\n");
	else
		printf("���� : True\n");

	for (i = 1; i < year; i++) {
		bleapYear = bIsLeapyear(i);
		if (bleapYear == true) {
			countLeapYear++;
		}
	}

	firstday = ((year - 1) + countLeapYear) % 7; // ù���� ���ۿ���

	switch (firstday)
	{
	case 0:
		printf("�ش� ���� 1�� 1���� �����Ϸ� �����մϴ�.\n");
		printf("\n");
		firstday = 2;
		break;
	case 1:
		printf("�ش� ���� 1�� 1���� ȭ���Ϸ� �����մϴ�.\n");
		printf("\n");
		firstday = 3;
		break;
	case 2:
		printf("�ش� ���� 1�� 1���� �����Ϸ� �����մϴ�.\n");
		printf("\n");
		firstday = 4;
		break;
	case 3:
		printf("�ش� ���� 1�� 1���� ����Ϸ� �����մϴ�.\n");
		printf("\n");
		firstday = 5;
		break;
	case 4:
		printf("�ش� ���� 1�� 1���� �ݿ��Ϸ� �����մϴ�.\n");
		printf("\n");
		firstday = 6;
		break;
	case 5:
		printf("�ش� ���� 1�� 1���� ����Ϸ� �����մϴ�.\n");
		printf("\n");
		firstday = 7;
		break;
	case 6:
		printf("�ش� ���� 1�� 1���� �Ͽ��Ϸ� �����մϴ�.\n");
		printf("\n");
		firstday = 1;
		break;
	}
	return firstday;
}

// ��� �Լ�
void printCalender(int day, int year) {
	int totalDate[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char date[7][4] = { {"Sun"},{"Mon"},{"Tue"},{"Wed"},{"Thu"},{"Fri"},{"Sat"} };
	char month[12][4] = { {"Jan"}, {"Feb"}, {"Mar"}, {"Apr"}, {"May"}, {"Jun"}, {"Jul"}, {"Aug"}, {"Sep"}, {"Oct"}, {"Nov"}, {"Dec"} };
	int i, k, l, m, n = 0; // �ݺ����� ����ϴ� ����
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
				
		printf("[%s] 			     ", month[i - 1]);  // �� ���

		if (i % 3 == 0)
		{
			printf("\n");
			for (l = 0; l < 3; l++)
			{
				for (k = 0; k < 7; k++)
				{
					printf("%s ", date[k]);				// ���� ���
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
				dateCount = totalDate[n]; // �Ѵ��� �� ����
								
				for (int x = 0; x < 42; x++)   // �� ���� 1�� ~ ���ϱ��� ��¥�� �ο�
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

				for (m = 1; m <= 7; m++)   // �� ���� ù �ָ� ���
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

				// �����޿� �����ϴ� ������ ����
				day = (dateCount + emptyDate) % 7 + 1; 
			}
			printf("\n");

			for (int i = 0; i < 5; i++) // �� ���� �ι�° �ֺ��� ���ϱ��� ���
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

