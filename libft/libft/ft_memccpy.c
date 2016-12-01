/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:36:21 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:36:24 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i++] == (unsigned char)c)
			return (dest + i);
	}
	return (NULL);
}
