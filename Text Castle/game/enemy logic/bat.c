#include "bat.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void to_lower_str(char *s) {
    while (*s != '\0') {
        *s = (char)tolower((unsigned char)*s);
        s++;
    }
}

int bat_attacks(Bat* bat) {
    if (bat == NULL || bat->health <= 0) {
        return 0;
    }
    if (bat->attack > 0) {
        return bat->attack;
    }
    return 0;
}

void bat_battle(Bat* bat, Player* player) {
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

    printf("Battle start! Commands: attack, magic, heal, defend, flee\n");

    while (bat->health > 0 && player->health > 0) {
        printf("\nYour HP: %d | Bat HP: %d\n", player->health, bat->health);
        printf("Your turn > ");
        if (scanf("%15s", action) != 1) {
            return;
        }
        to_lower_str(action);

        if (strcmp(action, "attack") == 0) {
            int playerDamage = player_attacks(player);
            bat->health -= playerDamage;
            printf("You hit the bat for %d damage!\n", playerDamage);
        } else if (strcmp(action, "magic") == 0) {
            if (!player->has_magic_staff || player->magic_attack <= 0) {
                printf("You do not know any magic attack yet.\n");
                continue;
            }
            bat->health -= player->magic_attack;
            printf("You cast a spell for %d damage!\n", player->magic_attack);
        } else if (strcmp(action, "heal") == 0) {
            const int heal_amount = 12;
            const int max_health = 40;
            if (!player->has_heal_spell) {
                printf("You do not know the Heal Spell.\n");
                continue;
            }
            if (player->health >= max_health) {
                printf("Your HP is already full.\n");
                continue;
            }
            player->health += heal_amount;
            if (player->health > max_health) {
                player->health = max_health;
            }
            printf("You cast Heal Spell. HP restored to %d.\n", player->health);
        } else if (strcmp(action, "defend") == 0) {
            defending = 1;
            printf("You brace for the next hit.\n");
        } else if (strcmp(action, "flee") == 0) {
            printf("You fled the battle.\n");
            return;
        } else {
            printf("Invalid action. Use attack, magic, heal, defend, or flee.\n");
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
