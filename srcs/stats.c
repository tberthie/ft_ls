/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:52:32 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/09 18:13:21 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdlib.h>
#include <sys/stat.h>

int				cmp(t_s *s1, t_s *s2, unsigned int o)
{
	if ((o & T) && (o & R))
		return (s1->s.st_mtime > s2->s.st_mtime ? 1 : 0);
	if (o & T)
		return (s1->s.st_mtime <= s2->s.st_mtime ? 1 : 0);
	if (o & R)
		return (ft_strcmp(s1->n, s2->n) <= 0) ? 1 : 0;
	return (ft_strcmp(s1->n, s2->n) > 0) ? 1 : 0;
}

t_s				*filestat(char *n, char *p)
{
	t_s				*f;
	char			*fulln;

	if (!(fulln = ft_strjoin(p, n)))
		free_ret(n, 0);
	if (!(f = malloc(sizeof(t_s))) || lstat(fulln, &(f->s)))
	{
		f ? error_ret(fulln, 0) : 0;
		f ? free(f) : 0;
		free(n);
		free(fulln);
		return (0);
	}
	f->n = n;
	free(fulln);
	return (f);
}

void			sort(t_s **s, unsigned int o)
{
	int		i;
	t_s		*t;

	while (*s && (i = 1))
	{
		while (s[i])
		{
			if (cmp(*s, s[i], o) && (t = *s)
			&& (*s = s[i]))
				s[i] = t;
			i++;
		}
		s++;
	}
}

t_s				**insert(t_s **d, t_s *s, unsigned int o)
{
	t_s		**ns;
	int		l;
	int		i;

	l = 0;
	if (!s)
		return (d);
	while (d[l])
		l++;
	if (!(ns = malloc(sizeof(t_s*) * (++l + 1))))
		return (0);
	ns[l] = 0;
	i = 0;
	while (i < l)
	{
		if (s && (!d[i] || !cmp(s, d[i], o)) && (ns[i] = s))
			s = 0;
		else
			ns[i] = d[i - (!s)];
		i++;
	}
	free(d);
	return (ns);
}
