SRC=$(addsuffix .c,atoi freeret memalloc printf putchar putnbr putstr strchr strcmp strcpy strdup strjoin strlen)
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
