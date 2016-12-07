/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:32:58 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/07 13:01:10 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define ALLOC_CHAR 64
# define ALLOC_STR 16

signed char		ft_gnl(int fd, char **line);
void			ft_printf(char *str, ...);

int				ft_atoi(const char *str);

signed char		ft_freeret(void *ptr, signed char ret);
void			ft_freeswap(void **ptr, void *swap);
void			*ft_memalloc(unsigned int size);

void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(const char *str);

char			*ft_strchr(char *str, char c);
char			ft_strcmp(const char *s1, const char *s2);
char			ft_strncmp(const char *s1, const char *s2, unsigned int n);
void			ft_strcpy(char *dest, const char *src);
char			*ft_strdup(const char *str);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strcjoin(const char *s1, const char *s2, char c);
signed char		ft_strpush(char **str, char c);
unsigned int	ft_strlen(const char *str);

unsigned int	ft_strtablen(char **tab);
signed char		ft_strtabpush(char ***tab, char *str);
void			ft_strtabfree(char **tab);

#endif
