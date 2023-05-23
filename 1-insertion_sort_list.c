#include "sort.h"

/**
 * insertion_sort_list - Sorts insertion a doubly linked list of integers
 * @list: A pointer to the head of a doubly-linked list of integers.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swap, *preview;

	if (!list || !*list)
		return;

	current = *list;
	while ((current = current->next))
	{
		swap = current;

		/* Trouver la position d'insertion appropriée pour le noeud actuel*/
		while (swap->prev && swap->n < swap->prev->n)
		{
			preview = swap->prev;

			/* Mettre à jours les pointeurs next et prev pour les noeuds voisins */
			if (swap->next)
				swap->next->prev = preview;
			if (preview->prev)
				preview->prev->next = swap;
			else
				/* Update la tête de liste si le noeud actuel devient la nouvelle tête */
				*list = swap;

			/* Réorganise *next et *prev pour insérer le noeud actuel */
			preview->next = swap->next;
			swap->prev = preview->prev;
			swap->next = preview;
			preview->prev = swap;

			/* Affiche la liste après chaque étape de tri */
			print_list(*list);
		}
	}
}
