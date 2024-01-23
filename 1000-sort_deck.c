#include "deck.h"

/**
 * compare_cards - Comparison function for qsort
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 * Return: Positive if a > b, negative if a < b, 0 if a == b
 */
int compare_cards(const void *a, const void *b)
{
    return strcmp(((deck_node_t *)a)->card->value,
                  ((deck_node_t *)b)->card->value);
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

    /* Count the number of cards in the deck */
    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    /* Convert the deck to an array for sorting */
    deck_array = malloc(sizeof(deck_node_t *) * count);

    if (deck_array == NULL)
        return;

    current = *deck;
    for (i = 0; i < count; i++)
    {
        deck_array[i] = current;
        current = current->next;
    }

    /* Sort the array of deck nodes using qsort */
    qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);

    /* Reconnect the sorted nodes to form the sorted deck */
    for (i = 0; i < count; i++)
    {
        deck_array[i]->prev = (i == 0) ? NULL : deck_array[i - 1];
        deck_array[i]->next = (i == count - 1) ? NULL : deck_array[i + 1];
    }

    /* Update the head of the deck */
    *deck = deck_array[0];

    free(deck_array);
}
