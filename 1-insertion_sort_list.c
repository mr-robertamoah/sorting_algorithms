#include "sort.h"

/**
* swap_nodes - swap two nodes in a doubly
* linked list
* @a: listint_t node
* @b: listint_t node
*/
void swap_nodes(listint_t **a, listint_t **b)
{
	listint_t *next, *prev;

	next = (*b)->next;
	prev = (*a)->prev;
	(*b)->next = *a;
	(*b)->prev = prev;
	if (prev)
		prev->next = *b;
	(*a)->next = next;
	if (next)
		next->prev = *a;
	(*a)->prev = *b;
}

/**
* insertion_sort_list - Sorts a doubly linked list using the
* insertion sort algorithm.
* @list: Pointer to the head of the linked list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *first, *second, *tmp;

	if (list == NULL || *list == NULL)
		return;

	curr = *list;
	while (curr)
	{
		first = curr;
		second = curr->next;
		if (first && second && first->n > second->n)
		{
			swap_nodes(&first, &second);
			if (second && second->prev == NULL)
				*list = second;
			print_list(*list);
			while (second && second->prev && second->n < second->prev->n)
			{
				tmp = second->prev;
				swap_nodes(&tmp, &second);
				if (second->prev == NULL)
					*list = second;
				print_list(*list);
			}
		}
		else
			curr = curr->next;
	}
}
