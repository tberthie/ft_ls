/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:14:05 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/08 15:38:56 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

#include <stdio.h>

void			display_l(t_s **s, unsigned int o)
{
	o = 0;
	while (*s)
		ft_printf("%s\n", (*s++)->n);
}

void			display(t_s **s, unsigned int o)
{
	while (*s)
	{
		if ((*(*s)->n == '.' && !(o & A))
		|| ((S_ISDIR((*s)->s.st_mode) && (o & RR))))
		{
			s++;
			continue ;
		}
		ft_printf("%s\n", (*s++)->n);
	}
}
