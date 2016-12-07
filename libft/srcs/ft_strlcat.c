/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:37:39 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:37:40 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	ret;
	size_t	i;

	i = ft_strlen(dest);
	ret = i + ft_strlen(src);
	if (i >= n)
		return (ret - i + n);
	--n;
	while (*src && i != n)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (ret);
}
