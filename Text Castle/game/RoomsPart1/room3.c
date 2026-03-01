#include "room3.h"
#include "lobby.h"
#include "bat.h"
#include <stdio.h>
#include <string.h>

void room3(void) {
    printf("A bat trys to attack you!\n");
    printf("Attack or Flee? (attack/flee)\n");
    char choice[7];
    if (scanf("%6s", choice) != 1) {
        return;
    }
    if (strcmp(choice, "attack") == 0) {
        Bat bat = {30, 5}; // Example stats for the bat
        battle(&bat);
    } else if (strcmp(choice, "flee") == 0) {
        printf("You fleed from the bats\n");
        lobby();
    } else {
        printf("You don't have a choice BTW...\n");
    }
}
