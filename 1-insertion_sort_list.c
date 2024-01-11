#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @current: Node to be swapped
 * @list: Head of the linked list
 */
void swap_nodes(listint_t *current, listint_t **list)
{
	listint_t *temp = current->prev;

	temp->next = current->next;
	current->next = temp;
	current->prev = temp->prev;
	temp->prev = current;

	if (temp->next)
		temp->next->prev = temp;

	if (current->prev)
		current->prev->next = current;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order.
 * @list: Head of the linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		while (current->prev && (current->n < current->prev->n))
		{
			swap_nodes(current, list);
			print_list(*list);
		}

		current = current->next;
	}
}
