#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
* struct listint_s - Singly linked list node
* @n: integer stored in the node
* @prev: pointer to the previous node in the list
* @next: pointer to the next node in the list
*
* Description: This structure defines a singly linked list node
*/
typedef struct listint_s
{
	int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

#endif
