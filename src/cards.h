#ifndef cards
#define cards

enum tcg_card{ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT} tcg_card;

void tcg_init_deck(int *deck);
void tcg_shuffle_deck(int *deck);

#endif