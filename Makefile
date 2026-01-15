
NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -I includes
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
		src/helpers/helper.c

PUSH_SWAP_SRC =\
				src/ps/main.c \
				$(HELPERS) \

BONUS_SRC = \
			src/bonus/checker_utils_bonus.c \
			src/bonus/checker_bonus.c \
			src/bonus/rules_bonus.c \
			src/bonus/get_next_line_bonus.c \
			src/bonus/get_next_line_utils_bonus.c \
			src/bonus/helper_bonus.c\
			$(HELPERS)

all : $(NAME)
bonus : $(BONUS)

$(NAME) : $(PUSH_SWAP_SRC)
	@$(CC) $(CFLAGS) $^ -o $@

$(BONUS) : $(BONUS_SRC)
	@$(CC) $(CFLAGS) $^ -o $@

clean:
	@rm -f $(NAME) 

fclean: clean
	@rm -f $(BONUS)

re : fclean all

.PHONY : fclean re clean all