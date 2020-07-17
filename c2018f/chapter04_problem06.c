/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: 檢查碼計算 */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>

int main() {

	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, temp1, temp2;

	printf("Enter the first 12 digit of an EAN: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);
	/* 輸入12位數值 */

	temp1 = n2 + n4 + n6 + n8 + n10 + n12;
	temp2 = n1 + n3 + n5 + n7 + n9 + n11;
	temp1 = 9-( (temp1 * 3 + temp2 - 1) % 10 );    /* 檢查碼計算 */


	printf("Check digit: %d", temp1);       /* 輸出檢查碼 */
}