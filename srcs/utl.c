/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:14:52 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/11 16:03:33 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int				cmp(t_file *a, t_file *b, unsigned int o)
{
	if ((o & T) && (o & R))
		return (a->stat.st_mtime > b->stat.st_mtime ? 1 : 0);
	if (o & T)
		return (a->stat.st_mtime <= b->stat.st_mtime ? 1 : 0);
	if (o & R)
		return (ft_strcmp(a->name, b->name) <= 0) ? 1 : 0;
	return (ft_strcmp(a->name, b->name) > 0) ? 1 : 0;
}

int				error_ret(char *s, int n)
{
	write(2, "ft_ls: ", 7);
	perror(s);
	return (n);
}

int				free_ret(void *p, int n)
{
	free(p);
	return (n);
}
