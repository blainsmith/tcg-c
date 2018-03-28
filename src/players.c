#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "players.h"
#include "cards.h"

tcg_player *tcg_new_player(char *name) {
    tcg_player *player = malloc(sizeof(tcg_player));

    player->name = malloc(20);
    strcpy(player->name, name);
    player->health = INITIAL_HEALTH;
    player->mana = INITIAL_MANA;
    player->deck_size = DECK_SIZE;
    player->hand_size = 0;

    tcg_init_deck(player->deck);
    tcg_shuffle_deck(player->deck);

    int i = 0;
    while (tcg_pull_card(player) && i < 2) {
        i++;
    }
    
    return player;
}

bool tcg_pull_card(tcg_player *player) {
    if (player->hand_size >= HAND_SIZE) {
        return false;
    }
    
    int rc = rand() % player->deck_size;
    int card = player->deck[rc];
    
    int c;
    for (c = rc; c < player->deck_size; c++) {
        player->deck[c] = player->deck[c+1];
    }
    player->deck_size--;

    player->hand[player->hand_size] = card;
    player->hand_size++;

    return true;
}

int tcg_play_card(tcg_player *player) {
    int rc = rand() % player->hand_size;
    int card = player->hand[rc];
    
    if (player->mana >= card) {
        player->mana -= card;

        int c;
        for (c = rc; c < player->hand_size; c++) {
            player->hand[c] = player->hand[c+1];
        }
        player->hand_size--;

        return card;
    }
    return 0;
}

void display_player(tcg_player *player) {
    int i;
    printf("+----------------------------\n");
    printf("| Name: %s\n", player->name);
    printf("| Health: %d\n", player->health);
    printf("| Mana: %d\n", player->mana);
    printf("| Deck: ");
    for (i = 0; i < player->deck_size; i++) { printf("[%d] ", player->deck[i]); }
    printf("\n| Hand: ");
    for (i = 0; i < player->hand_size; i++) { printf("[%d] ", player->hand[i]); }
    printf("\n+----------------------------\n");
}