/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:41:56 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:42:09 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	if ((ptr = malloc(size)))
		while (size--)
			((char*)ptr)[size] = 0;
	return (ptr);
}
