/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.10.7 */
/* Purpose: 姓名轉換 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>
#include<string.h>

int main() {

	char fn[256], ln[256];

	/* 輸入姓名 */
	printf("Enter a first name and last name: ");
	scanf("%s", fn);
	scanf("%s", ln);

	/* 輸出姓名 */
	printf("%s, %c.", ln, fn[0]);
}