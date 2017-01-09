SRCS = main.c \
	   ft_ls.c \
	   utl.c \
	   files.c \
	   output.c \
	   print.c \

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

NAME = ft_ls
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCS = includes -I libft

all: $(NAME)

$(NAME): $(OBJS)
	@echo "[compiling libft]"
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) libft/libft.a $(OBJS)
	@echo "[$(NAME)]"

srcs/%.o: srcs/%.c
	@$(CC) $(FLAGS) -I $(INCS) -I libft/includes -o $@ -c $<
	@echo "[$@]"

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@echo "[objs removed]"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "[workspace clean]"

re: fclean all
