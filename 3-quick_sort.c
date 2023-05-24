#include "sort.h"

/**
 * swap - Swaps the values of two integers
 * @arr: Array of integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *arr, ssize_t a, ssize_t b)
{
	int tmp;

	tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

/**
 * partitionLomuto - Partitions the array using the Lomuto partition scheme
 * @arr: Array of integers
 * @firstElement: Index of the first element
 * @lastElement: Index of the last element
 * @size: Size of the array
 *
 * Return: Index of the pivot element
 */
int partitionLomuto(int *arr, int firstElement, int lastElement, size_t size)
{
	int pivot = arr[lastElement];
	int current = firstElement;
	int index = 0;

	for (index = firstElement; index < lastElement; index++)
	{
		if (arr[index] < pivot)
		{
			/* Vérifie si current est différent de l'élément à échanger */
			if (arr[current] != arr[index])
			{
				swap(arr, current, index);
				print_array(arr, size);
			}
			current++;
		}
	}

	/* Vérifie si l'élément courant est différent du pivot */
	if (arr[current] != arr[lastElement])
	{
		swap(arr, current, lastElement);
		print_array(arr, size); /* Affiche le tableau après l'échange */
	}

	/* Retourne l'index du pivot après partitionnement */
	return (current);
}

/**
 * quickRecursive - Recursive function to perform quicksort
 * @arr: Array of integers
 * @firstElement: Index of the first element
 * @lastElement: Index of the last element
 * @size: Size of the array
 */
void quickRecursive(int *arr, int firstElement, int lastElement, size_t size)
{
	if (firstElement < lastElement)
	{
		/* Effectue la partition du tableau en utilisant l'algorithme de Lomuto */
		int pivot = partitionLomuto(arr, firstElement, lastElement, size);

		/* Effectue le tri rapide récursif */
		quickRecursive(arr, firstElement, pivot - 1, size);
		quickRecursive(arr, pivot + 1, lastElement, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using quicksort
 * @array: Array of integers
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	/* Appelle la fonction pour effectuer le tri rapide récursif du tableau */
	quickRecursive(array, 0, size - 1, size);
}
