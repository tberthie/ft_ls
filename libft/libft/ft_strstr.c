/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:38:07 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:38:08 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	size;

	if (!*needle)
		return ((char*)haystack);
	size = ft_strlen(needle);
	while (*haystack && ft_strncmp(haystack, needle, size))
		++haystack;
	return (ft_strncmp(haystack, needle, size)) ? NULL : (char*)haystack;
}
