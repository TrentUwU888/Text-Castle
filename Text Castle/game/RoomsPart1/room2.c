#include <stdio.h>
#include <string.h>
#include "room2.h"
#include "lobby.h"

void room2(void) {
    printf("You found a rusty sword... Do you wanna pick it up? (yes/no)\n");
    char choice[4];
    if (scanf("%3s", choice) != 1) {
        return;
    }

    if (strcmp(choice, "yes") == 0) {
        printf("You pick up the rusty sword. Rusty Sword in inventory.\n");
        lobby();
    } else if (strcmp(choice, "no") == 0) {
        printf("You leave the rusty sword where it is.\n");
        lobby();
    } else {
        printf("You don't have a choice BTW...\n");
    }
}
