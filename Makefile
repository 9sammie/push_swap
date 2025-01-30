
#####################################################
#####                   files                   #####
#####################################################

SRC =	src/push_swap.c \
		src/checks.c \
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
	make -c $(LIBFT_DIR)

$(OBJ) %.o: %.c $(HEADER) makefile
	$(CC) $(CFLAGS) -I 4(LIBFT_DIR) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re