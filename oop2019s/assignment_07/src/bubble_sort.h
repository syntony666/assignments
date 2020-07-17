#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

template <class T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template <class T, class COMPARE>
void bubbleSort(T begin, T end, COMPARE comp)
{
	for (T i = end - 1; i != begin; i--)
		for (T j = begin; j != i; j++)
			if (comp(*(j + 1), *j))
				swap(*(j + 1), *j);
}

#endif
