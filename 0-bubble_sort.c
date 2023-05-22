#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int index, j;

	if (!array)
		return;

	for (index = 0; index < size -1; index++)
	{
		for (j = 0; j < size - index - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
