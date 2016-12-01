/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:56:27 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/29 13:05:55 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_itoabase_uns(unsigned long long n, int b, long long *f, char c)
{
	char				*s;
	unsigned long long	n2;
	int					l;

	l = 1;
	n2 = n;
	while (n2 >= (unsigned long long)b && (n2 /= b))
		l++;
	l = f && f[2] > l ? f[2] : l;
	if (!(s = ft_strnew(l--)))
		return (0);
	while (n >= (unsigned long long)b)
	{
		s[l--] = c == 'X' ?
		("0123456789ABCDEF")[n % b] : ("0123456789abcdef")[n % b];
		n /= b;
	}
	s[l--] = c == 'X' ? ("0123456789ABCDEF")[n % b] :
	("0123456789abcdef")[n % b];
	while (l >= 0)
		s[l--] = '0';
	return (f[2] == 0 && *s == '0' ? "" : s);
}
