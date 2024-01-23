#include "deck.h"

/**
 * _strcmp - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: Positive byte difference if str1 > str2
 *         0 if str1 == str2
 *         Negative byte difference if str1 < str2
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * get_card_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_card_value(deck_node_t *card)
{
	if (_strcmp(card->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(card->card->value, "1") == 0)
		return (1);
	if (_strcmp(card->card->value, "2") == 0)
		return (2);
	if (_strcmp(card->card->value, "3") == 0)
		return (3);
	if (_strcmp(card->card->value, "4") == 0)
		return (4);
	if (_strcmp(card->card->value, "5") == 0)
		return (5);
	if (_strcmp(card->card->value, "6") == 0)
		return (6);
	if (_strcmp(card->card->value, "7") == 0)
		return (7);
	if (_strcmp(card->card->value, "8") == 0)
		return (8);
	if (_strcmp(card->card->value, "9") == 0)
		return (9);
	if (_strcmp(card->card->value, "10") == 0)
		return (10);
	if (_strcmp(card->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_deck_by_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck_by_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck_by_value - Sort a deck of cards sorted from
 *                      spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck_by_value(deck_node_t **deck)
{
	deck_node_t *current, *insert, *temp;

	for (current = (*deck)->next; current != NULL; current = temp)
	{
		temp = current->next;
		insert = current->prev;
		while (insert != NULL &&
				insert->card->kind == current->card->kind &&
				get_card_value(insert) > get_card_value(current))
		{
			insert->next = current->next;
			if (current->next != NULL)
				current->next->prev = insert;
			current->prev = insert->prev;
			current->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = current;
			else
				*deck = current;
			insert->prev = current;
			insert = current->prev;
		}
	}
}

/**
 * sort_deck - It sorts a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: This is a pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_by_kind(deck);
	sort_deck_by_value(deck);
}
