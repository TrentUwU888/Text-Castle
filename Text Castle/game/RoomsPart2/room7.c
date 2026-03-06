#include "room7.h"
#include "lobby2.h"
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

void room7(Player* player) {
    if (player == NULL) {
        return;
    }
    BetaBoss boss = {50, 9};
    printf("You are on your way out of the first two lobbies when an undead guard approaches you. \"HEY! WHAT ARE YOU DOING HERE?!\" the guard shouts. You stare at him, and both of you get ready to fight. (fight/flee)\n");

    while (1) {
        char choice[16];
        printf("> ");
        if (scanf("%15s", choice) != 1) {
            return;
        }
        to_lower_str(choice);

        if (strcmp(choice, "fight") == 0) {
            beta_boss_battle(&boss, player);
            return;
        }
        if (strcmp(choice, "flee") == 0) {
            printf("You fled from the boss.\n");
            return;
        }
        printf("Invalid choice. Type fight or flee.\n");
    }
}
