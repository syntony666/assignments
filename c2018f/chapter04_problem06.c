/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 (your student ID here) */
/* Date: 2018.09.26 (put program development started date here) */
/* Purpose: �ˬd�X�p�� */
/* Change History: log the change history of the program */
/********************************************************************/

#include<stdio.h>

int main() {

	int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, temp1, temp2;

	printf("Enter the first 12 digit of an EAN: ");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10, &n11, &n12);
	/* ��J12��ƭ� */

	temp1 = n2 + n4 + n6 + n8 + n10 + n12;
	temp2 = n1 + n3 + n5 + n7 + n9 + n11;
	temp1 = 9-( (temp1 * 3 + temp2 - 1) % 10 );    /* �ˬd�X�p�� */


	printf("Check digit: %d", temp1);       /* ��X�ˬd�X */
}