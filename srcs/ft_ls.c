/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:16:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/12 16:18:14 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

int				init(t_file ***ptr)
{
	t_file		**files;

	if (!(files = malloc(sizeof(t_file*))))
		return (0);
	*files = 0;
	*ptr = files;
	return (1);
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
	{
		if (read->d_type == DT_DIR && (o & RR))
		{
			!forbidden(read->d_name, o) && (file = getfile(tmp, read->d_name))
			? (ds = insert(ds, file, o)) : 0;
			!forbidden(read->d_name, o) && (file = getfile(tmp, read->d_name))
			? (fs = insert(fs, file, o)) : 0;
		}
		else if (*read->d_name != '.' || o & A)
			(file = getfile(tmp, read->d_name)) ?
			(fs = insert(fs, file, o)) : 0;
		if (!fs || !ds)
			return (0);
	}
	closedir(dir);
	output(fs, o, 1);
	free(tmp);
	freetab(fs);
	return (ds);
}

void			ft_ls(t_file *d, unsigned int o, int r)
{
	t_file			**dirs;
	DIR				*dir;
	char			*tmp;
	int				i;

	if (!(tmp = ft_strjoin(d->path, d->name))
	|| !(dir = opendir(tmp)))
		return (tmp) ? (void)free_ret(tmp, 0) : (void)0;
	if (r)
		ft_printf(r == 1 ? "{green}%s:{eoc}\n" : "\n{green}%s:{eoc}\n", tmp);
	if ((dirs = parse(dir, tmp, o)))
	{
		i = 0;
		while (dirs[i])
			ft_ls(dirs[i++], o, 2);
		freetab(dirs);
	}
	else
		closedir(dir);
	free(tmp);
}
