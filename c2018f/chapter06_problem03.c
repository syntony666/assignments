/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.10.3 (put program development started date here) */
/* Purpose: ���Ƭ��� */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main()
{
	int num1, num2, temp;

	printf("Enter a fraction: ");
	scanf("%d/%d", &num1, &num2);     /* ��J���� */

	temp = GCD(num1, num2);
	num1 /= temp;     /* ���� */
	num2 /= temp;

	if (num2 < 0)
	{
		num2 = -num2;
		num1 = -num1;
	}

	printf("in lowest terms: %d/%d", num1, num2);     /* ��X�ƭ� */

	return 0;
}

GCD(int a, int b) {       /* �̤j���]�� */
	int temp;
	while (a % b != 0) {
		
		temp = a % b;
		a = b;
		b = temp;

	}
	return b;
}