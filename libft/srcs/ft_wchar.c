/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:52:19 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/30 13:45:23 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_charwlen(wchar_t c)
{
	if (c > 0x800)
		return (c > 0x10000 ? 4 : 3);
	return (c > 0x80 ? 2 : 1);
}

int		ft_strwlen(wchar_t *s)
{
	int		l;

	l = 0;
	while (*s++)
		l++;
	return (l);
}

void	ft_putwchar(wchar_t c)
{
	if (c > 0x10000)
		ft_putchar(((c & 0x1c0000) >> 18) + 0xF0);
	if (c > 0x800)
		ft_putchar(c > 0x10000 ? ((c & 0x03F000) >> 12) + 0x80 :
		((c & 0xF000) >> 12) + 0xE0);
	if (c > 0x80)
		ft_putchar(c > 0x800 ? ((c & 0x0Fc0) >> 6) + 0x80 :
		((c & 0x07c0) >> 6) + 0xc0);
	ft_putchar(c > 0x80 ? (c & 0x003F) + 0x80 : c);
}

void	ft_putwstr(wchar_t *s)
{
	while (*s)
		ft_putwchar(*s++);
}
