#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 *			integers in ascending order
 *			using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *backtrack;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current && current->prev;
			current = current->next)
	{
		for (; current && current->prev && current->n < current->prev->n;
				current = current->prev)
		{
			backtrack = current->prev;
			nodeSwap(list, backtrack, current);
			print_list(*list);
			current = current->next;
		}
	}
}

/**
 * nodeSwap - swaps two nodes
 * @head: the head node
 * @currentNode: The first node to swap
 * @nextNode: The second node to swap
 *
 * Return: void
 */

void nodeSwap(listint_t **head, listint_t *currentNode, listint_t *nextNode)
{
	listint_t *previousNode, *followingNode;

	previousNode = currentNode->prev;
	followingNode = nextNode->next;

	if (previousNode != NULL)
		previousNode->next = nextNode;
	else
		*head = nextNode;
	currentNode->prev = nextNode;
	currentNode->next = followingNode;
	nextNode->prev = previousNode;
	nextNode->next = currentNode;

	if (followingNode)
		followingNode->prev = currentNode;
}
