NAME =	pipex

CC 	 =	clang

INCLUDE = -I ./includes
CFLAGS = -Wall -Wextra $(INCLUDE)

SRC = pipex.c pipex_utils.c
OBJ = $(SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	make all -C ./libft
	$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)

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

c:clean
	rm -rf test
	$(CC) $(CFLAGS) $(SRC) ./libft/libft.a -o test
	./test file0 ls -la file2