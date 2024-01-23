#include "sort.h"
/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using Knuth sequence
 *
 * @array: array of integers
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t x, gap;
	int y;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap < (size / 3))
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (x = gap; x < size; x++)
		{
			for (y = x - gap; y >= 0; y -= gap)
			{
				if (array[y] > array[y + gap])
					swap_int(&array[y], &array[y + gap]);
				else
					break;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}

