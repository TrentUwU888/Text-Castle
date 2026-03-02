#include "goblin.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void to_lower_str(char *s) {
    while (*s != '\0') {
        *s = (char)tolower((unsigned char)*s);
        s++;
    }
}

int goblin_attacks(Goblin* goblin) {
    if (goblin == NULL || goblin->health <= 0) {
        return 0;
    }
    if (goblin->attack > 0) {
        return goblin->attack;
    }
    return 0;
}

void battle(Goblin* goblin, Player* player) {
    if (goblin == NULL || player == NULL) {
        printf("Battle cannot start.\n");
        return;
    }
    if (goblin->health <= 0) {
        printf("There is no goblin to fight.\n");
        return;
    }
    if (player->health <= 0) {
        printf("You are too weak to fight.\n");
        return;
    }

    int defending = 0;
    char action[16];

    printf("Battle start! Commands: attack, magic, heal, defend, flee\n");

    while (goblin->health > 0 && player->health > 0) {
        printf("\nYour HP: %d | Goblin HP: %d\n", player->health, goblin->health);
        printf("Your turn > ");
        if (scanf("%15s", action) != 1) {
            return;
        }
        to_lower_str(action);

        if (strcmp(action, "attack") == 0) {
            int playerDamage = player_attacks(player);
            goblin->health -= playerDamage;
            printf("You hit the goblin for %d damage!\n", playerDamage);
        } else if (strcmp(action, "magic") == 0) {
            if (!player->has_magic_staff || player->magic_attack <= 0) {
                printf("You do not know any magic attack yet.\n");
                continue;
            }
            goblin->health -= player->magic_attack;
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

        if (goblin->health <= 0) {
            goblin_dies(goblin);
            break;
        }

        int goblinDamage = goblin_attacks(goblin);
        if (defending) {
            goblinDamage -= 2;
            if (goblinDamage < 0) {
                goblinDamage = 0;
            }
            defending = 0;
        }

        player->health -= goblinDamage;
        printf("The goblin attacks you for %d damage!\n", goblinDamage);
        if (player->health <= 0) {
            player_dies(player);
            printf("You were defeated by the goblin.\n");
            break;
        }
    }
}

void goblin_dies(Goblin* goblin) {
    if (goblin == NULL) {
        return;
    }
    printf("The goblin has been defeated!\n");
    goblin->health = 0;
}

void goblin_stats(Goblin* goblin) {
    if (goblin == NULL) {
        return;
    }
    printf("The goblin has %d HP and does %d damage.\n", goblin->health, goblin->attack);
}
