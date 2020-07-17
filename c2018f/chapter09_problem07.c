/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.11.4 */
/* Purpose: 指數函式 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int power(int x, int n);

int main() {

	int x, n, result;

	/* 輸入數字 */
	printf("Calculate x^n\nx: ");
	scanf("%d", &x);
	printf("n: ");
	scanf("%d", &n);

	result = power(x, n); /* 計算答案 */

	printf("The answer of %d^%d is %d", x, n, result);  /* 輸出答案 */
	
	return 0;
}

/* 計算指數 */
int power(int x, int n) {
	int temp;

	if (n == 1) {  /* 若次方為1, 輸出答案 */
		return x;
	}

	if (n % 2 == 0) {   /* 若次方為偶數, 使該數平方 */
		x *= x;
		n/=2;
		power(x, n);
	}
	else {      /* 若次方數為奇數, 使其變成x*x^(n-1) */
		n--;
		temp = power(x, n);
		x *= temp;
		return x;
	}
}