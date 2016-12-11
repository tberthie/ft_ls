/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 15:48:23 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/11 16:05:54 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdlib.h>

void			freefile(t_file *file)
{
	free(file->path);
	free(file->name);
	free(file);
}

void			freetab(t_file **files)
{
	int		i;

	i = 0;
	while (files[i])
		freefile(files[i++]);
	free(files);
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
	{
		file ? free(file) : 0;
		tmp ? free(tmp) : 0;
		return (0);
	}
	file->path = ft_strdup(p);
	file->name = ft_strdup(n);
	file->stat = stat;
	free(tmp);
	return (file);
}

t_file			**insert(t_file **files, t_file *file, unsigned int o)
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
