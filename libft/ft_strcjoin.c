/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:59:51 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/07 13:00:58 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*ft_strcjoin(const char *s1, const char *s2, char c)
{
	char	*str;
	char	*beg;

	if (!(str = (char*)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 2))))
		return ((char*)0);
	beg = str;
	while (*s1)
		*str++ = *s1++;
	*str++ = c;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (beg);
}
