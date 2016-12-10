/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:16:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/10 22:41:34 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int				init(t_file ***files)
{
	if (!(*files = malloc(sizeof(t_file))))
		return (0);
	**files = 0;
	return (1);
}

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

t_file			**parse(DIR *dir, char *p, unsigned int o)
{
	t_file			**fs;
	t_file			**ds;
	t_file			*file;
	struct dirent	*read;
	char			*tmp;

	if (!init(&fs) || !init(&ds) || !(tmp = ft_strjoin(p, "/")))
		return (0);
	while ((read = readdir(dir)))
		if ((file = getfile(tmp, read->d_name)))
		{
			if (read->d_type == DT_DIR && (o & RR))
			{
				if (!forbidden(read->d_name, o) && !(ds = insert(ds, file, o)))
					return (0);
			}
			else if ((*read->d_name != '.' || o & A) &&
			!(fs = insert(fs, file, o)))
				return (0);
		}
	free(tmp);
	output(fs, p, o);
	freetab(fs);
	return (ds);
}

void			ft_ls(t_file *d, unsigned int o, int r)
{
	t_file			**dirs;
	DIR				*dir;
	char			*tmp;
	int				i;

	if (!(tmp = *(d->path) ? ft_strjoin(d->path, d->name) : ft_strdup(d->name))
	|| !(dir = opendir(tmp)))
		return (tmp) ? (void)free_ret(tmp, 0) : (void)0;
	if (r)
		ft_printf(r == 1 ? "%s:\n" : "\n%s:\n", tmp);
	if ((dirs = parse(dir, tmp, o)))
	{
		i = 0;
		while (dirs[i])
			ft_ls(dirs[i++], o, 2);
		freetab(dirs);
	}
	free(tmp);
	closedir(dir);
}
