/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.10.17 */
/* Purpose: ��ܱƧǪk */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

void selection_sort(int a[], int n);

int main() {

	int i, num[1000];

	/* ��J�Ʀr */
	printf("The number sorting (Press 0 to stop)\n");
	for (i = 0;; i++) {
		printf("Enter a number %d: ", i);
		scanf("%d", &num[i]);
		if (num[i] == 0)
			break;
	}
	i--;   /* ��0�c�� */

	int size_num = i;

	selection_sort(num, i);  /* �ƧǪk */

	/* ��X���G */
	printf("Sorted: ");
	for (i = 0; i <= size_num; i++) {
		printf("%d ", num[i]);
	}
	
	return 0;
}

/* ��ܱƧǪk */
void selection_sort(int a[], int n) {
	int i, temp;

	if (n == 0)  /* �Y�n�ƧǪ��ƶq��0, �h���� */
		return;

	int max = 0;
	for (i = 1; i <= n; i++) {		/* ����j�p */
		if (a[i] > a[max]) {
			max = i;
		}
	}

	if (max != n) {    /* ���᭱ */
		i = a[max];
		a[max] = a[n];
		a[n] = i;
	}

	selection_sort(a, n - 1);
}