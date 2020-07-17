/* pch.cpp: 對應到先行編譯過之標頭的來源檔案; 編譯需要此才可成功 */

#include "quicksort.h"

/* 快速排序法 */
void quicksort(int a[], int low, int high)
{
	int middle;

	if (low >= high) return;
	middle = split(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

/* 設定節點 */
int split(int a[], int low, int high)
{
	int part_element = a[low];

	for (;;)
	{
		while (low < high && part_element <= a[high])
			high--;
		if (low >= high) break;
		a[low++] = a[high];

		while (low < high && a[low] <= part_element)
			low++;
		if (low >= high) break;
		a[high--] = a[low];
	}

	a[high] = part_element;
	return high;
}