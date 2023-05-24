#include "sort.h"

/**
 * swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swap(int *arr, ssize_t a, ssize_t b)
{
	int tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}
