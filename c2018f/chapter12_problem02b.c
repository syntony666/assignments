/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.12.5 */
/* Purpose: �q�e�ܫ�Ū���T�{�O�_�P�ϦV�ۦP */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>
#include <ctype.h>

#define BUFF 50

int main()
{
	char ch, msg[BUFF];
	char *i, *j;

	/* ��J�y�l */
	printf("Enter a sentence: ");

	/* Ū���O�r�����r�� */
	for (i = &msg[0]; (ch = tolower(getchar())) != '\n'; i++){
		if (isalpha(ch)) *i = ch;
	}

	/* �ˬd */
		for (j = i - 1, i = &msg[0]; j >= &msg[0]; i++)
	{
		if (*i == 0) break;
		if (*i != *j)
		{
			printf("Not a palindrome");
			return 0;
		}
		j--;
	}
	printf("Palindrome");

}