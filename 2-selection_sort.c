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
 * selection_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int index, current, smallElement;

	/* Vérifie les cas où aucun tri n'est nécessaire */
	if (!array || size < 2)
		return;

	/* Parcours le tableau */
	for (index = 0; index < size - 1; index++)
	{
		smallElement = index;

		/* Recherche l'élement minimum */
		for (current = index + 1; current < size; current++)
		{
			if (array[current] < array[smallElement])
				smallElement = current; /* Met à jour l'élement minimum trouvé */
		}

		/* Verifi si un élement est plus petit on l'échange et on l'affiche */
		if (index != smallElement)
		{
			swap(&array[smallElement], &array[index]);
			print_array(array, size);
		}
	}
}
