#include <stdio.h>
#include <string.h>
#include "room2.h"
#include "lobby.h"

void room2(Player* player) {
    printf("You found a rusty sword... Do you wanna pick it up? (yes/no)\n");
    char choice[4];
    if (scanf("%3s", choice) != 1) {
        return;
    }

    if (strcmp(choice, "yes") == 0) {
        player->has_rusty_sword = 1;
        printf("You pick up the rusty sword. Rusty Sword in inventory.\n");
        lobby(player);
    } else if (strcmp(choice, "no") == 0) {
        printf("You leave the rusty sword where it is.\n");
        lobby(player);
    } else {
        printf("You don't have a choice BTW...\n");
    }
}
