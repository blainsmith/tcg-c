#include <stdio.h>

#include "players.h"
#include "cards.h"
#include "dual.h"

int main(int argc, char *argv[]) {

    char input[256];

    printf("Player 1 Name: ");
    scanf("%s", input);
    tcg_player *p1 = tcg_new_player(input);
    printf("");

    printf("Player 2 Name: ");
    scanf("%s", input);
    tcg_player *p2 = tcg_new_player(input);
    printf("");

    tcg_dual *d = tcg_new_dual(p1, p2);

    tcg_player *winner = tcg_play_dual(d);

    printf("WINNER\n");
    display_player(winner);

    return 0;
}