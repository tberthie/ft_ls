/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:19:45 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/30 14:30:54 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_fields(char *s, long long *f, va_list ap)
{
	int		m;
	int		p;
	int		i;

	m = 0;
	i = 0;
	if (*s == '*' && (i += 1))
		m = va_arg(ap, int);
	m = (s[i] >= '0' && s[i] <= '9') ? 0 : m;
	while (s[i] >= '0' && s[i] <= '9')
		m += m * 9 + s[i++] - '0';
	if (s[i] == '*' && (i += 1))
		m = va_arg(ap, int);
	f[1] = m < 0 ? -m : m;
	if (m < 0 && (*f |= 1 << 2))
		*f |= 1 << 2;
	p = -1;
	while (s[i] == '.')
		if (s[i] == '.' && s[i + 1] == '*' && (i += 2))
			p = va_arg(ap, int);
		else if (s[i] == '.' && (i += 1) && !(p = 0))
			while (s[i] >= '0' && s[i] <= '9')
				p += p * 9 + s[i++] - '0';
	f[2] = p < -1 ? -1 : p;
	return (i);
}

static int			ft_flags(char *s, long long *f, int p)
{
	while ((s[p] == '#' && (*f |= 1)) || (s[p] == '0' &&
	(*f |= 1 << 1)) || (s[p] == '-' && (*f |= 1 << 2)) || (s[p] == '+' &&
	(*f |= 1 << 3)) || (s[p] == ' ' && (*f |= 1 << 4)))
		++p;
	return (p);
}

static int			ft_mod(char *s, long long *f, int p, int i)
{
	while ((s[p + i] == 'h' && (s[p + i + 1] == 'h') && (*f |= 1 << 5) &&
	(p += 1)) || ((s[p + i] == 'h') && (*f |= 1 << 6)) || ((s[p + i] == 'l' &&
	s[p + i + 1] == 'l') && (*f |= 1 << 7) && (p += 1)) ||
	((s[p + i] == 'l') && (*f |= 1 << 8)) || ((s[p + i] == 'j') &&
	(*f |= 1 << 9)) || ((s[p + i] == 'z') && (*f |= 1 << 10)))
		p += 1;
	return (p);
}

static int			ft_parse(char *s, int i, va_list ap, int *c)
{
	long long	f[3];
	int			p;
	int			r;

	f[0] = 0;
	p = 0;
	r = 0;
	if (!s[i])
		return (i);
	p = ft_flags(&s[i], f, p);
	p += ft_fields(&s[p + i], f, ap);
	p = ft_flags(&s[i], f, p);
	p = ft_mod(s, f, p, i);
	p = ft_flags(&s[i], f, p);
	if (!s[p + i])
		return (p + i);
	if (s[p + i] && !(r = ft_format(&s[p + i], f, ap, c)))
		return (0);
	else if (!s[p + i] || r != -1)
		return (p + i + 1);
	return (i);
}

int					ft_printf(const char *s, ...)
{
	va_list			ap;
	int				c[1];
	int				i;

	i = 0;
	*c = 0;
	va_start(ap, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			if (!(i = ft_parse((char*)s, i + 1, ap, c)))
				return (-1);
		}
		else if (s[i] == '{')
			i = ft_color((char*)s, i, c);
		else if (((*c) += 1))
			write(1, &s[i++], 1);
	}
	va_end(ap);
	return (*c);
}
