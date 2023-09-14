#include "sort.h"
/**
 * insertion_sort_list - function that sorts via insertion sort
 * @list: list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *anode, *temp, *nodprev;

	if (!list || !*list)
		return;
	anode = *list;
	while ((anode = anode->next))
	{
		temp = anode;
		while (anode->prev && (anode->n < anode->prev->n))
		{
			nodprev = temp->prev;
			if (temp->next)
				temp->next->prev = nodprev;
			if (nodprev->prev)
				nodprev->prev->next = temp;
			else
				*list = temp;
			nodprev->next = temp->next;
			temp->prev = nodprev->prev;
			temp->next = nodprev;
			nodprev->prev = temp;
			print_list(*list);
		}
	}
}
