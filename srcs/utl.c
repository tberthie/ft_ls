/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:14:52 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/10 21:40:55 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int				cmp(t_file *a, t_file *b, unsigned int o)
{
	if ((o & T) && (o & R))
		return (a->stat.st_mtime > b->stat.st_mtime ? 1 : 0);
	if (o & T)
		return (a->stat.st_mtime <= b->stat.st_mtime ? 1 : 0);
	if (o & R)
		return (ft_strcmp(a->name, b->name) <= 0) ? 1 : 0;
	return (ft_strcmp(a->name, b->name) > 0) ? 1 : 0;
}

t_file			*getfile(char *p, char *n)
{
	t_file		*file;
	t_s			stat;
	char		*tmp;

	tmp = 0;
	if ((!(file = malloc(sizeof(t_file)))
	|| !(tmp = ft_strjoin(p, n))
	|| lstat(tmp, &stat)) && error_ret(tmp, 1))
		return (0);
	file->path = ft_strdup(p);
	file->name = ft_strdup(n);
	file->stat = stat;
	free(tmp);
	return (file);
}

t_file			**insertfile(t_file **files, t_file *file, unsigned int o)
{
	t_file		**nfiles;
	int			i;
	int			l;

	l = 0;
	while (files[l])
		l++;
	if (!(nfiles = malloc(sizeof(t_file*) * (l + 2))))
		return (0);
	nfiles[l + 1] = 0;
	i = 0;
	while (i <= l)
	{
		if (file && (!files[i] || !cmp(file, files[i], o)) &&
		(nfiles[i] = file))
			file = 0;
		else
			nfiles[i] = files[i - (!file)];
		i++;
	}
	free(files);
	return (nfiles);
}

int				error_ret(char *s, int n)
{
	write(2, "ft_ls: ", 7);
	perror(s);
	return (n);
}

int				free_ret(void *p, int n)
{
	free(p);
	return (n);
}
