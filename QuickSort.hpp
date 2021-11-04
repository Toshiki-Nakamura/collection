#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T	partition(T array[], int left, int right)
{
	T Pivot = array[right];
	int index = (left - 1);

	for (int j = left; j <= right-1; j++)
	{
		if (array[j] <= Pivot) {
			index++;
			swap(array[index], array[j]);
		}
	}
	swap(array[index + 1], array[right]);
	return (index + 1);
}

template<typename T>
void	quick_sort(T array[], int left, int right)
{
	if (left >= right)
		return ;
	T pivot = partition(array, left, right);
	quick_sort(array, left, pivot - 1);
	quick_sort(array, pivot + 1, right);
}

#endif
