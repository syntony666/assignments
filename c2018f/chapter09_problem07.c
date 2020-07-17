/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.11.4 */
/* Purpose: ���ƨ禡 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int power(int x, int n);

int main() {

	int x, n, result;

	/* ��J�Ʀr */
	printf("Calculate x^n\nx: ");
	scanf("%d", &x);
	printf("n: ");
	scanf("%d", &n);

	result = power(x, n); /* �p�⵪�� */

	printf("The answer of %d^%d is %d", x, n, result);  /* ��X���� */
	
	return 0;
}

/* �p����� */
int power(int x, int n) {
	int temp;

	if (n == 1) {  /* �Y���謰1, ��X���� */
		return x;
	}

	if (n % 2 == 0) {   /* �Y���謰����, �ϸӼƥ��� */
		x *= x;
		n/=2;
		power(x, n);
	}
	else {      /* �Y����Ƭ��_��, �Ϩ��ܦ�x*x^(n-1) */
		n--;
		temp = power(x, n);
		x *= temp;
		return x;
	}
}