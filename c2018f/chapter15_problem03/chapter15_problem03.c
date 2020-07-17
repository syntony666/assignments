/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.12.10 */
/* Purpose: 快速排序法(使用標頭檔) */
/* Change History: log the change history of the program */
/********************************************************************/

/* chapter15_problem03.c : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。 */

#include "quicksort.h"
#include <stdio.h>

int main(void)
{
	int a[N], i;

	/* 輸入要排序的數字 */
	printf("Enter %d numbers to be sorted: ", N);
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);

	quicksort(a, 0, N - 1);

	/* 輸出結果 */
	printf("In sorted order: ");
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}
