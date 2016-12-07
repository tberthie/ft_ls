/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:32:25 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/04 15:32:26 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <unistd.h>

void	ft_printf(char *str, ...)
{
	va_list		ap;
	char		*percent;

	va_start(ap, str);
	while ((percent = ft_strchr(str, '%')))
	{
		if (percent != str)
			write(1, str, (unsigned int)(percent - str));
		if (*++percent == 's')
			ft_putstr(va_arg(ap, const char*));
		else if (*percent == 'i')
			ft_putnbr(va_arg(ap, int));
		else if (*percent == 'c')
			ft_putchar((char)va_arg(ap, int));
		str = percent + 1;
	}
	if (*str)
		ft_putstr(str);
}
