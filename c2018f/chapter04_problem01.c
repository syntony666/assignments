/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.28 (put program development started date here) */
/* Purpose: 數值翻轉 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main() {

	int n_1, n_10;
	
	printf("Enter a two-digit number: ");
	scanf("%1d%1d", &n_1, &n_10);     /* 輸入數值 */
	
	printf("The reversal is: %d%d", n_10, n_1);     /* 十位與個位互換及輸出 */
	
	return 0;
}