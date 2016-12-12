/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:40:18 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/12 16:19:32 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>

void		loutput(t_file **files, int root)
{
	int		max[4];
	char	*cs;

	cs = get_date();
	max[0] = get_max(files, 0);
	max[1] = get_max(files, 1);
	max[2] = get_max(files, 2);
	max[3] = get_max(files, 3);
	root ? print_total(files) : 0;
	while (*files)
	{
		print_rights(*files);
		ft_printf("  %*d %-*s  %-*s  %*d ", max[0], (*files)->stat.st_nlink,
		max[1], getpwuid((*files)->stat.st_uid)->pw_name, max[2],
		getgrgid((*files)->stat.st_gid)->gr_name, max[3],
		(*files)->stat.st_size);
		print_date(*files, cs);
		setcolor((*files));
		ft_printf(" %s{eoc}", (*files)->name);
		S_ISLNK((*files)->stat.st_mode) ? print_link(*files) : 0;
		write(1, "\n", 1);
		files++;
	}
	free(cs);
}

void		output(t_file **files, unsigned int o, int root)
{
	struct winsize	win;
	int				max;
	int				size;
	int				len;

	if (!*files)
		return ;
	if (o & L)
		return (loutput(files, root));
/*	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	size = 0;
	max = 0;
	while (files[size])
	{
		max =
		(len = ft_strlen(files[size++]->name)) > max ? len : max;
	}
	if (size)
		format(files, (max / 8) + 1, size, win);*/
}
