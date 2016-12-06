#ifndef LIBFT_H
# define LIBFT_H

int				ft_atoi(const char *str);

signed char		ft_freeret(void *ptr, signed char ret);

void			*ft_memalloc(unsigned int size);

void			ft_printf(char *str, ...);

void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(const char *str);

char			*ft_strchr(char *str, char c);
char			ft_strcmp(const char *s1, const char *s2);
void			ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
unsigned int	ft_strlen(const char *str);


#endif
