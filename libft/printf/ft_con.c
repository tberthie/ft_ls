/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_con_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:46:07 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/29 16:21:00 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char		*ft_con_int(long long i, long long *f)
{
	unsigned long long	i2;
	char				*r;
	int					l;

	i2 = i < 0 ? -i : i;
	l = 1;
	while (i2 >= 10 && (i2 /= 10))
		l++;
	l = f[2] > l ? f[2] : l;
	if (!(r = ft_strnew(l-- + (i < 0))))
		return (0);
	i2 = i < 0 ? -i : i;
	while (i2 >= 10)
	{
		r[l-- + (i < 0)] = (char)(i2 % 10 + '0');
		i2 /= 10;
	}
	r[l-- + (i < 0)] = (char)(i2 % 10 + '0');
	while (l >= 0)
		r[l-- + (i < 0)] = '0';
	*r = i < 0 ? '-' : *r;
	return (f[2] == 0 && *r == '0' ? "" : r);
}

char		*ft_con_uns(char s, unsigned long long i, long long *f)
{
	if (s == 'u' || s == 'U')
		return (ft_itoabase_uns(i, 10, f, s));
	if (s == 'o' || s == 'O')
		return (ft_itoabase_uns(i, 8, f, s));
	if (s == 'x' || s == 'X')
		return (ft_itoabase_uns(i, 16, f, s));
	return (0);
}

int			ft_con_ptr(va_list ap, long long f, int *c)
{
	if (f >> 5 & 1)
		*(signed char*)va_arg(ap, int*) = *c;
	else if (f >> 6 & 1)
		*(short*)va_arg(ap, int*) = *c;
	else if (f >> 7 & 1)
		*va_arg(ap, long long*) = *c;
	else if (f >> 8 & 1)
		*va_arg(ap, long*) = *c;
	else if (f >> 9 & 1)
		*va_arg(ap, intmax_t*) = *c;
	else if (f >> 10 & 1)
		*va_arg(ap, size_t*) = *c;
	else
		*va_arg(ap, int*) = *c;
	return (1);
}
