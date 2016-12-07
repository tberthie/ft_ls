/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontani <tfontani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 14:10:03 by tfontani          #+#    #+#             */
/*   Updated: 2016/12/04 15:13:25 by tfontani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

#define BUFF_SIZE 128

signed char		ft_gnl(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	unsigned char	i;
	signed char		ret;

	i = 0;
	if (!*line)
		*line = (char*)malloc(sizeof(char));
	**line = '\0';
	while ((ret = (signed char)read(fd, buf + i, 1)) == 1 && buf[i] != '\n')
	{
		if (++i == BUFF_SIZE && !(buf[i] = '\0'))
		{
			ft_freeswap((void**)line, (void*)ft_strjoin(*line, buf));
			i = 0;
		}
	}
	if (i)
	{
		buf[i] = '\0';
		ft_freeswap((void**)line, (void*)ft_strjoin(*line, buf));
	}
	return (ret);
}
