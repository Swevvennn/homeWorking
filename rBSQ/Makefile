NAME = bsq
SRC = src/main.c src/solver_filler.c src/struct_funcs.c src/utils.c src/utils2.c src/validity_check_utils.c src/validity_checker.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^