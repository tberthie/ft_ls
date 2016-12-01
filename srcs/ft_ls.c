/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:59:03 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/01 22:09:32 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

static t_f		**insert(t_f **d, struct dirent *f)
{
	t_f		**nd;
	t_f		*e;
	int		i;
	int		n;

	n = 0;
	while (d && d[n])
		n++;
	if (!(nd = malloc(sizeof(t_f*) * (n + 2))) ||
	!(e = malloc(sizeof(t_f))))
		return (0);
	nd[n + 1] = 0;
	i = 0;
	while (i < n)
		nd[i++] = *d++;
	e->n = f->d_name;
	e->t = f->d_type;
	nd[n] = e;
	return (nd);
}

static void		display(t_f **t)
{
	while (*t)
		ft_printf("%s\t", (*(t++))->n);
	ft_putchar('\n');
}

void			ft_ls(DIR *d, unsigned int o, int r, char *p)
{
	struct dirent	*f;
	t_f				**t;
	DIR				*rd;
	char			*lp;

	if (r)
		ft_printf("\n%s:\n", p);
	while (!(f = 0) && (f = readdir(d)))
		if (((o & A) || *(f->d_name) != '.') && !(t = insert(t, f)))
			return ;
	display(t);
	while ((o & RR) && *t)
	{
		if ((*t)->t == DT_DIR && *((*t)->n) != '.')
		{
			if (!(lp = ft_strjoin(p, "/")) ||
			!(lp = ft_strjoin(lp, (*t)->n)) ||
			!(rd = opendir(lp)))
			{
				ft_putstr_fd("ft_ls: ", 2);
				perror(p);
				closedir(d);
				return ;
			}
			else
			{
				ft_ls(rd, o, 1, lp);
			}
		}
		t++;
	}
	closedir(d);
}
