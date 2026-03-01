#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "headers/room1.h"
#include "headers/room2.h"
#include "headers/room3.h"
#include "headers/lobby.h"
#include "headers/player.h"


static void to_lower_str(char *s) {
    while (*s != '\0') {
        *s = (char)tolower((unsigned char)*s);
        s++;
    }
}

static void start_game(Player* player) {
    printf("You walk in the castle and there's 3 rooms.\n");
    printf("Pick a room (1/2/3 or room1/room2/room3):\n");

    char choice[16];
    if (scanf("%15s", choice) != 1) {
        return;
    }
    to_lower_str(choice);

    if (strcmp(choice, "room1") == 0 || strcmp(choice, "1") == 0) {
        room1(player);
    } else if (strcmp(choice, "room2") == 0 || strcmp(choice, "2") == 0) {
        room2(player);
    } else if (strcmp(choice, "room3") == 0 || strcmp(choice, "3") == 0) {
        room3(player);
    } else {
        printf("Unknown room: %s\n", choice);
    }
}

void lobby(Player* player) {
    printf("Pick a room (1/2/3 or room1/room2/room3):\n");
    char choice[16];
    if (scanf("%15s", choice) != 1) {
        return;
    }
    to_lower_str(choice);

    if (strcmp(choice, "room1") == 0 || strcmp(choice, "1") == 0) {
        room1(player);
    } else if (strcmp(choice, "room2") == 0 || strcmp(choice, "2") == 0) {
        room2(player);
    } else if (strcmp(choice, "room3") == 0 || strcmp(choice, "3") == 0) {
        room3(player);
    } else {
        printf("Unknown room: %s\n", choice);
    }
}

int main() {
    Player player = {40, 6, 0};

    printf("Type 'start' to play:\n");
    char command[16];
    if (scanf("%15s", command) != 1) {
        return 0;
    }
    to_lower_str(command);

    if (strcmp(command, "start") == 0) {
        start_game(&player);
    } else {
        printf("Game not started.\n");
    }
    return 0;
}
