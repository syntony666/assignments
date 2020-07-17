/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.11.6 */
/* Purpose: �������D(�禡����) */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

void pay_amount(int amount, int *dol_20, int *dol_10, int *dol_5, int *dol_1);

int main() {
	int amount, dol_20, dol_10, dol_5, dol_1;

	printf("Enter a dollar amount: ");
	scanf("%d", &amount);   /* ��J���� */

	pay_amount(amount, &dol_20, &dol_10, &dol_5, &dol_1);

	printf("$20 Bills: %d\n", dol_20);	/* ��X20���Ӽ� */

	printf("$10 Bills: %d\n", dol_10);	/* ��X10���Ӽ� */

	printf("$5  Bills: %d\n", dol_5);	/* ��X5���Ӽ� */

	printf("$1  Bills: %d\n", dol_1);	/* ��X1���Ӽ� */
	
	
	return 0;
}

/* �p�⴫���� */
void pay_amount(int amount, int *dol_20, int *dol_10, int *dol_5, int *dol_1) {

	*dol_20 = amount / 20;	/* 20���Ӽ� */
	amount %= 20;			/* �ѤU���� */

	*dol_10 = amount / 10;	/* 10���Ӽ� */
	amount %= 10;			/* �ѤU���� */

	*dol_5 = amount / 5;	/*  5���Ӽ� */
	amount %= 5;			/* �ѤU���� */

	*dol_1 = amount;		/* 1���Ӽ� */
}