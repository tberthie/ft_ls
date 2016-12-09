/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:14:05 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/09 17:29:51 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

void			setcolor(t_s *s)
{
	if (S_ISDIR(s->s.st_mode))
		ft_printf("{green}");
	else if (S_ISLNK(s->s.st_mode))
		ft_printf("{magenta}");
}

void			display(t_s **s, unsigned int o, char *p)
{
	if (o & L)
		display_l(s, p);
	else
		while (*s)
		{
			setcolor(*s);
			ft_printf("%s\n", (*s++)->n);
		}
}
