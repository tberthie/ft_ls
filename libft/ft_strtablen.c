/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtablen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:21:09 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/06 12:50:42 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strtablen(char **tab)
{
	char	**beg;

	beg = tab;
	while (*tab)
		++tab;
	return ((unsigned int)(tab - beg));
}
