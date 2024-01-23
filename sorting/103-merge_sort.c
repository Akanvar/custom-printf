#include "sort.h"
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of integers
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *leftArray, *rightArray;
	size_t i, mid;

	if (!array)
		return;
	if (size < 2)
		return;
	mid = size / 2;
	leftArray = malloc(mid * sizeof(int));
	rightArray = malloc((size - mid) * sizeof(int));
	if (!leftArray || !rightArray)
	{
		free(leftArray);
		free(rightArray);
		return;
	}

	for (i = 0; i < mid; i++)
		leftArray[i] = array[i];
	for (i = mid; i < size; i++)
		rightArray[i - mid] = array[i];

	merge_sort(leftArray, mid);
	merge_sort(rightArray, (size - mid));
	merge(array, leftArray, mid, rightArray, (size - mid), size);

	free(leftArray);
	free(rightArray);
}

/**
 * merge - merges sub-arrays created the by the merge_sort function
 * into sorted arrays
 * @array: array of integers
 * @left: left sub-array
 * @right: right sub-array
 */
void merge(int *array, int *left, size_t nLeft, int *right, size_t nRight, size_t size)
{
	size_t x, y, z;

	x = y = z = 0;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, nLeft);
	printf("[right]: ");
	print_array(right, nRight);

	while (x < nLeft && y < nRight)
	{
		if (left[x] <= right[y])
		{
			array[z] = left[x];
			x++;
		}
		else
		{
			array[z] = right[y];
			y++;
		}
		z++;
	}
	while (x < nLeft)
	{
		array[z] = left[x];
		x++;
		z++;
	}
	while (y < nRight)
	{
		array[z] = right[y];
		y++;
		z++;
	}
	printf("[Done]: ");
	print_array(array, size);
}

