#include "lobby3.h"
#include "lobby.h"
#include "lobby2.h"
#include "lobby.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void to_lower_str(char *s) {
    while (*s != '\0') {
        *s = (char)tolower((unsigned char)*s);
        s++;
    }
}

void lobby3(Player* player) {
    while (1) {
        printf("Pick a room (8, 9, 10, 11, 12)):\n");
        char choice[16];
        if (scanf("%15s", choice) != 1) {
            return;
        }
        to_lower_str(choice);

        if (strcmp(choice, "lobby2") == 0) {
            lobby2(player);
        } else if (strcmp(choice, "back") == 0) {
            lobby(player);
            return;
        } else {
            printf("Unknown room: %s\n", choice);
        }
    }
}