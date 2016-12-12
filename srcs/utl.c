/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:14:52 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/12 16:08:12 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

char			*get_date(void)
{
	time_t	tm;
	char	*cs;
	char	*tmp;

	tm = time(&tm);
	tmp = ctime(&tm);
	cs = ft_strdup(tmp);
	return (cs);
}

void			setcolor(t_file *file)
{
	if (S_ISDIR(file->stat.st_mode))
		write(1, "\x1b[32m", 6);
	else if (S_ISLNK(file->stat.st_mode))
		write(1, "\x1b[35m", 6);
	else if (S_ISLNK(file->stat.st_mode) || S_ISBLK(file->stat.st_mode) ||
	S_ISCHR(file->stat.st_mode) || S_ISSOCK(file->stat.st_mode))
		write(1, "\x1b[36m", 6);
	else if (S_IXUSR & file->stat.st_mode || S_IXGRP & file->stat.st_mode
	|| S_IXOTH & file->stat.st_mode)
		write(1, "\x1b[31m", 6);
}

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
