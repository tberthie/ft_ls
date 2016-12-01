/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:37:51 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:37:53 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && *s1++ == *s2++ && *(s1 - 1))
		;
	return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
}
