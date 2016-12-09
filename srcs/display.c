/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:14:05 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/09 16:59:05 by tberthie         ###   ########.fr       */
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
	else
		ft_printf("{cyan}");
}

/*long			getdims(int size, int len)
{
	struct winsize	ws;
	int				width;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
	width = ws.ws_col / (len + 1);
	return (size / width + (size % width ? 1 : 0));
}*/

/*void			display_n(t_s **s, unsigned int o)
{
}*/

void			display(t_s **s, unsigned int o, char *p)
{
//	if (o & L)
		display_l(s, o, p);
/*	else
		display_n(s, o);*/
}
