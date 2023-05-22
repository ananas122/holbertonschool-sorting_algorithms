#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t index, currentElement;

	for (index = 0; index < size - 1; index++)
	{
		for (currentElement = 0; currentElement < size - index - 1; currentElement++)
		{
			if (array[currentElement] > array[currentElement + 1])
			{
				/* Échanger les éléments */
				int temp = array[currentElement];

				array[currentElement] = array[currentElement + 1];
				array[currentElement + 1] = temp;
			}
		}
		/* Afficher le tableau après chaque itération */
		for (currentElement = 0; currentElement < size - 1; currentElement++)
		{
			printf("%d, ", array[currentElement]);
		}
		printf("%d\n", array[size - 1]);
	}
}
