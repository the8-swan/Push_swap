
NAME = pushswap.a
CC = cc
SFLAGS = -Wall -Werror -Wetra 
SRC = helpers/ft_split.c helpers/input_validation.c helpers/core.c helpers/stacks.c helpers/rules.c
SRC_OBJ=$(SRC:.c=.o)

all:$(NAME)

sws : $(NAME)
	gcc main.c $(NAME) -o p
	rm -f $(NAME) $(SRC_OBJ)

$(NAME):$(SRC_OBJ)
	ar rcs $(NAME) $(SRC_OBJ)
clean:
	rm -f $(SRC_OBJ)

fclean:clean
	rm -f $(NAME)

re: clean fclean all re