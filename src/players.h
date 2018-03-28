#include <stdbool.h>

#ifndef players
#define players

#define size_of_cards(x)  ((&x)[1] - x)

#define INITIAL_HEALTH 30
#define INITIAL_MANA 10
#define MANA_INCREMENT 1
#define MANA_MAX 10
#define DECK_SIZE 20
#define HAND_SIZE 5

typedef struct tcg_player {
    char *name;
    int health;
    int mana;
    int deck_size;
    int deck[DECK_SIZE];
    int hand_size;
    int hand[HAND_SIZE];
} tcg_player;

tcg_player *tcg_new_player(char *name);
bool tcg_pull_card(tcg_player *player);
int tcg_play_card(tcg_player *player);
void display_player(tcg_player *player);

#endif