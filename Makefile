
NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -Iincludes
HELPERS = src/helpers/ft_split.c \
		src/helpers/input_validation.c \
		src/helpers/core.c \
		src/helpers/positional_utils.c \
		src/helpers/stacks.c \
		src/helpers/rules.c \
		src/helpers/rules_utils.c \
		src/helpers/pre_sort.c \
		src/helpers/stack_utils.c \
		src/helpers/free.c \
		src/helpers/extra.c \

PUSH_SWAP_SRC =\
				src/ps/main.c \
				$(HELPERS) \

BONUS_SRC = \
			src/bonus/checker_utils.c \
			src/bonus/checker.c \
			src/bonus/rules_bonus.c \
			src/bonus/gnl/get_next_line.c \
			src/bonus/gnl/get_next_line_utils.c \
			$(HELPERS)

PUSH_SWAP_SRC_OBJ = $(PUSH_SWAP_SRC:.c=.o)
BONUS_SRC_OBG = $(BONUS_SRC:.c=.o)

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(PUSH_SWAP_SRC_OBJ)
	@$(CC) $(CFLAGS) $^ -o $@

$(BONUS) : $(BONUS_SRC_OBG)
	@$(CC) $(CFLAGS) $^ -o $@

%.o : %.c 
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(PUSH_SWAP_SRC_OBJ) $(BONUS_SRC_OBG)

fclean: clean
	@rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : fclean re clean all