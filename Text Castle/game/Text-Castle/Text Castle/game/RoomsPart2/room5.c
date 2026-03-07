#include "room5.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void to_lower_str(char *s) {
    while (*s != '\0') {
        *s = (char)tolower((unsigned char)*s);
        s++;
    }
}

void room5(Player* player) {
    if (player == NULL) {
        return;
    }

    if (player->has_heal_spell) {
        printf("You already learned Heal Spell from this room.\n");
        return;
    }

    printf("You walk into Room 5 and find a spell book.\n");
    while (1) {
        char choice[8];
        printf("Learn Heal Spell? (yes/no)\n> ");
        if (scanf("%7s", choice) != 1) {
            return;
        }
        to_lower_str(choice);

        if (strcmp(choice, "yes") == 0) {
            player->has_heal_spell = 1;
            printf("You learned Heal Spell! You can now heal yourself in battle.\n");
            return;
        } else if (strcmp(choice, "no") == 0) {
            printf("You leave the spell book alone.\n");
            return;
        } else {
            printf("Invalid choice. Type yes or no.\n");
        }
    }
}
