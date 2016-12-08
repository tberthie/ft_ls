/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:16:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/08 15:38:36 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int				hidden(char *s, int o)
{
	if (*(s + 1) && ft_strcmp(s, "..") && (o & A))
		return (0);
	return (1);
}

void			recurs(t_s **f, char *p, unsigned int o)
{
	while ((o & RR) && *f)
	{
		if ((*(*f)->n != '.' || !hidden((*f)->n, o))
		&& S_ISDIR((*f)->s.st_mode))
			ft_ls(ft_strjoin(p, (*f)->n), o, 2);
		f++;
	}
}

void			ft_ls(char *p, unsigned int o, int r)
{
	DIR				*d;
	t_s				**fs;
	struct dirent	*f;
	char			*np;

	if (!(d = opendir(p)))
		return ((void)error_ret(p, 0));
	if (!(fs = malloc(sizeof(t_s*))))
		return ((void)closedir(d));
	*fs = 0;
	if (!(np = ft_strjoin(p, "/")))
	{
		free(fs);
		return ((void)closedir(d));
	}
	if (r)
		ft_printf((r == 2 ? "\n%s:\n" : "%s:\n"), p);
	while ((f = readdir(d)))
		if (!(fs = insert(fs, filestat(ft_strdup(f->d_name), np), o)))
			return ((void)closedir(d));
	display(fs, o);
	recurs(fs, np, o);
	closedir(d);
}
