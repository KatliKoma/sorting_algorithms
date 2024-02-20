#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 *			integers in ascending order
 *			using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current;
		current = current->next;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			tmp->prev->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;

			if (tmp->prev != NULL)
				tmp->prev->next = tmp;

			else
				*list = tmp;

			if (current != NULL)
				current->prev = tmp->next;

			print_list(*list);
		}
	}
}
