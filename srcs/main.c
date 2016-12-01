/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:40:48 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/01 21:48:41 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static int		parse(char *s, unsigned int *o)
{
	if (*s++ != '-')
		return (0);
	while (*s == 'l' || *s == 'R' || *s == 'a' || *s == 'r' || *s == 't')
		if ((*s == 'l' && (*o |= L)) || (*s == 'R' && (*o |= RR)) ||
		(*s == 'a' && (*o |= A)) || (*s == 'r' && (*o |= R)) ||
		(*s == 't' && (*o |= T)))
			s++;
	if (*s)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*s, 2);
		ft_putstr_fd("\nusage: ft_ls [-lRart] [file ...]\n", 2);
		return (-1);
	}
	return (1);
}

static void		sort_insert(char **d, int n, char *s)
{
	int		i;

	i = 0;
	while (i < n && ft_strcmp(s, d[i]) > 0)
		i++;
	if (i != n)
		while (n--)
			d[n + 1] = d[n];
	d[i] = s;
}

int				main(int ac, char **av)
{
	char			**d;
	unsigned int	o[1];
	int				i;
	DIR				*ld;

	if (!(d = (char**)malloc(sizeof(char*) * ac)))
		return (0);
	av++;
	ac = 0;
	while (*av && (ac = parse(*av, o)))
		if ((av++) && ac == -1)
			return (0);
	ac = 0;
	while (*av)
		sort_insert(d, ac++, *av++);
	if (!ac)
		d[ac++] = ".";
	d[ac] = 0;
	i = 0;
	while (i++ < ac)
		if (!opendir(d[i - 1]))
		{
			ft_putstr_fd("ft_ls: ", 2);
			err_ret(d[i - 1], 0);
		}
	if (ac > 1)
		sort(d, *o, ac);
	i = 0;
	while (i++ < ac)
		if ((ld = opendir(d[i - 1])))
			ft_ls(ld, *o, (ac > 1), d[i - 1]);
	return (0);
}
