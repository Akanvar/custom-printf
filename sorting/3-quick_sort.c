#include "sort.h"
/**
 * quick_sort - sorts an array of integers
 * in ascending order using the quick sort algorithm
 *
 * @array: array of integers
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	lomuto_sort(array, 0, size - 1, size);
}

/**
 * lomuto_sort - Sorts an array of integers recursively
 *
 * @array: array of integers
 * @low: lowest index of array
 * @high: highest index of array
 * @size: size of array
 */
void lomuto_sort(int *array, int low, int high, size_t size)
{
	int idx;

	if (low >= high || low < 0)
		return;

	idx = lomuto_partition(array, low, high, size);
	lomuto_sort(array, low, idx - 1, size);
	lomuto_sort(array, idx + 1, high, size);
}
/**
 * lomuto_partition - Partitions array using the last element as the pivot
 *
 * @high: highest index of array
 * @low: lowest index of array
 * @array: array of numbers
 * @size: size of array
 *
 * Return: index of pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	i = low - 1;
	pivot = array[high];

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	return (i);
}

