/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.10.3 (put program development started date here) */
/* Purpose: �Ʀr�����A�� */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>

int main() {
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);           /* ��J�Ʀr */

	printf("The reversal is: ");

	/* �����A�� */
	do
	{
		printf("%d", num % 10);
		num /= 10;
	} while (num != 0);

	return 0;
}