/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:58:31 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:37:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	n2;

	if (n < 0)
		ft_putchar_fd('-', fd);
	n2 = (n < 0 ? -n : n);
	if (n2 >= 10)
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putchar_fd(n2 % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n2 + '0', fd);
}
