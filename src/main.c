#include <stdio.h>

#include "players.h"
#include "cards.h"

int main(int argc, char *argv[]) {
    tcg_player *player_one = tcg_new_player("rblgk");
    tcg_player *player_two = tcg_new_player("fluffyfatguy");

    display_player(player_one);
    display_player(player_two);

    return 0;
}