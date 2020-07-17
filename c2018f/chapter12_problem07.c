/********************************************************************/
/* Class: Computer Programming, Fall 2018 */
/* Author: �f�f�E */
/* ID: 107820016 */
/* Date: 2018.12.5 */
/* Purpose: ��X���� */
/* Change History: log the change history of the program */
/********************************************************************/

#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
    int b[N], i, big, small;

	/* ��J�Ʀr */
    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &b[i]);

    max_min(b, N, &big, &small);

	/* ��X���G*/
    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    return 0;
}

/* �D�X���� */
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
