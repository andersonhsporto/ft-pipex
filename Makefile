NAME =	pipex

CC 	 =	clang

INCLUDE = -I ./includes
SOURCE = ./source/
SOURCE_UTILS = utils/
CFLAGS = -Wall -Wextra  #-Werror

UTILS = $(addprefix $(SOURCE_UTILS), \
		ft_memcmp.c ft_strdup.c ft_strtjoin.c ft_strjoin.c ft_split.c \
		ft_strlen.c ft_substr.c ft_strchr.c ft_strrchr.c ft_putstr_fd.c \
)

SRC =	$(addprefix $(SOURCE), \
		$(UTILS) \
		pipex.c pipex_utils.c path_utils.c \
		error_pipex.c free_pipex.c \
)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	rm -rf $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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

c:fclean
	rm -rf file2
	$(CC) $(CFLAGS) $(INCLUDE) $(SRC) -o $(NAME)
	./pipex file1 "ls -l" "wc -l" file2
	cat file2

valgrind:fclean
	rm -rf file2
	$(CC) $(CFLAGS) $(INCLUDE) -g $(SRC) -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./pipex file1 "ls -l" "wc -l" file2

error:fclean
	rm -rf file2
	$(CC) $(CFLAGS) $(INCLUDE) -g $(SRC) -o $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all ./pipex file1 "casa" "testea" file2

t:re
	../pipex-tester/run.sh