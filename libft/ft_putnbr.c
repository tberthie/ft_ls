/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:32:29 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/04 15:32:30 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

void	ft_putnbr(int nb)
{
	unsigned int	n;
	unsigned int	i;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = (unsigned int)-nb;
	}
	else
		n = (unsigned int)nb;
	i = 1;
	while (n / i > 9)
		i *= 10;
	while (i)
	{
		ft_putchar((char)(n / i % 10) + '0');
		i /= 10;
	}
}
