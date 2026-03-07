#ifndef PLAYER_H
#define PLAYER_H

typedef struct {
    int health;
    int attack;
    int has_rusty_sword;
    int has_magic_staff;
    int magic_attack;
    int has_heal_spell;
} Player;

int player_attacks(Player* player);
void player_dies(Player* player);
void player_stats(Player* player);
void inventory(Player* player);

#endif 
