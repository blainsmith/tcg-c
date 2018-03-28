#ifndef dual
#define dual

typedef struct tcg_dual {
    tcg_player *winner;
    tcg_player *current;

    tcg_player *player_one;
    tcg_player *player_two;
} tcg_dual;

tcg_dual *tcg_new_dual(tcg_player *p1, tcg_player *p2);
tcg_player *tcg_play_dual(tcg_dual *d);
void tcg_play_round(tcg_dual *d);

#endif