/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:40:48 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/10 22:05:12 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

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

static char		**sort(char **s)
{
	int		a;
	int		b;
	char	*tmp;

	a = 0;
	while (s[a])
	{
		b = a + 1;
		while (s[b])
		{
			if (ft_strcmp(s[a], s[b]) > 0 && (tmp = s[a]) &&
			(s[a] = s[b]))
				s[b] = tmp;
			b++;
		}
		a++;
	}
	return (s);
}

static void		setup(char **s, unsigned int o, t_file **files, t_file **dirs)
{
	t_file		*file;
	int			i;
	int			e;

	e = 0;
	while (*s)
	{
		if (!(file = getfile("", *s++)))
			e = 1;
		else if (S_ISDIR(file->stat.st_mode) || S_ISLNK(file->stat.st_mode))
		{
			if (!(dirs = insert(dirs, file, o)))
				return ;
		}
		else if (!(files = insert(files, file, o)))
			return ;
	}
	output(files, "", o);
	i = 0;
	while (dirs[i++])
		ft_ls(dirs[i - 1], o, (i - 1) || *files ? 2 : e || (dirs[i]));
	freetab(files);
	freetab(dirs);
}

int				main(int ac, char **av)
{
	unsigned int	o;
	int				i;
	t_file			**files;
	t_file			**dirs;

	if (!init(&files) || !init(&dirs))
		return (0);
	++av;
	while (*av && (i = parse(*av, &o)) && (av += 1) && (ac -= 1))
		if (i == -1)
			return (0);
	if (ac == 1)
		ft_ls(getfile("", "."), o, 0);
	else
		setup(sort(av), o, files, dirs);
	return (0);
}
