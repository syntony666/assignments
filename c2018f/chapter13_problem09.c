/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.12.9 */
/* Purpose: �D�X�y�l���������r�� */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int compute_vowel_count(char *ch);

int main() {

	char ch;

	printf("Enter a sentence: ");

	int i = compute_vowel_count(&ch);

	printf("Your sentence contains %d vowels.", i);
	return 0;
}

/* ��J�C�Ӧr�����ˬd�O�_��a,e,i,o,u */
int compute_vowel_count(char *ch) {
	int i = 0;
	while ((*ch = getchar()) != '\n') {
		switch (*ch)
		{
		case 'a':case 'e':case 'i':case 'o':case 'u':case 'A':case 'E':case 'I':case 'O':case 'U':
			i++;
		default:
			continue;
		}
	}
	return i;
}