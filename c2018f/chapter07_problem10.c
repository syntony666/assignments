/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.10.7 */
/* Purpose: �D�X�y�l���������r�� */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main() {

	char ch;
	int i = 0;

	printf("Enter a sentence: ");

	/* ��J�C�Ӧr�����ˬd�O�_��a,e,i,o,u */
	while ((ch = getchar()) != '\n') {
		switch (ch)
		{
		case 'a':case 'e':case 'i':case 'o':case 'u':case 'A':case 'E':case 'I':case 'O':case 'U':
			i++;
		default:
			continue;
		}
	}

	printf("Your sentence contains %d vowels.", i);
	return 0;
}