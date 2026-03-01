CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -Iheaders
TARGET = game

SRC = main.c \
      RoomsPart1/room1.c \
      RoomsPart1/room2.c \
      RoomsPart1/room3.c \

OBJ = $(SRC:.c=.o) bat.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bat.o: enemy\ logic/bat.c
	$(CC) $(CFLAGS) -c "$<" -o "$@"

clean:
	rm -f $(OBJ) $(TARGET)
