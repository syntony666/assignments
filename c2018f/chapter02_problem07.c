/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.09.12 */
/* Purpose: �������D */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
	int amount, dol_20, dol_10, dol_5;

	printf("Enter a dollar amount: ");
	scanf("%d", &amount);	/* ��J���� */

	dol_20 = amount / 20;	/* 20���Ӽ� */
	amount %= 20;			/* �ѤU���� */

	dol_10 = amount / 10;	/* 10���Ӽ� */
	amount %= 10;			/* �ѤU���� */

	dol_5 = amount / 5;		/*  5���Ӽ� */
	amount %= 5;			/* �ѤU���� & 1���Ӽ� */

	printf("$20 Bills: %d\n", dol_20);		/* ��X20���Ӽ� */

	printf("$10 Bills: %d\n", dol_10);		/* ��X10���Ӽ� */

	printf("$5  Bills: %d\n", dol_5);		/* ��X5���Ӽ� */

	printf("$1  Bills: %d\n", amount);		/* ��X1���Ӽ� */
}