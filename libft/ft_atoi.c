/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:32:04 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/04 15:32:06 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			nb;
	const char	*beg;

	while (*str < 33)
		++str;
	str += (*(beg = str) == '-' || *beg == '+') ? 1 : 0;
	nb = 0;
	while (*str > 47 && *str < 58)
		nb = nb * 10 + *str++ - '0';
	return (nb * (1 - 2 * (*beg == '-')));
}
