/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:14:05 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/07 16:33:57 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void			display_l(t_s **s, unsigned int o)
{
	while (*s++)
	{
		
	}
}

void			filter(t_s **s, unsigned int o)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[i])
	{
		if (*s[i]->n == '.' && !(o & A) && (i += 1))
			continue ;
		if (S_ISDIR(s[i]->s.st_mode) && (o & R) && (i += 1))
			continue ;
		s[l++] = s[i++];
	}
	s[l] = 0;
}

void			display(t_s **s, unsigned int o)
{
	filter(s, o);
	if (o & L)
		display_l(s, o);
	else
	{
		while (*s)
		{
			ft_printf("%s\n", (*s++)->n);
		}
	}
}
