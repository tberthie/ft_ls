/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:57:14 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/01 21:25:52 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int			err_ret(char *s, int r)
{
	perror(s);
	return (r);
}

void		sort(char **d, unsigned int o, int s)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i++ < s && (j = i))
		while (j++ < s)
			if (((o & R) && ft_strcmp(d[i - 1], d[j - 1]) < 0) &&
			(tmp = d[i - 1]) && (d[i - 1] = d[j - 1]))
				d[j - 1] = tmp;
}
