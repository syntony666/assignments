/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.10.7 */
/* Purpose: �m�W�ഫ */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>
#include<string.h>

int main() {

	char fn[256], ln[256];

	/* ��J�m�W */
	printf("Enter a first name and last name: ");
	scanf("%s", fn);
	scanf("%s", ln);

	/* ��X�m�W */
	printf("%s, %c.", ln, fn[0]);
}