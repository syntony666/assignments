/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.10.8 */
/* Purpose: 求行與列之和 */
/* Change History: log the change history of the program */
/********************************************************************/


#include<stdio.h>

int main() {

	int arr[5][5];

	int i, j;

	for (i = 0; i < 5; i++) {
			printf("Enter row %d: ", i + 1);
			scanf("%d %d %d %d %d", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3], &arr[i][4]);
	}

	printf("Row totals: ");

	/* 輸出列之和 */
	for (i = 0; i < 5; i++) {
		printf("%d ", arr[i][0] + arr[i][1] + arr[i][2] + arr[i][3] + arr[i][4]);
	}

	printf("\nColumn totals: ");

	/* 輸出行之和 */
	for (i = 0; i < 5; i++) {
		printf("%d ", arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i] + arr[4][i]);
	}


	return 0;
}