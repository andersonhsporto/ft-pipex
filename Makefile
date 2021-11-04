
NAME =	pipex

CC 	 =	clang

INCLUDE = -I ./includes
CFLAGS = -Wall -Wextra -Werror $(INCLUDE)

SRC = pipex.c
OBJ = $(SRC:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)


push:
	git add .
	read -p "Message:" message; \
	git commit -m "$$message"; \
	git push