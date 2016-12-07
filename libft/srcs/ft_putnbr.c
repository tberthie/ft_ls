/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:07:09 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/26 15:35:51 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	unsigned int	n2;

	if (n < 0)
		ft_putchar('-');
	n2 = (n < 0 ? -n : n);
	if (n2 >= 10)
	{
		ft_putnbr(n2 / 10);
		ft_putchar(n2 % 10 + '0');
	}
	else
		ft_putchar(n2 + '0');
}
