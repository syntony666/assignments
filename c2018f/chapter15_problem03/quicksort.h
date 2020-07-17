/*quicksort.c及chapter15_problem03.c之標頭檔*/

#ifndef QUICKSORT_H
#define QUICKSORT_H

/* 定義陣列大小 */
#define N 10

/* 函式定義 */
void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

#endif //QUICKSORT_H
