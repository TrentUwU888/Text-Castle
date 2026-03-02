#include "room3.h"
#include "lobby.h"
#include "lobby2.h"
#include "bat.h"
#include "player.h"
#include <stdio.h>
#include <string.h>

void room3(Player* player) {
    if (player == NULL) {
        return;
    }
    if (!player->has_rusty_sword) {
        printf("The door to Room 3 is sealed. You need the Rusty Sword from Room 2.\n");
        lobby(player);
        return;
    }

    while (1) {
        printf("A bat tries to attack you!\n");
        printf("Attack or Flee? (attack/flee)\n");
        char choice[7];
        if (scanf("%6s", choice) != 1) {
            return;
        }
        if (strcmp(choice, "attack") == 0) {
            Bat bat = {30, 5};
            battle(&bat, player);
            lobby2(player);
            return;
        } else if (strcmp(choice, "flee") == 0) {
            printf("You fled from the bats.\n");
            lobby2(player);
            return;
        } else {
            printf("Invalid choice. Type attack or flee.\n");
        }
    }
}
