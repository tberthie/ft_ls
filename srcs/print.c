/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:45:45 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/12 16:19:18 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int			get_max(t_file **files, int type)
{
	int		max;
	int		a;
	int		b;

	max = 0;
	while (*files)
	{
		if (!type || type == 3)
		{
			a = !type ? (*files)->stat.st_nlink : (*files)->stat.st_size;
			b = 1;
			while (a >= 10 && (a /= 10))
				b += 1;
			max = b > max ? b : max;
		}
		else
		{
			a = type == 1 ? ft_strlen(getpwuid((*files)->stat.st_uid)->pw_name)
			: ft_strlen(getgrgid((*files)->stat.st_gid)->gr_name);
			max = a > max ? a : max;
		}
		files++;
	}
	return (max);
}

void		print_total(t_file **files)
{
	int		total;

	total = 0;
	while (*files)
		total += (*files++)->stat.st_blocks;
	ft_printf("total %d\n", total);
}

void		print_rights(t_file *file)
{
	if (S_ISREG((*file).stat.st_mode))
		write(1, "-", 1);
	else if (S_ISDIR((*file).stat.st_mode))
		write(1, "d", 1);
	else if (S_ISCHR((*file).stat.st_mode))
		write(1, "c", 1);
	else if (S_ISBLK((*file).stat.st_mode))
		write(1, "b", 1);
	else if (S_ISFIFO((*file).stat.st_mode))
		write(1, "p", 1);
	else if (S_ISLNK((*file).stat.st_mode))
		write(1, "l", 1);
	else if (S_ISSOCK((*file).stat.st_mode))
		write(1, "s", 1);
	write(1, (*file).stat.st_mode & S_IRUSR ? "r" : "-", 1);
	write(1, (*file).stat.st_mode & S_IWUSR ? "w" : "-", 1);
	write(1, (*file).stat.st_mode & S_IXUSR ? "x" : "-", 1);
	write(1, (*file).stat.st_mode & S_IRGRP ? "r" : "-", 1);
	write(1, (*file).stat.st_mode & S_IWGRP ? "w" : "-", 1);
	write(1, (*file).stat.st_mode & S_IXGRP ? "x" : "-", 1);
	write(1, (*file).stat.st_mode & S_IROTH ? "r" : "-", 1);
	write(1, (*file).stat.st_mode & S_IWOTH ? "w" : "-", 1);
	write(1, (*file).stat.st_mode & S_IXOTH ? "x" : "-", 1);
}

void		print_date(t_file *file, char *cs)
{
	char	*s;

	s = (ctime(&((*file).stat.st_mtime)) + 4);
	if (ft_strncmp(&s[16], &cs[20], 4))
	{
		write(1, s, 7);
		write(1, &s[15], 5);
	}
	else
		write(1, s, 12);
}

void		print_link(t_file *file)
{
	char	buff[100];
	char	*tmp;
	int		rd;

	if ((tmp = ft_strjoin(file->path, file->name)) &&
	(rd = readlink(tmp, buff, 100)))
	{
		write(1, " -> ", 4);
		write(1, buff, rd);
	}
	tmp ? free(tmp) : 0;
}
