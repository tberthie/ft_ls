/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:14:52 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/05 13:46:40 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				cmp(char *s1, char *s2, unsigned int o)
{
	o = 0;
	return (ft_strcmp(s1, s2) > 0) ? 1 : 0;
}

void			sort(char **s, unsigned int o)
{
	int		i;
	char	*t;

	while (*s && (i = 1))
	{
		while (s[i])
		{
			if (cmp(*s, s[i], o) && (t = *s) && (*s = s[i]))
				s[i] = t;
			i++;
		}
		s++;
	}
}

char			**sort_insert(char **d, char *s, unsigned int o)
{
	char	**ns;
	int		l;

	l = 0;
	while (d[l])
		l++;
	if (!(ns = malloc(sizeof(char*) * (l + 1))))
		return (0);
	ns[l] = '\0';
	while (l--)
		ns[l] = (s && !strcmp(s, d[l]) && !(s = 0)) ? s : d[l];
	return (ns);
}

void			print_files()
{

}
