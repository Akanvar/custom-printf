#include "sort.h"
/**
 * selection_sort - sorts an array of integers
 * in ascending order using Selection sort algorithm
 *
 * @array: array of integers
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;

		}
		if (min_idx != i)
		{
			swap_int(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}

