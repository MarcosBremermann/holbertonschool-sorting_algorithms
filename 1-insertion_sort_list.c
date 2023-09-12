#include "sort.h"
/**
 * insertion_sort_list - function that sorts via insertion sort
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = *list;
	while (current)
	{
		sorted = current->next;
		next = current->next;

		while (sorted && sorted->prev && sorted->n < sorted->prev->n)
		{
			sorted->next ? (sorted->next->prev = sorted->prev) : 0;
			sorted->prev->next = sorted->next;
			sorted->next = sorted->prev;
			sorted->prev = sorted->prev->next;
			sorted->next->prev = sorted;
			sorted->prev ? (sorted->prev->next = sorted) : (*list = sorted);
			sorted->next->next ? (sorted->next->next->prev = sorted->next) : 0;
			sorted->next->next = sorted;
			sorted->prev ? (current = sorted->prev) : (current = sorted);
		}

		if (current)
		{
			print_list(*list);
		}

		current = next;
	}
}
