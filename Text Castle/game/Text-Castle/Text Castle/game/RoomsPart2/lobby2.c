#include "lobby2.h"
#include "lobby.h"
#include "room4.h"
#include "room5.h"
#include "room6.h"
#include "room7.h"
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
        printf("Pick a room (4/5/6/7 or room4/room5/room6/room7, or back):\n");
        char choice[16];
        if (scanf("%15s", choice) != 1) {
            return;
        }
        to_lower_str(choice);

        if (strcmp(choice, "room4") == 0 || strcmp(choice, "4") == 0) {
            room4(player);
        } else if (strcmp(choice, "room5") == 0 || strcmp(choice, "5") == 0) {
            room5(player);
        } else if (strcmp(choice, "room6") == 0 || strcmp(choice, "6") == 0) {
            room6(player);
        } else if (strcmp(choice, "room7") == 0 || strcmp(choice, "7") == 0) {
            room7(player);
        } else if (strcmp(choice, "back") == 0) {
            lobby(player);
            return;
        } else {
            printf("Unknown room: %s\n", choice);
        }
    }
}
