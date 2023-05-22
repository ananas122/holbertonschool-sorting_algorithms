#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int index, currentElement;

	if (!array)
		return;

	for (index = 0; index < size - 1; index++)
	{
		for (currentElement = 0; currentElement < size - index - 1; currentElement++)
		{
			if (array[currentElement] > array[currentElement + 1])
			{
				swap(&array[currentElement], &array[currentElement + 1]);
				print_array(array, size);
			}
		}
	}
}
