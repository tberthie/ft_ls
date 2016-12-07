SRC=$(addsuffix .c,\
	gnl printf\
	atoi\
	freeret freeswap memalloc\
	putchar putnbr putstr\
	strchr strcmp strncmp strcpy strdup strjoin strcjoin strpush strlen\
	strtablen strtabpush strtabfree)
OBJ=$(addprefix ft_,$(SRC:.c=.o))
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

%.o: %.c
	@gcc -c $< -o $@ -Weverything -Wall -Wextra -Werror

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
