/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 20:37:35 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/10 21:42:07 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

static int		get_total(t_file **files)
{
	int		t;

	t = 0;
	while (*files)
		t += (*files++)->stat.st_blocks;
	return (t);
}

static char		*get_time(t_file *file)
{
	char		*c;

	(c = ft_strdup(ctime(&(file->stat.st_mtime))))[16] = 0;
	return (&c[4]);
}

static int		max_width(t_file **files, int t)
{
	int		max;
	int		nb;
	int		tmp;

	max = 0;
	while (*files)
	{
		tmp = 1;
		nb = !t ? (*files)->stat.st_nlink : 0;
		tmp = t == 1 ? ft_strlen(getpwuid((*files)->stat.st_uid)->pw_name)
		: tmp;
		tmp = t == 2 ? ft_strlen(getgrgid((*files)->stat.st_gid)->gr_name)
		: tmp;
		nb = t == 3 ? (*files)->stat.st_size : nb;
		if (!t || t == 3)
			while (nb >= 10)
			{
				tmp++;
				nb /= 10;
			}
		max = tmp > max ? tmp : max;
		files++;
	}
	return (max);
}

static char		type_char(mode_t t)
{
	if (S_ISDIR(t))
		return ('d');
	if (S_ISLNK(t))
		return ('l');
	if (S_ISCHR(t))
		return ('c');
	if (S_ISBLK(t))
		return ('b');
	if (S_ISFIFO(t))
		return ('p');
	if (S_ISSOCK(t))
		return ('s');
	return ('-');
}

void			loutput(t_file **files, char *p)
{
	mode_t		t;
	int			i;
	char		lnk[64];
	int			rd;

	if ((i = get_total(files)))
		ft_printf("total %d\n", i);
	i = 0;
	while (files[i] && (t = files[i]->stat.st_mode))
	{
		ft_printf("%c%c%c%c%c%c%c%c%c%c  %*d %-*s  %-*s  %*d %s ",
		type_char(t), t & S_IRUSR ? 'r' : '-', t & S_IWUSR ? 'w' : '-', t &
		S_IXUSR ? 'x' : '-', t & S_IRGRP ? 'r' : '-', t & S_IWGRP ? 'w' : '-',
		t & S_IXGRP ? 'x' : '-', t & S_IROTH ? 'r' : '-', t & S_IWOTH ? 'w' :
		'-', t & S_IXOTH ? 'x' : '-', max_width(files, 0),
		files[i]->stat.st_nlink, max_width(files, 1),
		getpwuid(files[i]->stat.st_uid)->pw_name, max_width(files, 2),
		getgrgid(files[i]->stat.st_gid)->gr_name, max_width(files, 3),
		files[i]->stat.st_size, get_time(files[i]));
		if (S_ISLNK(t) && (rd = readlink(ft_strjoin(p, files[i]->name), lnk,
		63)) && !(lnk[rd] = 0))
			ft_printf("%s -> %s{eoc}\n", files[i++]->name, lnk);
		else
			ft_printf("%s{eoc}\n", files[i++]->name);
	}
	free(files);
}
