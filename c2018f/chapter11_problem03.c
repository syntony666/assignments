/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 琭翬 */
/* ID: 107820016 */
/* Date: 2018.11.6 */
/* Purpose: だ计だ(ㄧΑ夹) */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

void reduce(int *num1, int *num2);

int main()
{
	int num1, num2, temp;

	printf("Enter a fraction: ");
	scanf("%d/%d", &num1, &num2);     /* 块だ计 */

	reduce(&num1, &num2);

	printf("in lowest terms: %d/%d", num1, num2);     /* 块计 */

	return 0;
}

/* だ */
void reduce(int *num1, int *num2) {
	int temp;
	int a = *num1;
	int b = *num2;

	while (a % b != 0) {       /* 程そ计 */

		temp = a % b;
		a = b;
		b = temp;

	}

	*num1 /= b;     /* だ */
	*num2 /= b;

	if (*num2 < 0)     /* 锣Θタ盽糶猭 */
	{
		*num2 = -*num2;
		*num1 = -*num1;
	}
}