/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:32:19 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/04 15:32:20 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	*ft_memalloc(unsigned int size)
{
	char	*mem;

	if (!(mem = (char*)malloc(size)))
		return ((void*)0);
	while (size--)
		mem[size] = 0;
	return ((void*)mem);
}
