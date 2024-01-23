#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order
 * using Bubble sort algorithm.
 *
 * @array: array to be sorted
 * @size: size of array to be sorted
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for(i = 0; i < size - 1; i++)
	{
		for(j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}

