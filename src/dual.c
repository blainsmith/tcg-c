#include <stdlib.h>
#include <stdio.h>

#include "players.h"
#include "dual.h"

tcg_dual *tcg_new_dual(tcg_player *p1, tcg_player *p2) {
    tcg_dual *d = malloc(sizeof(tcg_dual));

    d->player_one = p1;
    d->player_two = p2;

    d->current = d->player_one;
    
    return d;
}

tcg_player *tcg_play_dual(tcg_dual *d) {
    while (d->winner == NULL) {
        tcg_play_round(d);
    }
}

void tcg_play_round(tcg_dual *d) {
    if (d->winner != NULL) {
        return;
    }

    if (d->current->mana < MANA_MAX) {
        d->current->mana++;
    }

    tcg_pull_card(d->current);
    int card = tcg_play_card(d->current);

    printf("Player %s played card %d\n", d->current->name, card);

    if (d->player_one == d->current) {
        d->player_two->health -= card;
        d->current = d->player_two;
    } else {
        d->player_one->health -= card;
        d->current = d->player_one;
    }

    if (d->player_one->health <= 0) {
        d->winner = d->player_two;
    } else if (d->player_two->health <= 0) {
        d->winner = d->player_one;
    }
}