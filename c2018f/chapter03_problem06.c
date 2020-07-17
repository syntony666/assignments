/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: 分數運算 */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>

int main() {

	int a1, a2, b1, b2, r1, r2;

	printf("Enter two fractions seperated by a plus sign: ");

	scanf("%d/%d+%d/%d", &a1, &a2, &b1, &b2);	/* 輸入分數加法 */

	r1 = a1 * b2 + a2 * b1;	/* 分子計算 */
	r2 = a2 * b2;			/* 分母計算 */

	printf("The sum is %d/%d", r1, r2);		/* 結果輸出 */

	return 0;
}