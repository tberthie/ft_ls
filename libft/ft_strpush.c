/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:44:08 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/06 14:19:37 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

signed char		ft_strpush(char **str, char c)
{
	char			*n_str;
	unsigned int	strlen;

	if (!(n_str =
	((strlen = ft_strlen(*str)) % ALLOC_CHAR) ?
	*str : (char*)malloc(sizeof(char) * (strlen + ALLOC_CHAR + 1))))
		return (-1);
	n_str[strlen] = c;
	n_str[strlen + 1] = '\0';
	if (n_str == *str)
		return (0);
	while (strlen--)
		n_str[strlen] = (*str)[strlen];
	free(*str);
	*str = n_str;
	return (0);
}
