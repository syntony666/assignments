
/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.11.4 */
/* Purpose: �H���Ƨǭ^��r��(�禡��) */
/* Change History: log the change history of the program */
/********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_radom_walk(char walk[10][10]);
void print_array(char walk[10][10]);

int main() {

	char walk[10][10];

	generate_radom_walk(walk);   /* �ഫ�X���G */
	print_array(walk);     /* �L�X���G */
	
	return 0;
}

/* �ഫ�X���G */
void generate_radom_walk(char walk[10][10]) {

	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			walk[i][j] = '.';
		}
	}

	walk[0][0] = 'A';


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
			if (i + 1 < 10 && walk[i + 1][j] == '.') {
				i++;
			}
			else {
				goto Alphabat;
			}
			break;
		case 2: /* �V�� */
			if (i - 1 >= 0 && walk[i - 1][j] == '.') {
				i--;
			}
			else {
				goto Alphabat;
			}
			break;
		case 3: /* �V�U */
			if (j + 1 < 10 && walk[i][j + 1] == '.') {
				j++;
			}
			else {
				goto Alphabat;
			}
			break;
		case 0: /* �V�W */
			if (j - 1 >= 0 && walk[i][j - 1] == '.') {
				j--;
			}
			else {
				goto Alphabat;
			}
			break;
		}
		walk[i][j] = ch;
	}
}

/* �L�X���G */
void print_array(char walk[10][10]) {

	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%c ", walk[i][j]);
		}
		printf("\n");
	}

}