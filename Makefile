
#####################################################
#####                   files                   #####
#####################################################

SRC =		src/push_swap.c \
			src/check.c \
			src/find_cheapest.c \
			src/push_cheapest.c \
			src/instructions.c \
			src/stack_manage.c \
			src/sort.c \
			src/sort_big.c \
			src/sort_utils.c \
			src/median_sort.c

BONUS =		src/checker.c \
			src/check.c \
			src/find_cheapest.c \
			src/push_cheapest.c \
			src/instructions.c \
			src/stack_manage.c \
			src/sort.c \
			src/sort_big.c \
			src/sort_utils.c \
			src/median_sort.c

#####################################################
#####                 variables                 #####
#####################################################

NAME				= 			push_swap
CHECKER				= 			checker
CC					= 			cc
CFLAGS				= 			-Wall -Werror -Wextra -g3
HEADER				= 			inc/push_swap.h
LIBFT_DIR			= 			libft
LIBFT				= 			libft/libft.a

OBJ_DIR				= 			obj
OBJ					= 			$(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
OBJ_BONUS			= 			$(addprefix $(OBJ_DIR)/, $(notdir $(BONUS:.c=.o)))

#####################################################
#####                  commands                 #####
#####################################################

all: $(NAME)

$(NAME): lib
	$(MAKE) .compile

$(CHECKER): $(OBJ_BONUS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_BONUS) -L $(LIBFT_DIR) -lft -o $(CHECKER)

$(OBJ_DIR)/%.o : src/%.c $(HEADER) libft/inc/libft.h | $(OBJ_DIR)
		$(CC) $(CFLAGS) -I inc -I $(LIBFT_DIR)/inc -o $@ -c $<

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

.compile: $(OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT_DIR) -lft -o $(NAME)
		@touch .compile

lib:
		@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

bonus: $(CHECKER)

clean:
		rm -rf $(OBJ_DIR)
		$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -f $(NAME) checker
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus