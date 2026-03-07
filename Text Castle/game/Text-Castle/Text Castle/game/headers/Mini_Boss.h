#ifndef BETA_BOSS_H
#define BETA_BOSS_H

#include "player.h"

typedef struct {
    int health;
    int attack;
} BetaBoss;

int beta_boss_attacks(BetaBoss* boss);
void beta_boss_dies(BetaBoss* boss);
void beta_boss_stats(BetaBoss* boss);
void beta_boss_battle(BetaBoss* boss, Player* player);

#endif
