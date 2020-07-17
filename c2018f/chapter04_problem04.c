/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: 10進制轉8進制 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main()
{
	int num;

	printf("Enter your number between 0 and 32767: ");
	scanf("%d", &num);     /* 輸入數值 */

	printf("In octal, your number is: %05o", num);     /* 輸出數值 */

	return 0;
}