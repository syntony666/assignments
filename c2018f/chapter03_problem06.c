/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: ���ƹB�� */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>

int main() {

	int a1, a2, b1, b2, r1, r2;

	printf("Enter two fractions seperated by a plus sign: ");

	scanf("%d/%d+%d/%d", &a1, &a2, &b1, &b2);	/* ��J���ƥ[�k */

	r1 = a1 * b2 + a2 * b1;	/* ���l�p�� */
	r2 = a2 * b2;			/* �����p�� */

	printf("The sum is %d/%d", r1, r2);		/* ���G��X */

	return 0;
}