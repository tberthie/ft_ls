/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:16:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/10 21:43:38 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void			freetab(t_file **files)
{
	int		i;

	i = 0;
	while (files[i])
	{
		free(files[i]->name);
		free(files[i]->path);
		free(files[i++]);
	}
	free(files);
}

int				forbidden(char *n, unsigned int o)
{
	if (*n == '.' && (!(o & A) || (!*(n + 1) ||
	(*(n + 1) == '.' && !*(n + 2)))))
		return (1);
	return (0);
}

t_file			**parse(DIR *dir, char *p, unsigned int o, t_file **dirs,
						t_file **files)
{
	t_file			*file;
	struct dirent	*read;
	char			*tmp;

	while ((read = readdir(dir)))
	{
		if ((tmp = ft_strjoin(p, "/")) &&
		(file = getfile(tmp, read->d_name)))
		{
			if (read->d_type == DT_DIR && (o & RR))
			{
				if (!forbidden(read->d_name, o) &&
				!(dirs = insertfile(dirs, file, o)))
					return (0);
			}
			else if ((*read->d_name != '.' || o & A) &&
			!(files = insertfile(files, file, o)))
				return (0);
		}
		if (tmp)
			free(tmp);
	}
	output(files, p, o);
	freetab(files);
	return (dirs);
}

void			ft_ls(t_file *d, unsigned int o, int r)
{
	DIR				*dir;
	char			*tmp;
	t_file			**files;
	t_file			**dirs;
	int				i;

	if (!(files = malloc(sizeof(t_file*))) ||
	!(dirs = malloc(sizeof(t_file*))))
		return ;
	*files = 0;
	*dirs = 0;
	if (!(tmp = *(d->path) ? ft_strjoin(d->path, d->name) : d->name)
	|| !(dir = opendir(tmp)))
		return (tmp) ? (void)free_ret(tmp, 0) : (void)0;
	if (r)
		ft_printf(r == 1 ? "%s:\n" : "\n%s:\n", tmp);
	i = 0;
	if ((dirs = parse(dir, tmp, o, dirs, files)))
	{
		while (dirs[i])
			ft_ls(dirs[i++], o, 2);
		freetab(dirs);
	}
	free(tmp);
	closedir(dir);
}
