CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = main.c sort_album_by.c album.h push_back_album.c create_album.c my_atoi.c my_strcmp.c print_album.c my_strlen.c my_itoa.c
OBJ = $(SRC:.c=.o)
EXEC = music

.PHONY: all clean fclean run

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(EXEC)

run: $(EXEC)
	./$(EXEC)