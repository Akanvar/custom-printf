#include "sort.h"
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 *
 * @list: doubly linked list of integers
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *tmp;
	bool swapped;

	node = *list;
	swapped = true;

	if (!list || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = false;

		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(list, node->next);
				print_list(*list);
				swapped = true;
			}
			node = node->next;
		}

		if (!swapped)
			break;

		swapped = false;
		tmp = node->prev;
		while (tmp->prev)
		{
			if (tmp->n < tmp->prev->n)
			{
				tmp = swap_node(list, tmp);
				print_list(*list);
				swapped = true;
			}
			else
				tmp = tmp->prev;
		}
		node = tmp->next;
	}
}
