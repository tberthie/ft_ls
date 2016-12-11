/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 13:40:18 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/11 16:43:29 by tberthie         ###   ########.fr       */
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

void		output(t_file **files, unsigned int o)
{
//	if (o & L)
//		loutput(files);
//	else

}
