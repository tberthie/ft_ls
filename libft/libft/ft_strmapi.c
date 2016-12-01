/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 17:18:46 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:37:47 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	while (*s)
	{
		new[i] = f(i, *s++);
		i++;
	}
	new[i] = '\0';
	return (new);
}
