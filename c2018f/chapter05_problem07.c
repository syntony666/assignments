/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.30 (put program development started date here) */
/* Purpose: 求出最大值及最小值 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main() {

	int a, b, c, d;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);       /* 輸入整數 */

	printf("Largest: %d\n", largest(a, b, c, d)); /* 輸出最大值 */

	printf("Smallest: %d", smallest(a, b, c, d)); /* 輸出最小值 */

	return 0;
}

int largest(int w, int x, int y, int z) {  /* 最大值求解 */
	int temp;

	if (w >= x) {           /* w,x比較 */
		temp = w;
	}
	else {
		temp = x;
	}

	if (y >= temp) {       /* y與前次較大者比較 */
		temp = y;
	}

	if (z >= temp) {      /* z與前次較大者比較 */
		temp = z;
	}
	return temp;
}

int smallest(int w, int x, int y, int z) {        /* 最大值求解 */
	int temp;
	if (w <= x) {           /* w,x比較 */
		temp = w;
	}
	else {
		temp = x;
	}
	if (y <= temp) {       /* y與前次較小者比較 */
		temp = y;
	}
	if (z <= temp) {       /* z與前次較小者比較 */
		temp = z;
	}
	return temp;
}