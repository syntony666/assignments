/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: �q�ܸ��X��J�ο�X */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main()
{
	int n1, n2, n3;

	printf("Enter phone number [(xxx) xxx-xxxx]: ");

	scanf("(%d) %d-%d", &n1, &n2, &n3);		/* ��J���X */

	printf("You entered %d.%d.%d", n1, n2, n3);		/* ��X���X */
}