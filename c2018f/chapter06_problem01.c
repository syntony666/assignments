/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.10.3 (put program development started date here) */
/* Purpose: ��J�Ʀr�D�̤j�� */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main() {

	double num;
	double temp = 0;

	for (;;) {
		printf("Enter a number: ");    /* ��J�Ʀr */
		scanf("%lf", &num);
		if (num == 0) {           /* �Y0�h���� */
			break;
		}

		if (num > temp) {          /* ��X�̤j�� */
			temp = num;
		}
	}

	printf("The largest number entered was %lf", temp);   /* ��X���� */
	
	return 0;
}