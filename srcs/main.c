/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:40:48 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/05 13:47:15 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <unistd.h>

static int		parse(char *s, unsigned int *o)
{
	if (*s++ != '-')
		return (0);
	while ((*s == 'l' && (*o |= l)) || (*s == 'R' && (*o |= R)) || (*s == 'a' &&
	(*o |= a)) || (*s == 'r' && (*o |= r)) || (*s == 't' && (*o |= t)))
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

	++av;
	i = 0;
	while (*av && (i = parse(*av, &o)) && (av += 1) && (ac -= 1))
		if (i == -1)
			return (0);
	(ac == 1) ? ft_ls(".", o) : sort(av, 0);
	sort(av, o);
	dfiles(av, o);
	while (--ac)
		if (*av++)
			ft_ls(*(av - 1), o);
	return (0);
}
