/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:40:18 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/10 20:57:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

#include <sys/stat.h>

void		setcolor(t_file *file)
{
	if (S_ISDIR(file->stat.st_mode))
		ft_printf("{green}");
	else if (S_ISLNK(file->stat.st_mode))
		ft_printf("{magenta}");
}

void		noutput(t_file **files)
{

}

void		output(t_file **files, char *p, unsigned int o)
{
//	if (o & L)
//		loutput(files, p);
//	else
//		noutput(files);
}
