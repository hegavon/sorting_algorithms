#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail Shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;

		for (current = *list; current->next != NULL; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				print_list(*list);
			}
		}

		if (!swapped)
			break;

		swapped = 0;

		for (; current->prev != NULL; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				print_list(*list);
			}
		}
	}
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @node1: First node to be swapped.
 * @node2: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/* Declare variables */
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	/* Create a doubly linked list from the array */
	list = create_listint(array, n);
	if (!list)
		return (EXIT_FAILURE);

	/* Print the original list */
	print_list(list);
	printf("\n");

	/* Sort the list using the Cocktail Shaker Sort algorithm */
	cocktail_sort_list(&list);

	/* Print the sorted list */
	printf("\nSorted list:\n");
	print_list(list);

	/* Free the allocated memory for the list */
	free_list(list);

	/* Return 0 to indicate successful execution */
	return (EXIT_SUCCESS);
}

/**
 * free_list - Frees a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 */
void free_list(listint_t *list)
{
	listint_t *current, *temp;

	current = list;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
