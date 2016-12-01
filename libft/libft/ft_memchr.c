/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:36:26 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:36:30 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n && ((unsigned char*)s)[i] != (unsigned char)c)
		++i;
	return (i == n) ? NULL : (void*)(s + i);
}
