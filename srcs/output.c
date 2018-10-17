/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:40:18 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/12 18:53:32 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <sys/ioctl.h>
#include <pwd.h>
#include <grp.h>

void		loutput(t_file **files, int root, unsigned int o)
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
		ft_printf("  %*d", max[0], (*files)->stat.st_nlink);
		ft_printf((o & G) ? "" : " %-*s ",
		max[1], getpwuid((*files)->stat.st_uid)->pw_name);
		ft_printf(" %-*s  ", max[2], getgrgid((*files)->stat.st_gid)->gr_name);
		ft_printf("%*d ", max[3], (*files)->stat.st_size);
		print_date(*files, cs);
		setcolor((*files));
		ft_printf(" %s{eoc}", (*files)->name);
		S_ISLNK((*files)->stat.st_mode) ? print_link(*files) : 0;
		write(1, "\n", 1);
		files++;
	}
	free(cs);
}

static void	format_alt(t_file **files)
{
	while (*files)
		ft_printf("%s\n", (*files++)->name);
}

static void	format(t_file **files, int total, int num, int max)
{
	int		rows;
	t_file	*file;
	int		pos;
	int		len;
	int		i;

	rows = num / total + (num % total ? 1 : 0);
	total *= rows;
	i = 0;
	while (i < total)
	{
		pos = (i * rows) - total * (i * rows / total) + (i * rows / total);
		if ((i += 1) && pos < num)
		{
			setcolor((file = files[pos]));
			if (pos >= num - rows)
				ft_printf("%s{eoc}\n", file->name);
			else if ((len = ft_strlen(file->name)))
			{
				ft_printf("%s{eoc}\t", file->name);
				while (len - (len % 8) < max - (max % 8) && (len += 8))
					write(1, "\t", 1);
			}
		}
	}
}

void		output(t_file **files, unsigned int o, int root)
{
	struct winsize	win;
	int				max;
	int				num;
	int				len;

	if (!*files)
		return ;
	if (o & L)
		return (loutput(files, root, o));
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	num = 0;
	max = 0;
	while (files[num])
	{
		max =
		(len = ft_strlen(files[num++]->name)) > max ? len : max;
	}
	(win.ws_col) ? format(files, win.ws_col / (8 + (max - (max % 8))), num,
	max) : format_alt(files);
}
