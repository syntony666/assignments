/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.12.5 */
/* Purpose: �N�@�y�ܭ˹L�Ӽg */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>
#include<string.h>

#define MAX 100

int main() {

	char ch, ter = 0, str[MAX] = { 0 };
	char *last, *i, *j;

	printf("Enter a sentence: ");

	/* ��J�y�l */
	for (i = str; (ch = getchar()) != '\n'; i++) {
		if (ch == '.' || ch == '?' || ch == '!') {  /* �Y�J�쵲�������I�Ÿ�����Ū���y�l,�ïS�O�е������I�Ÿ� */
			last = i;
			ter = ch;
			break;
		}
		*i = ch;

	}

	printf("Reversal of sentence: ");

	/* ��X�ഫ��y�l */
	for (i = last; i >= str; i--) {     /* �q�᭱�}�lŪ�� */
		if (*i == ' ') {
			for (j = i + 1; j != last; j++) {  /* �Y�J��Ů�Y�i��X�r�� */

				putchar(*j);

			}

			last = i;
			putchar(*i);

		}
	}

	/* ��X�Ĥ@�ӳ�r */
	for (i = str; *i != ' '; i++) {
		putchar(*i);
	}

	printf("%c\n\n", ter);  /* ��X���I�Ÿ� */

	return 0;
}