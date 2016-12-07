LIB = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strndup.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_itoa.c \
	  ft_strsplit.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_countwords.c \
	  ft_isspace.c \
	  ft_lstpush.c \
	  ft_freeret.c \
	  ft_wchar.c \
	  get_next_line.c \

PRINTF = ft_printf.c \
		 ft_format.c \
		 ft_cast.c \
		 ft_con.c \
		 ft_wchar.c \
		 ft_utl.c \
		 ft_color.c

OBJ = $(addprefix libft/, $(LIB:.c=.o))
PF_OBJ = $(addprefix printf/, $(PRINTF:.c=.o))

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
INCS = includes

all: $(NAME)

$(NAME): $(OBJ) $(PF_OBJ)
	@ar -rsc $(NAME) $(OBJ) $(PF_OBJ)

libft/%.o: libft/%.c
	@$(CC) $(FLAGS) -I $(INCS) -o $@ -c $<

printf/%.o: printf/%.c
	@$(CC) $(FLAGS) -I $(INCS) -o $@ -c $<

clean:
	@rm -f $(OBJ) $(PF_OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
