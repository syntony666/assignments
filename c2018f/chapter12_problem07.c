/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: 呂柏鴻 */
/* ID: 107820016 */
/* Date: 2018.12.5 */
/* Purpose: 找出極值 */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
    int b[N], i, big, small;

	/* 輸入數字 */
    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &b[i]);

    max_min(b, N, &big, &small);

	/* 輸出結果*/
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

/* 求出極值 */
void max_min(int a[], int n, int *max, int *min)
{
    int *i = a;

    *max = *min = a[0];
    for (i = a; i < a + n; i++)
    {
        if (*i > *max)
            *max = *i;
        else if (*i < *min)
            *min = *i;
    }
}
