#include "bat.h"
#include <stdio.h>
#include <string.h>

int bat_attacks(Bat* bat) {
    if (bat == NULL || bat->health <= 0) {
        return 0;
    }
    if (bat->attack > 0) {
        return bat->attack;
    }
    return 0;
}

void battle(Bat* bat, Player* player) {
    if (bat == NULL || player == NULL) {
        printf("Battle cannot start.\n");
        return;
    }
    if (bat->health <= 0) {
        printf("There is no bat to fight.\n");
        return;
    }
    if (player->health <= 0) {
        printf("You are too weak to fight.\n");
        return;
    }

    int defending = 0;
    char action[16];

    printf("Battle start! Commands: attack, defend, flee\n");

    while (bat->health > 0 && player->health > 0) {
        printf("\nYour HP: %d | Bat HP: %d\n", player->health, bat->health);
        printf("Your turn > ");
        if (scanf("%15s", action) != 1) {
            return;
        }

        if (strcmp(action, "attack") == 0) {
            int playerDamage = player_attacks(player);
            bat->health -= playerDamage;
            printf("You hit the bat for %d damage!\n", playerDamage);
        } else if (strcmp(action, "defend") == 0) {
            defending = 1;
            printf("You brace for the next hit.\n");
        } else if (strcmp(action, "flee") == 0) {
            printf("You fled the battle.\n");
            return;
        } else {
            printf("Invalid action. Use attack, defend, or flee.\n");
            continue;
        }

        if (bat->health <= 0) {
            bat_dies(bat);
            break;
        }

        int batDamage = bat_attacks(bat);
        if (defending) {
            batDamage -= 2;
            if (batDamage < 0) {
                batDamage = 0;
            }
            defending = 0;
        }

        player->health -= batDamage;
        printf("The bat attacks you for %d damage!\n", batDamage);
        if (player->health <= 0) {
            player_dies(player);
            printf("You were defeated by the bat.\n");
            break;
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
