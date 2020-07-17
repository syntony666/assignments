/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: §f¬fÂE */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.10.3 (put program development started date here) */
/* Purpose: ¼Æ¦r¶¶§ÇÄA­Ë */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>

int main() {
	int num;

	printf("Enter a number: ");
	scanf("%d", &num);           /* ¿é¤J¼Æ¦r */

	printf("The reversal is: ");

	/* ¶¶§ÇÄA­Ë */
	do
	{
		printf("%d", num % 10);
		num /= 10;
	} while (num != 0);

	return 0;
}