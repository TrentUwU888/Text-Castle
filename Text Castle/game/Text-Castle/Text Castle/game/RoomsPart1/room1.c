#include <stdio.h>
#include <string.h>
#include "room1.h"
#include "lobby.h"

void room1(Player* player) {
    while (1) {
        printf("\n=== ROOM 1 ===\n");
        printf("You enter room 1 and see a chest.\n");
        printf("Do you open it? (yes/no)\n");
        printf("> ");

        char choice[8];
        if (scanf("%7s", choice) != 1) {
            return;
        }

        printf("\n");

        if (strcmp(choice, "yes") == 0) {
            printf("Nahhhhhhhhhhhhhhhh you get eaten XD\n");
            printf("You died from a MAN EATING CHEST...\n\n");
            player_dies(player);
            return;
        } else if (strcmp(choice, "no") == 0) {
            printf("You decide to leave the chest alone and exit the room.\n\n");
            lobby(player);
            return;
        } else {
            printf("I don't understand that choice.\n");
        }
    }
}
