/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.30 (put program development started date here) */
/* Purpose: �D�X�̤j�Ȥγ̤p�� */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main() {

	int a, b, c, d;

	printf("Enter four integers: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);       /* ��J��� */

	printf("Largest: %d\n", largest(a, b, c, d)); /* ��X�̤j�� */

	printf("Smallest: %d", smallest(a, b, c, d)); /* ��X�̤p�� */

	return 0;
}

int largest(int w, int x, int y, int z) {  /* �̤j�ȨD�� */
	int temp;

	if (w >= x) {           /* w,x��� */
		temp = w;
	}
	else {
		temp = x;
	}

	if (y >= temp) {       /* y�P�e�����j�̤�� */
		temp = y;
	}

	if (z >= temp) {      /* z�P�e�����j�̤�� */
		temp = z;
	}
	return temp;
}

int smallest(int w, int x, int y, int z) {        /* �̤j�ȨD�� */
	int temp;
	if (w <= x) {           /* w,x��� */
		temp = w;
	}
	else {
		temp = x;
	}
	if (y <= temp) {       /* y�P�e�����p�̤�� */
		temp = y;
	}
	if (z <= temp) {       /* z�P�e�����p�̤�� */
		temp = z;
	}
	return temp;
}