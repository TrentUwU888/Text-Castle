#include "player.h"
#include <stdio.h>

void player_stats(Player* player) {
    if (player == NULL) {
        return;
    }
    printf("You have %d HP and do %d damage.\n", player->health, player->attack);
}

void player_dies(Player* player) {
    if (player == NULL) {
        return;
    }

    player->health = 0;
}

int player_attacks(Player* player) {
    if (player == NULL || player->health <= 0) {
        return 0;
    }
    if (player->attack > 0) {
        return player->attack;
    }
    return 0;
}
