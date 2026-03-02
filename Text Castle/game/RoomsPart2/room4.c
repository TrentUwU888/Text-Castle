#include "room4.h"
#include "lobby2.h"
#include <stdio.h>
#include <string.h>

void room4(Player* player) {
    if (player == NULL) {
        return;
    }

    printf("You enter Room 4. A glowing chest sits in the center.\n");

    if (player->has_magic_staff) {
        printf("The chest is empty. You already took the Magic Staff.\n");
        lobby2(player);
        return;
    }

    while (1) {
        char choice[8];
        printf("Open the chest? (yes/no)\n> ");
        if (scanf("%7s", choice) != 1) {
            return;
        }

        if (strcmp(choice, "yes") == 0) {
            player->has_magic_staff = 1;
            player->magic_attack = 12;
            printf("You obtained the Magic Staff! Magic attack unlocked.\n");
            lobby2(player);
            return;
        }

        if (strcmp(choice, "no") == 0) {
            printf("You leave the chest alone.\n");
            lobby2(player);
            return;
        }

        printf("Invalid choice. Type yes or no.\n");
    }
}
