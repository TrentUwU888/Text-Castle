#ifndef BAT_H
#define BAT_H

typedef struct {
    int health;
    int attack;
} Bat;

int bat_attacks(Bat* bat);
void bat_dies(Bat* bat);
void bat_stats(Bat* bat);
void battle(Bat* bat);


#endif 