/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.09.12 */
/* Purpose: 多項式代入x求解 */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <math.h>

int main()
{
	float x, ans;
	
	printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6\nEnter the value of x: ");
	scanf("%f", &x);      /* 輸入x值 */

	ans = 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * x - 6;   /* 代入x */

	printf("the value of the polynomial: %f\n", ans);      /* 輸出答案 */
}