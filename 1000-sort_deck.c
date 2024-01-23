#include "deck.h"

/**
 * compare_cards - Comparison function for qsort
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: Positive if a > b, negative if a < b, 0 if a == b
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = ((deck_node_t *)a)->card;
	const card_t *card_b = ((deck_node_t *)b)->card;

	/* Compare suits first */
	int suit_cmp = ((int)(card_a->kind)) - ((int)(card_b->kind));

	if (suit_cmp == 0)
	{
		/* If suits are the same, compare values */
		return (strcmp(card_a->value, card_b->value));
	}

	return (suit_cmp);
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to the head of the doubly linked list representing the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t count;
	deck_node_t *current, **deck_array;
	size_t i;

	if (deck == NULL || *deck == NULL)
		return;

	count = 0;
	current = *deck;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	deck_array = malloc(sizeof(deck_node_t *) * count);

	if (deck_array == NULL)
		return;

	current = *deck;
	for (i = 0; i < count; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < count; i++)
	{
		deck_array[i]->prev = (i == 0) ? NULL : deck_array[i - 1];
		deck_array[i]->next = (i == count - 1) ? NULL : deck_array[i + 1];
	}

	/* Update the head of the deck */
	*deck = deck_array[0];

	free(deck_array);
}
