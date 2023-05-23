#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @h: A pointer to the head of the doubly-linked list.
 * @n1: A pointer to the first node to swap.
 * @n2: The second node to swap.
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	
	/* Vérifier si le n2 n'est pas le dernier nœud de la liste */
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	
	/* Vérifier si le n1 n'est pas le premier nœud de la liste */
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - Sorts insertion a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list of integers.
 */

void insertion_sort_list(listint_t **list)
{

	listint_t *current, *insert, *tmp;

	/* Vérifier si la liste est vide*/
	if (list == NULL || *list == NULL || (*list)->next == NULL)
        	return;

	/* Parcourir la liste à partir du deuxième élément */
	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insert = current->prev;

		while (insert != NULL && current->n < insert->n)
        	{
            		/*swap les noeuds*/
			swap_nodes(list, &insert, current);

            		/* Afficher la liste après chaque échange */
			print_list((const listint_t *)*list);

        }
    }
}


