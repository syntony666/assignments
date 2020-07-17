/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: �̪�ɨ��(�禡���c) */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

#define MAX 15

int calculate_minutes(int h, int m);
int calculate_nearest_flight(struct time *transportation, int h, int m);

struct time {
	int minutes;		/* �ɨ������� */
	char depart[MAX];	/* ��F�ɶ� */
	char arrive[MAX];	/* �X�o�ɶ� */
};

int main()
{
	/* �إ߮ɨ�� */
	struct time flight[8] = {
		{ calculate_minutes(8, 0),	"8:00 a.m.",	"10:16 a.m."},
		{ calculate_minutes(9, 43),	"9:43 a.m.",	"11:52 a.m."},
		{ calculate_minutes(11, 19),"11:19 a.m.",	"1:31 p.m."	},
		{ calculate_minutes(12, 47),"12:47 p.m.",	"3:00 p.m."	},
		{ calculate_minutes(14, 0),	"2:00 p.m.",	"4:08 p.m."	},
		{ calculate_minutes(15, 45),"3:45 p.m.",	"5:55 p.m."	},
		{ calculate_minutes(19, 0),	"7:00 p.m.",	"9:20 p.m."	},
		{ calculate_minutes(21, 45),"9:45 p.m.",	"11:58 p.m."},

	};

	int hh, mm;

	/* ��J�ɶ� */
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hh, &mm);

	/* �p��̪�ɶ� */
	int i = calculate_nearest_flight(&flight, hh, mm);

	/* ��X�ɶ��� */
	printf("Closest departure time is %s, arriving at %s", flight[i].depart, flight[i].arrive);

	return 0;
}

/* �p��ɶ������� */
int calculate_minutes(int h, int m) {
	return h * 60 + m;
}

/* �p��̪�ɶ� */
int calculate_nearest_flight(struct time *transportation, int h, int m) {

	int i;

	/* �Y�ɶ���Ĥ@�Z��, �h�ϥβĤ@�Z */
	if (calculate_minutes(h, m) <= transportation[1].minutes) {
		return 0;
	}

	for (i = 0; i < 7; i++) {
		if (calculate_minutes(h, m) >= transportation[i].minutes && calculate_minutes(h, m) <= transportation[i + 1].minutes) {
			if (calculate_minutes(h, m) - transportation[i].minutes >= transportation[i + 1].minutes - calculate_minutes(h, m)) {
				i = i + 1;
			}
			break;
		}
	}
	return i;
}
