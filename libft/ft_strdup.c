/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 15:32:38 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/04 15:32:38 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char			*dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return ((char*)0);
	ft_strcpy(dup, str);
	return (dup);
}
