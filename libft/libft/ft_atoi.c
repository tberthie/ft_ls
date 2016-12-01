/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:42:17 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/25 19:57:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int neg;
	int	nbr;

	nbr = 0;
	while (ft_isspace(*str))
		str++;
	neg = (*str == '-' ? -1 : 1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
		nbr = (nbr * 10 + *str++ - '0');
	return (neg * nbr);
}
