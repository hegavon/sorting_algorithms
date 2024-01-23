#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * enum kind_e - Enumeration of card suits
 * @SPADE: Spades suit
 * @HEART: Hearts suit
 * @CLUB: Clubs suit
 * @DIAMOND: Diamonds suit
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
 * @kind: Kind of the card (SPADE, HEART, CLUB, DIAMOND)
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of cards
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

/* Function prototypes */
void sort_deck(deck_node_t **deck);
int _strcmp(const char *s1, const char *s2);
char get_card_value(deck_node_t *card);
void sort_deck_kind(deck_node_t **deck);
void sort_deck_value(deck_node_t **deck);


#endif /* DECK_H */
