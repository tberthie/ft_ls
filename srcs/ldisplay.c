/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldisplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:35:44 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/09 16:58:00 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

#include <fcntl.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

static int		get_total(t_s **s)
{
	int		t;

	t = 0;
	while (*s)
		t += (*s++)->s.st_blocks;
	return (t);
}

static char		*get_time(t_s *s)
{
	char		*c;

	c = ((ft_strdup(ctime(&(s->s.st_mtime))) + 4));
	c[12] = 0;
	return (c);
}

int				max_width(t_s **s, int t)
{
	int		max;
	int		nb;
	int		tmp;

	max = 0;
	while (*s)
	{
		tmp = 1;
		nb = t == 0 ? (*s)->s.st_nlink : (*s)->s.st_size;
		while (nb >= 10)
		{
			tmp++;
			nb /= 10;
		}
		max = tmp > max ? tmp : max;
		s++;
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

void			display_l(t_s **s, unsigned int o, char *p)
{
	mode_t		t;
	int			i;
	char		lnk[32];
	int			rd;

	rd = 0;
	i = 0;
	ft_printf("total %d\n", get_total(s));
	while (s[i])
	{
		t = s[i]->s.st_mode;
		ft_printf("%c%c%c%c%c%c%c%c%c%c  %*d %s  %s  %*d %s ",
		type_char(t), t & S_IRUSR ? 'r' : '-', t & S_IWUSR ? 'w' : '-', t &
		S_IXUSR ? 'x' : '-', t & S_IRGRP ? 'r' : '-', t & S_IWGRP ? 'w' : '-',
		t & S_IXGRP ? 'x' : '-', t & S_IROTH ? 'r' : '-', t & S_IWOTH ? 'w' :
		'-', t & S_IXOTH ? 'x' : '-', max_width(s, 0), s[i]->s.st_nlink,
		getpwuid(s[i]->s.st_uid)->pw_name, getgrgid(s[i]->s.st_gid)->gr_name,
		max_width(s, 1), s[i]->s.st_size, get_time(s[i]));
		/*(o & G) ? */setcolor(s[i])/* : 0*/;
		ft_printf("%s{eoc}", s[i]->n);
		if (S_ISLNK(t) && (rd = readlink(ft_strjoin(p, s[i]->n), lnk, 31)) &&
		!(lnk[rd] = 0))
			ft_printf(" -> %s", lnk);
		ft_putchar('\n');
		i++;
	}
}
