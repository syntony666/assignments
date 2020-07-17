/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: �̪�ɨ�� */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main()
{
	int hh, mm, now_t;

	/* ��J�ɶ� */
	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hh, &mm);


	/* �ثe�ɶ������� */
	now_t = hh * 60 + mm;   

	/* �ɨ������� */
	int t[8] = { 480, 583, 679, 767, 840, 945, 1140, 1305 };

	/* ��F�ɶ��ΥX�o�ɶ� */
	char *tt[2][8] = { {"8:00 a.m.","9:43 a.m.","11:19 a.m.","12:47 p.m.","2:00 p.m.","3:45 p.m.","7:00 p.m.","9:45 p.m."}, {"10:16 a.m.","11:52 a.m.","1:31 p.m.","3:00 p.m.","4:08 p.m.","5:55 p.m.","9:20 p.m.","11:58 p.m."} };
	
	int i;

	/* �p��̪�ɶ� */
	for (i = 0; i < 7; i++) {
		if (now_t >= t[i] && now_t <= t[i + 1]) {
			if (now_t - t[i] >= t[i + 1] - now_t) {
				i = i + 1;
			}
			break;
		}
	}

	/* ��X�ɶ��� */
	printf("Closest departure time is %s, arriving at %s", tt[0][i], tt[1][i]);

	return 0;
}
