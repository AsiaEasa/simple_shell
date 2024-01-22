#include "deck.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 *         0 if s1 == s2
 *         Negative byte difference if s1 < s2
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

}

int get_value(deck_node_t *card)
{
    static const char *card_values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

    const char *value = card->card->value;

    for (int i = 0; i < 13; ++i)
    {
        if (_strcmp(value, card_values[i]) == 0)
        {
            return i + 1 + 13 * card->card->kind;
        }
    }

    return 0; // handle invalid values
}
/**
 * compare_cards - Compare two cards based on their values and kinds.
 * @card1: A pointer to the first deck_node_t card.
 * @card2: A pointer to the second deck_node_t card.
 *
 * Return: Positive byte difference if card1 > card2
 *         0 if card1 == card2
 *         Negative byte difference if card1 < card2
 */
int compare_cards(deck_node_t *card1, deck_node_t *card2)
{
    int value_diff = get_value(card1) - get_value(card2);

    if (value_diff == 0) {
        return card1->card->kind - card2->card->kind;
    }

    return value_diff;
}



void bubble_sort(deck_node_t **deck, int (*compare)(deck_node_t *, deck_node_t *))
{
    int swapped;
    deck_node_t *ptr1;
    deck_node_t *lptr = NULL;
    deck_node_t *tmp;

    if (*deck == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = *deck;

        while (ptr1->next != lptr)
        {
            if (compare(ptr1, ptr1->next) > 0)
            {
                tmp = ptr1->next;
                ptr1->next = tmp->next;

                if (tmp->next != NULL)
                    tmp->next->prev = ptr1;

                tmp->prev = ptr1->prev;
                ptr1->prev = tmp;
                tmp->next = ptr1;

                if (tmp->prev != NULL)
                    tmp->prev->next = tmp;
                else
                    *deck = tmp;

                ptr1 = tmp;
                swapped = 1;
            }
            else
            {
                ptr1 = ptr1->next;
            }
        }
        lptr = ptr1;
    } while (swapped);
}
/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds using bubble sort.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    bubble_sort(deck, compare_cards);
}
