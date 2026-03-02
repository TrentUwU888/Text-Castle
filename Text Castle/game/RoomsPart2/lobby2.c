#include "lobby2.h"
#include "room4.h"
#include "room5.h"
#include "room6.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

static void to_lower_str(char *s) {
    while (*s != '\0') {
        *s = (char)tolower((unsigned char)*s);
        s++;
    }
}

void lobby2(Player* player) {
    while (1) {
        printf("Pick a room (4/5/6 or room4/room5/room6):\n");
        char choice[16];
        if (scanf("%15s", choice) != 1) {
            return;
        }
        to_lower_str(choice);

        if (strcmp(choice, "room4") == 0 || strcmp(choice, "4") == 0) {
            room4(player);
            return;
        } else if (strcmp(choice, "room5") == 0 || strcmp(choice, "5") == 0) {
            room5(player);
            return;
        } else if (strcmp(choice, "room6") == 0 || strcmp(choice, "6") == 0) {
            room6(player);
            return;
        } else {
            printf("Unknown room: %s\n", choice);
        }
    }
}
