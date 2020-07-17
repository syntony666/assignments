/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.10.3 (put program development started date here) */
/* Purpose: 輸入數字求最大值 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main() {

	double num;
	double temp = 0;

	for (;;) {
		printf("Enter a number: ");    /* 輸入數字 */
		scanf("%lf", &num);
		if (num == 0) {           /* 若0則停止 */
			break;
		}

		if (num > temp) {          /* 找出最大值 */
			temp = num;
		}
	}

	printf("The largest number entered was %lf", temp);   /* 輸出答案 */
	
	return 0;
}