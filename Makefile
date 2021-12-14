NAME =	pipex

CC = gcc

INCLUDE = -I ./includes
SOURCE = ./source/
SOURCE_UTILS = utils/
PIPE_UTILS = pipe_utils/
CFLAGS = -Wall -Wextra -Werror

P_UTILS = $(addprefix $(PIPE_UTILS), \
		pipex_utils.c path_utils.c \
		error_pipex.c free_pipex.c init.c \
)

UTILS = $(addprefix $(SOURCE_UTILS), \
		ft_memcmp.c ft_strdup.c ft_strtjoin.c ft_strjoin.c ft_split.c \
		ft_strlen.c ft_substr.c ft_strchr.c ft_strrchr.c ft_putstr_fd.c \
		ft_strnstr.c ft_strtrim.c \
)

SRC =	$(addprefix $(SOURCE), \
		$(P_UTILS) $(UTILS)\
		ft_pipex.c  \
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
	cat file1
	./pipex file1 "tr a b" "tr e ' '" file2
	cat file2

valgrind:fclean
	rm -rf file2
	$(CC) $(CFLAGS) $(INCLUDE) -g $(SRC) -o $(NAME)
	valgrind --leak-check=full ./pipex filex "tr e '~'" "tr '~' A" outfile

error:fclean
	rm -rf file2
	$(CC) $(CFLAGS) $(INCLUDE) -g $(SRC) -o $(NAME)
	valgrind --leak-check=full ./pipex file1 "casa" "testea" file2

t:re
	../pipex-tester/run.sh
