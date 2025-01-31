
#####################################################
#####                   files                   #####
#####################################################

SRC =	src/push_swap.c \
		src/check.c \
		src/find_cheapest.c \
		src/push_cheapest.c \
		src/instructions.c \
		src/stack_manage.c \
		src/sort.c \
		src/sort_big.c \
		src/sort_utils.c \
		src/median_sort.c \

#####################################################
#####                 variables                 #####
#####################################################

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
HEADER = inc/push_swap.h
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRC:.c=.o)

#####################################################
#####                  commands                 #####
#####################################################

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I inc -I $(LIBFT_DIR)/inc -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re