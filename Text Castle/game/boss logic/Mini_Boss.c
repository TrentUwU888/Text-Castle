#include "Mini_Boss.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void to_lower_str(char *s) {
    while (*s != '\0') {
        *s = (char)tolower((unsigned char)*s);
        s++;
    }
}

void beta_boss_stats(BetaBoss* boss) {
    if (boss == NULL) {
        return;
    }
    printf("Beta Boss has %d HP and does %d damage.\n", boss->health, boss->attack);
}

void beta_boss_dies(BetaBoss* boss) {
    if (boss == NULL) {
        return;
    }

    boss->health = 0;
}

void beta_boss_battle(BetaBoss* boss, Player* player) {
    if (boss == NULL || player == NULL) {
        printf("Battle cannot start.\n");
        return;
    }
    if (boss->health <= 0) {
        printf("There is no boss to fight.\n");
        return;
    }
    if (player->health <= 0) {
        printf("You are too weak to fight.\n");
        return;
    }

    int defending = 0;
    char action[16];

    printf("Boss battle start! Commands: attack, magic, heal, defend, flee\n");

    while (boss->health > 0 && player->health > 0) {
        printf("\nYour HP: %d | Beta Boss HP: %d\n", player->health, boss->health);
        printf("Your turn > ");
        if (scanf("%15s", action) != 1) {
            return;
        }
        to_lower_str(action);

        if (strcmp(action, "attack") == 0) {
            int damage = player_attacks(player);
            boss->health -= damage;
            printf("You hit the Beta Boss for %d damage!\n", damage);
        } else if (strcmp(action, "magic") == 0) {
            if (!player->has_magic_staff || player->magic_attack <= 0) {
                printf("You do not know any magic attack yet.\n");
                continue;
            }
            boss->health -= player->magic_attack;
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
            printf("You fled the boss battle.\n");
            return;
        } else {
            printf("Invalid action. Use attack, magic, heal, defend, or flee.\n");
            continue;
        }

        if (boss->health <= 0) {
            beta_boss_dies(boss);
            printf("You have defeated the Beta Boss!\n");
            return;
        }

        int boss_damage = beta_boss_attacks(boss);
        if (defending) {
            boss_damage -= 3;
            if (boss_damage < 0) {
                boss_damage = 0;
            }
            defending = 0;
        }

        player->health -= boss_damage;
        printf("Beta Boss attacks you for %d damage!\n", boss_damage);
        if (player->health <= 0) {
            player_dies(player);
            printf("You have been defeated by the Beta Boss.\n");
            return;
        }
    }
}

int beta_boss_attacks(BetaBoss* boss) {
    if (boss == NULL || boss->health <= 0) {
        return 0;
    }
    if (boss->attack > 0) {
        return boss->attack;
    }
    return 0;
}
