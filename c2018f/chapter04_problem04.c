/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: 10�i����8�i�� */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main()
{
	int num;

	printf("Enter your number between 0 and 32767: ");
	scanf("%d", &num);     /* ��J�ƭ� */

	printf("In octal, your number is: %05o", num);     /* ��X�ƭ� */

	return 0;
}