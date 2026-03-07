#include "room6.h"
#include "bat.h"
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

void room6(Player* player) {
    if (player == NULL) {
        return;
    }
    if (player->health <= 0) {
        printf("You are too weak to enter Room 6.\n");
        return;
    }

    printf("You walk into Room 6. Two bats and a goblin rush you.\n");
    printf("Fight or flee? (fight/flee)\n");

    while (1) {
        char choice[16];
        printf("> ");
        if (scanf("%15s", choice) != 1) {
            return;
        }
        to_lower_str(choice);

        if (strcmp(choice, "fight") == 0) {
            Bat bat1 = {20, 3};
            Bat bat2 = {20, 3};
            Goblin captain = {40, 5};

            printf("Bat #1 attacks!\n");
            bat_battle(&bat1, player);
            if (player->health <= 0) {
                printf("You were defeated in Room 6.\n");
                return;
            }
            if (bat1.health > 0) {
                printf("You escaped Room 6.\n");
                return;
            }

            printf("Bat #2 attacks!\n");
            bat_battle(&bat2, player);
            if (player->health <= 0) {
                printf("You were defeated in Room 6.\n");
                return;
            }
            if (bat2.health > 0) {
                printf("You escaped Room 6.\n");
                return;
            }

            printf("Goblin captain attacks!\n");
            battle(&captain, player);
            if (player->health <= 0) {
                printf("You were defeated in Room 6.\n");
                return;
            }
            if (captain.health <= 0) {
                printf("You cleared Room 6.\n");
            } else if (player->health > 0) {
                printf("You escaped Room 6.\n");
            }
            return;
        }

        if (strcmp(choice, "flee") == 0) {
            printf("You fled back to the lobby.\n");
            return;
        }

        printf("Invalid choice. Type fight or flee.\n");
    }
}
