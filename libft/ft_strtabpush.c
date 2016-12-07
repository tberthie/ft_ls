/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabpush.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:31:53 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/06 19:03:06 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

signed char		ft_strtabpush(char ***tab, char *str)
{
	char			**n_tab;
	unsigned int	tablen;

	if (!(n_tab =
	((tablen = ft_strtablen(*tab)) % ALLOC_STR) ?
	*tab : (char**)malloc(sizeof(char*) * (tablen + ALLOC_STR + 1))))
		return (-1);
	n_tab[tablen] = str;
	n_tab[tablen + 1] = (char*)0;
	if (n_tab == *tab)
		return (0);
	while (tablen--)
		n_tab[tablen] = (*tab)[tablen];
	free(*tab);
	*tab = n_tab;
	return (0);
}
