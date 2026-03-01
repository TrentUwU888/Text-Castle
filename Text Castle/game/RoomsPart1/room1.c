#include <stdio.h>
#include <string.h>
#include "room1.h"
#include "lobby.h"

void room1(void) {
    printf("\n=== ROOM 1 ===\n");
    printf("You enter room 1 and see a chest.\n");
    printf("Do you open it? (yes/no)\n");
    printf("> ");

    /* Clear leftover input from previous scanf/fgets */
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char choice[64];

    if (fgets(choice, sizeof(choice), stdin) == NULL) {
        return;
    }

    for (int i = 0; choice[i] != '\0'; i++) {
        if (choice[i] == '\r' || choice[i] == '\n') {
            choice[i] = '\0';
        }
        if (choice[i] >= 'A' && choice[i] <= 'Z') {
            choice[i] += 32;
        }
    }

    printf("\n");

    if (strcmp(choice, "yes") == 0) {
        printf("Nahhhhhhhhhhhhhhhh you get eaten XD\n");
        printf("You died from a MAN EATING CHEST...\n\n");
    }
    else if (strcmp(choice, "no") == 0) {
        printf("You decide to leave the chest alone and exit the room.\n\n");
        lobby();
    }
    else {
        printf("I don't understand that choice.\n");
    }
}