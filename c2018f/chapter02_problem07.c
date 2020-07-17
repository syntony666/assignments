/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.09.12 */
/* Purpose: 錢幣問題 */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
	int amount, dol_20, dol_10, dol_5;

	printf("Enter a dollar amount: ");
	scanf("%d", &amount);	/* 輸入錢數 */

	dol_20 = amount / 20;	/* 20元個數 */
	amount %= 20;			/* 剩下的錢 */

	dol_10 = amount / 10;	/* 10元個數 */
	amount %= 10;			/* 剩下的錢 */

	dol_5 = amount / 5;		/*  5元個數 */
	amount %= 5;			/* 剩下的錢 & 1元個數 */

	printf("$20 Bills: %d\n", dol_20);		/* 輸出20元個數 */

	printf("$10 Bills: %d\n", dol_10);		/* 輸出10元個數 */

	printf("$5  Bills: %d\n", dol_5);		/* 輸出5元個數 */

	printf("$1  Bills: %d\n", amount);		/* 輸出1元個數 */
}