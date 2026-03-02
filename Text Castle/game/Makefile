CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iheaders
TARGET = game

SRC = main.c \
      RoomsPart1/room1.c \
      RoomsPart1/room2.c \
      RoomsPart1/room3.c \
      RoomsPart2/lobby2.c \
      RoomsPart2/room4.c \
      RoomsPart2/room5.c \
      RoomsPart2/room6.c \

OBJ = $(SRC:.c=.o) bat.o goblin.o player.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bat.o: enemy\ logic/bat.c
	$(CC) $(CFLAGS) -c "$<" -o "$@"

goblin.o: enemy\ logic/goblin.c
	$(CC) $(CFLAGS) -c "$<" -o "$@"

player.o: player\ logic/player.c
	$(CC) $(CFLAGS) -c "$<" -o "$@"

clean:
	rm -f $(OBJ) $(TARGET)
