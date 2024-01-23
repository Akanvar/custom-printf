#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: array of integers
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *outputArray, *countArray, j, k;
	size_t i, max;

	if (array == NULL || size < 2)
		return;

	k = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	max = k;
	countArray = malloc((max + 1) * sizeof(int));
	if (!countArray)
		return;
	for (i = 0; i < max + 1; i++)
		countArray[i] = 0;

	for (i = 0; i < size; i++)
		countArray[array[i]]++;
	
	for (i = 1; i <= max; i++)
		countArray[i] += countArray[i - 1];
	print_array(countArray, max + 1);

	outputArray = malloc(size * sizeof(int));
	if (!outputArray)
		return;

	for (j = size - 1; j >= 0; j--)
		outputArray[--countArray[array[j]]] = array[j];

	for (i = 0; i < size; i++)
		array[i] = outputArray[i];
	free(countArray);
	free(outputArray);
}
