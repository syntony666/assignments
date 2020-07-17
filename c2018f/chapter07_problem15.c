/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.10.22 */
/* Purpose: �ζ��������O��� */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main() {

	int num;

	printf("Please enter a number: "); /* ��J�ƭ� */
	scanf("%d", &num);

	/* �p��short���� */
	short ans_s = (short)num, s;
	for (s = ans_s - 1; s > 1; s--) {
		ans_s *= s;
	}

	/* �p��int���� */
	int ans_i = (int)num, i;
	for (i = ans_i - 1; i > 1; i--) {
		ans_i *= i;
	}

	/* �p��long���� */
	long ans_l = (long)num, l;
	for (l = ans_l - 1; l > 1; l--) {
		ans_l *= l;
	}

	/* �p��long long���� */
	long long ans_ll = (long long)num, ll;
	for (ll = ans_ll - 1; ll > 1; ll--) {
		ans_ll *= ll;
	}

	/* �p��float���� */
	float ans_f = (float)num, f;
	for (f = ans_f - 1.0f; f > 1.0f; f--) {
		ans_f *= f;
	}

	/* �p��double���� */
	double ans_d = (double)num, d;
	for (d = ans_d - 1; d > 1; d--) {
		ans_d *= d;
	}

	/* �p��long double���� */
	long double ans_ld = (long double)num, ld;
	for (ld = ans_ld - 1; ld > 1; ld--) {
		ans_ld *= ld;
	}

	/* ��X�ƭ� */
	printf("Factorial of %d (short int): %u\n",num , ans_s);
	printf("Factorial of %d (int): %d\n", num, ans_i);
	printf("Factorial of %d (long int): %ld\n", num, ans_l);
	printf("Factorial of %d (long long int): %lld\n", num, ans_ll);
	printf("Factorial of %d (float): %f\n", num, ans_f);
	printf("Factorial of %d (double float): %lf\n", num, ans_d);
	printf("Factorial of %d (long double float): %Lf\n", num, ans_ld);

	return 0;
}