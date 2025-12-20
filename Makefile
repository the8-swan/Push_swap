
NAME = pushswap.a
CC = cc
SFLAGS = -Wall -Werror -Wetra 
SRC = helpers/ft_split.c
SRC_OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(SRC_OBJ)
	ar rcs $(NAME) $(SRC_OBJ)
clean:
	rm -f $(SRC_OBJ)

fclean:clean
	rm -f $(NAME)

re: clean fclean all re