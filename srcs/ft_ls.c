/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:16:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/07 16:51:58 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

t_s				**getstats(char **d, char *p)
{
	t_s			**s;
	t_s			*f;
	int			l;

	l = 0;
	while (d[l])
		l++;
	if (!(s = malloc(sizeof(t_s*) * (l + 1))))
		return (0);
	l = 0;
	while (*d)
	{
		if ((f = malloc(sizeof(t_s))) && !stat(ft_strjoin(p, *d), &f->s)
		&& (f->n = *d))
			s[l++] = f;
		else
		{
			error(*d);
			if (f)
				free(f);
		}
		d++;
	}
	s[l] = 0;
	return (s);
}

void			files(char **d, char *p, unsigned int o)
{
	t_s			**s;

	if (!(s = malloc(sizeof(t_s*)))
	|| (*s = 0)
	|| !(s = getstats(d, p)))
		return ;
	display(s, o);
}

int				hidden(char *s, int o)
{
	if (*(s + 1) && ft_strcmp(s, "..") && (o & A))
		return (0);
	return (1);
}

void			ft_ls(char *p, unsigned int o, int r)
{
	DIR				*d;
	char			**fs;
	struct dirent	*f;
	char			*np;

	if (!(d = opendir(p)) ||
	!(fs = malloc(sizeof(char*))) ||
	!(np = ft_strjoin(p, "/")))
		return ;
	if (r)
		ft_printf((r == 1 ? "\n%s:\n" : "%s:\n"), p);
	*fs = 0;
	while ((f = readdir(d)))
		if (!(fs = insert(fs, ft_strdup(f->d_name), o)))
			return ;
	sort(fs, o);
	files(fs, np, o);
	while ((o & RR) && *fs)
		if (**fs++ != '.' || !hidden(*(fs - 1), o))
			ft_ls(ft_strjoin(np, *(fs - 1)), o, 1);
}
