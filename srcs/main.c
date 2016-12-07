/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:40:48 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/07 16:34:18 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <unistd.h>

static int		parse(char *s, unsigned int *o)
{
	if (*s != '-' || !*(s + 1))
		return (0);
	s++;
	while ((*s == 'l' && (*o |= L)) || (*s == 'R' && (*o |= RR)) || (*s == 'a'
	&& (*o |= A)) || (*s == 'r' && (*o |= R)) || (*s == 't' && (*o |= T)))
		++s;
	if (*s)
	{
		write(2, "ft_ls: illegal option -- ", 25);
		write(2, s, 1);
		write(2, "\nusage: ft_ls [-lRart] [file ...]\n", 34);
		return (-1);
	}
	return (1);
}

int				main(int ac, char **av)
{
	unsigned int	o;
	int				i;
	int				r;

	++av;
	i = 0;
	while (*av && (i = parse(*av, &o)) && (av += 1) && (ac -= 1))
		if (i == -1)
			return (0);
	if (ac == 1)
		ft_ls(".", o, 0);
	else
	{
		r = setup(av, o, 0);
		i = 0;
		while (av[i])
		{
			ft_ls(av[i], o, (!r && !i && av[i + 1]) ? 2 :
			(r || (i || av[i + 1])));
			i++;
		}
	}
	return (0);
}
