/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.10.17 */
/* Purpose: 選擇排序法 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

void selection_sort(int a[], int n);

int main() {

	int i, num[1000];

	/* 輸入數字 */
	printf("The number sorting (Press 0 to stop)\n");
	for (i = 0;; i++) {
		printf("Enter a number %d: ", i);
		scanf("%d", &num[i]);
		if (num[i] == 0)
			break;
	}
	i--;   /* 把0剃除 */

	int size_num = i;

	selection_sort(num, i);  /* 排序法 */

	/* 輸出結果 */
	printf("Sorted: ");
	for (i = 0; i <= size_num; i++) {
		printf("%d ", num[i]);
	}
	
	return 0;
}

/* 選擇排序法 */
void selection_sort(int a[], int n) {
	int i, temp;

	if (n == 0)  /* 若要排序的數量為0, 則結束 */
		return;

	int max = 0;
	for (i = 1; i <= n; i++) {		/* 比較大小 */
		if (a[i] > a[max]) {
			max = i;
		}
	}

	if (max != n) {    /* 放到後面 */
		i = a[max];
		a[max] = a[n];
		a[n] = i;
	}

	selection_sort(a, n - 1);
}