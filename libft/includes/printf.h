/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:02:18 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/30 17:35:19 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

int			ft_format(char *s, long long *f, va_list ap, int *c);

char		*ft_cast_int(char s, va_list ap, long long *f);
char		*ft_cast_uns(char s, va_list ap, long long *f);
char		*ft_cast_str(char s, va_list ap);
int			ft_cast_wch(char s, va_list ap, long long *f, int *c);

char		*ft_con_int(long long i, long long *f);
char		*ft_con_uns(char s, unsigned long long i, long long *f);
int			ft_con_ptr(va_list ap, long long f, int *c);

char		*ft_itoabase_uns(unsigned long long n, int b, long long *f, char c);
int			ft_color(char *s, int i, int *c);

#endif
