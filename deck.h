#ifndef DECK_H
#define DECK_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * typedef enum kind_e - Suit of the card
 * @SPADE: Spade suit
 * @HEART: Heart suit
 * @CLUB: Club suit
 * @DIAMOND: Diamond suit
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card (Ace to King)
 * @kind: Suit of the card (Spade, Heart, Club, Diamond)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of cards represented as a doubly linked list
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Function prototype for sorting the deck */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
