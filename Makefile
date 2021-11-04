NAME =	pipex

CC 	 =	clang

INCLUDE = -I ./includes
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

SRC = pipex.c
OBJ = $(SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf ./a.out

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

push:fclean
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push