/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.10.8 */
/* Purpose: �H����J�^��r�� */
/* Change History: log the change history of the program */
/********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	char abc[10][10];
	
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			abc[i][j] = '.';
		}
	}

	abc[0][0] = 'A';


	int r[1000], k;

	srand(time(NULL));

	for (i = 0; i < 1000; i++) {  /* �s�@�H���Ʀr�}�C */
		r[i] = rand() % 4;
	}

	char ch;
	i = 0; j = 0; k = -1;

	for (ch = 'B'; ch <= 'Z'; ch++) {
	Alphabat:
		k++;
			switch (r[k])
			{
			case 1: /* �V�k */
				if (i + 1 < 10 && abc[i + 1][j] == '.') {
					i++;
				}
				else {
					goto Alphabat;
				}
				break;
			case 2: /* �V�� */
				if (i - 1 >= 0 && abc[i - 1][j] == '.') {
					i--;
				}
				else {
					goto Alphabat;
				}
				break;
			case 3: /* �V�U */
				if (j + 1 < 10 && abc[i][j + 1] == '.') {
					j++;
				}
				else {
					goto Alphabat;
				}
				break;
			case 0: /* �V�W */
				if (j - 1 >= 0 && abc[i][j - 1] == '.') {
					j--;
				}
				else {
					goto Alphabat;
				}
				break;
			}
			abc[i][j] = ch;
	}

	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%c ",abc[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}