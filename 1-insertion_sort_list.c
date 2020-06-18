#include "sort.h"

/**
 * insertion_sort_list - Insertion sort algorithm
 * @list : list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *curr = tmp->next, *left;

	if (!list)
		return;

	while (curr)
	{
		left = curr;
		while (left->prev)
		{
			tmp = left->prev;
			if (tmp->n > left->n)
			{

				tmp->next = left->next;
				if (!curr->next)
					tmp->next = NULL;
				else
					left->next->prev = tmp;

				if (!tmp->prev)
					*list = left;
				else
					tmp->prev->next = left;
				left->prev = tmp->prev;
				left->next = tmp;
				tmp->prev = left;
				print_list(*list);
				continue;
			}
			left = left->prev;
		}
		curr = curr->next;
	}
}
