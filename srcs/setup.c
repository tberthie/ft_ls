/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:19:14 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/07 17:49:40 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int			setup(char **s, unsigned int o, int r)
{
	char			**f;
	struct stat		st;
	int				i;
	int				l;

	if (!(f = malloc(sizeof(char*))))
		return (0);
	*f = 0;
	i = 0;
	l = 0;
	sort(s, 0);
	while (s[i])
	{
		if (lstat(s[i], &st) && (r = 1))
			error(s[i]);
		else if (S_ISDIR(st.st_mode) || (S_ISLNK(st.st_mode) && !(o & L)))
			s[l++] = s[i];
		else
			f = insert(f, s[i], o);
		i++;
	}
	s[l] = 0;
	sort(s, o);
	files(f, "", o);
	return (*f || r) ? 1 : 0;
}
