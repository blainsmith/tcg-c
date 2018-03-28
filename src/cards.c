#include <stdlib.h>

#include "players.h"
#include "cards.h"

void tcg_init_deck(int *deck) {
    deck[0] = ZERO;
    deck[1] = ZERO;

    deck[2] = ONE;
    deck[3] = ONE;
    
    deck[4] = TWO;
    deck[5] = TWO;
    deck[6] = TWO;

    deck[7] = THREE;
    deck[8] = THREE;
    deck[9] = THREE;
    deck[10] = THREE;

    deck[11] = FOUR;
    deck[12] = FOUR;
    deck[13] = FOUR;

    deck[14] = FIVE;
    deck[15] = FIVE;

    deck[16] = SIX;
    deck[17] = SIX;

    deck[18] = SEVEN;

    deck[19] = EIGHT;
}

void tcg_shuffle_deck(int *deck) {
    int i, j, tmp;

    for (i = DECK_SIZE - 1; i > 0; i--) {
         j = rand() % (i + 1);
         tmp = deck[j];
         deck[j] = deck[i];
         deck[i] = tmp;
     }
}