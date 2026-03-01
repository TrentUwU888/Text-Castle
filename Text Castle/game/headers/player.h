#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int health;
    int attack;
} Player;

int player_attacks(Player* player);
void player_dies(Player* player);
void player_stats(Player* player);

#endif 