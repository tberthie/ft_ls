/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:36:45 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:36:47 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	signed char	op;
	int			i;
	int			lim;

	op = 1 - 2 * (dest - src >= 0 && dest - src < (int)n);
	lim = (op == 1) ? (int)n : -1;
	i = (op == 1) ? 0 : (int)n - 1;
	while (i != lim)
	{
		((char*)dest)[i] = ((const char*)src)[i];
		i += op;
	}
	return (dest);
}
