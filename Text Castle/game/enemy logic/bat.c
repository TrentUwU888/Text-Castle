#include "bat.h"
#include <stdio.h>

int bat_attacks(Bat* bat) {
    if (bat == NULL || bat->health <= 0) {
        return 0;
    }
    if (bat->attack > 0) {
        return bat->attack;
    }
    return 0;
}

void battle(Bat* bat) {
    if (bat == NULL || bat->health <= 0) {
        printf("There is no bat to fight.\n");
        return;
    }

    // Temporary combat loop until player system is wired in.
    const int player_damage = 6;
    printf("You engage in battle with the bat!\n");

    while (bat->health > 0) {
        printf("You hit the bat for %d damage.\n", player_damage);
        bat->health -= player_damage;
        if (bat->health <= 0) {
            bat_dies(bat);
            break;
        }

        int batDamage = bat_attacks(bat);
        if (batDamage > 0) {
            printf("The bat attacks you for %d damage!\n", batDamage);
        } else {
            printf("The bat's attack missed!\n");
        }
    }
}

void bat_dies(Bat* bat) {
    if (bat == NULL) {
        return;
    }
    printf("The bat has been defeated!\n");
    bat->health = 0;
}

void bat_stats(Bat* bat) {
    if (bat == NULL) {
        return;
    }
    printf("The bat has %d HP and does %d damage.\n", bat->health, bat->attack);
}
