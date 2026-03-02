#ifndef GOBLIN_H
#define GOBLIN_H

#include "player.h"

typedef struct {
    int health;
    int attack;
} Goblin;

int goblin_attacks(Goblin* goblin);
void goblin_dies(Goblin* goblin);
void goblin_stats(Goblin* goblin);
void battle(Goblin* goblin, Player* player);


#endif
