/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:16:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/06 21:00:41 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

t_s				**getstats(char **d)
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
		if ((f = malloc(sizeof(t_s))) && !stat(*d, f->s))
		{
			f->n = *d;
			s[l++] = f;
		}
		else if (f)
			free(f);
		d++;
	}
	s[l] = 0;
	return (s);
}

void			dfiles(char **d, unsigned int o)
{
	t_s			**s;

	if (!(s = malloc(sizeof(t_s*)))
	|| !(s = getstats(d)))
		return ;
	while (*s)
	{
		o = 0;		
//		if dir > = 0:;
		ft_printf("File %s\n", (*s)->n);
		s++;
	}
}

void			ft_ls(char *p, unsigned int o)
{
	DIR				*d;
	char			**fs;
	struct dirent	*f;

	if (!(d = opendir(p)) ||
	!(fs = malloc(sizeof(char*))))
		return ;
	ft_printf("%s:\n", p);
	*fs = 0;
	while ((f = readdir(d)))
		if (!(fs = sort_insert(fs, f->d_name, o)))
			return ;
	while (*fs)
		ft_printf("%s\n", *fs++);
}
