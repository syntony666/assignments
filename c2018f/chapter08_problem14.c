/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.10.22 */
/* Purpose: �N�@�y�ܭ˹L�Ӽg */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>
#include<string.h>

int main() {

	char ch, ter = 0, str[1000];
	int last;

	int i;

	printf("Enter a sentence: ");

	/* ��J�y�l */
	for (i = 0; (ch = getchar()) != '\n'; i++) {
		if (ch == '.' || ch == '?' || ch == '!') {  /* �Y�J�쵲�������I�Ÿ�����Ū���y�l,�ïS�O�е������I�Ÿ� */
			last = i;
			ter = ch;
			break;
		}
		str[i] = ch;
		
	}

	printf("Reversal of sentence: ");

	int j;

	/* ��X�ഫ��y�l */
	for (i = last; i >= 0; i--) {     /* �q�᭱�}�lŪ�� */
		if (str[i] == ' ') {
			for (j = i + 1; j != last; j++) {  /* �Y�J��Ů�Y�i��X�r�� */

				putchar(str[j]);

			}

			last = i;
			putchar(str[i]);

		}
	}

	/* ��X�Ĥ@�ӳ�r */
	for (i = 0; str[i] != ' '; i++) {
		putchar(str[i]);
	}
	
	printf("%c\n\n", ter);  /* ��X���I�Ÿ� */
	
	return 0;
}