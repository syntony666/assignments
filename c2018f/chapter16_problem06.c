/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.12.1 */
/* Purpose: ������ */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>

struct date
{
	int year, month, day;
};

int compare_date(struct date d1, struct date d2);
void output(struct date d1, struct date d2);
void comparing(int i, struct date d1, struct date d2);

int main() {

	struct date date_1, date_2;
	
	printf("Enter first date (mm/dd/yy): ");			/* ��J���1 */
	scanf("%d/%d/%d", &date_1.month, &date_1.day, &date_1.year);

	printf("Enter second date (mm/dd/yy): ");			/* ��J���2 */
	scanf("%d/%d/%d", &date_2.month, &date_2.day, &date_2.year);

	comparing(compare_date(date_1, date_2), date_1, date_2);

	return 0;
}


/* ���������ᶶ�� */
int compare_date(struct date d1, struct date d2) {

	if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day) {
		return 0;
	}

	else if (d1.year == d2.year && d1.month == d2.month && d1.day < d2.day) {
		return 1;
	}

	else if (d1.year == d2.year && d1.month < d2.month) {
		return 1;
	}

	else if (d1.year < d2.year) {
		return 1;
	}

	else {
		return -1;
	}
}


/* �Ncompare_date�����G��X */
void comparing(int i, struct date d1, struct date d2) {
	switch (i)
	{
	case 1:
		output(d1, d2);	break;
	case -1:
		output(d2, d1);	break;
	default:
		printf("Both dates are the same");	break;
	}
}


/* ��X, �ѩ�L��, �]�Ӱ����禡�W�[�iŪ�� */
void output(struct date d1, struct date d2) {
	printf("%d/%d/%d is earier than %d/%d/%d", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
}