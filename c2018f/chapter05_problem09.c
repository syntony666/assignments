/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.30 (put program development started date here) */
/* Purpose: ������ */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>

int main() {
	int yy[2], mm[2], dd[2], i;
	for (i = 0; i < 2; i++) {                           /* ��J����j�� */
		if (i == 0) {
			printf("Enter first date (mm/dd/yy): ");        /* ��J���1 */
		}
		else {
			printf("Enter second date (mm/dd/yy): ");       /* ��J���2 */
		}
		scanf("%d/%d/%d", &mm[i], &dd[i], &yy[i]);
	}


	int j = 0;                  /* j�������ɶ� */
	int k = 1;                  /* k�����߮ɶ� */

	if (yy[0] == yy[1]) {
		if (mm[0] == mm[1]) {
			if (dd[1] < dd[0]) {
				j = 1; k = 0;
			}
		}
		else {
			if (mm[1] < mm[0]) {
				j = 1; k = 0;
			}
		}
	}

	else {
		if (yy[1] < yy[0]) {
			j = 1; k = 0;
		}
	}
	

	printf("%d/%d/%d is earier than %d/%d/%d", mm[j], dd[j], yy[j], mm[k], dd[k], yy[k]);
	/* ��X���G */
}