#include "room5.h"
#include "lobby2.h"
#include <stdio.h>
#include <string.h>

void room5(Player* player) {
    if (player == NULL) {
        return;
    }

    if (player->has_heal_spell) {
        printf("You already learned Heal Spell from this room.\n");
        lobby2(player);
        return;
    }

    printf("You walk into Room 5 and find a spell book.\n");
    while (1) {
        char choice[8];
        printf("Learn Heal Spell? (yes/no)\n> ");
        if (scanf("%7s", choice) != 1) {
            return;
        }

        if (strcmp(choice, "yes") == 0) {
            player->has_heal_spell = 1;
            printf("You learned Heal Spell! You can now heal yourself in battle.\n");
            lobby2(player);
            return;
        } else if (strcmp(choice, "no") == 0) {
            printf("You leave the spell book alone.\n");
            lobby2(player);
            return;
        } else {
            printf("Invalid choice. Type yes or no.\n");
        }
    }
}
