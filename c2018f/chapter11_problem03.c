/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.11.6 */
/* Purpose: ���Ƭ���(�禡����) */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

void reduce(int *num1, int *num2);

int main()
{
	int num1, num2, temp;

	printf("Enter a fraction: ");
	scanf("%d/%d", &num1, &num2);     /* ��J���� */

	reduce(&num1, &num2);

	printf("in lowest terms: %d/%d", num1, num2);     /* ��X�ƭ� */

	return 0;
}

/* ���� */
void reduce(int *num1, int *num2) {
	int temp;
	int a = *num1;
	int b = *num2;

	while (a % b != 0) {       /* �̤j���]�� */

		temp = a % b;
		a = b;
		b = temp;

	}

	*num1 /= b;     /* ���� */
	*num2 /= b;

	if (*num2 < 0)     /* �ন���`�g�k */
	{
		*num2 = -*num2;
		*num1 = -*num1;
	}
}