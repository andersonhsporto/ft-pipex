NAME =	pipex

CC 	 =	clang

INCLUDE = -I ./includes
CFLAGS = -Wall -Wextra

SRC =	pipex.c pipex_utils.c path_utils.c \
		error_pipex.c free_pipex.c ft_strtjoin.c

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

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
	rm -rf file2 test
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push

c:clean
	rm -rf test
	rm -rf file2
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) ./libft/libft.a -o test
	./test file1 "ls -l" "wc -l" file2
	cat file2

valgrind:fclean
	rm -rf test
	rm -rf file2
	$(CC) $(CFLAGS) $(INCLUDE) -g $(SRC) ./libft/libft.a -o test
	valgrind --leak-check=full --leak-resolution=med ./test file1 "ls -l" "wc -l" file2

error:fclean
	rm -rf test
	rm -rf file2
	$(CC) $(CFLAGS) $(INCLUDE) -g $(SRC) ./libft/libft.a -o test
	valgrind --leak-check=full --leak-resolution=med ./test file1 "casa" "wc" file2
