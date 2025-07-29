NAME = bsq
SRC = bsq.c main.c map_file.c ending.c
OBJ = src/$(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all