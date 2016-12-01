/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 11:31:40 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/01 21:26:24 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <errno.h>
# include <sys/stat.h>

# define L	1
# define RR	1 << 1
# define A	1 << 2
# define R	1 << 3
# define T	1 << 4

typedef struct			s_d
{
	DIR				*d;
	char			*s;
}						t_d;

typedef struct			s_f
{
	unsigned char	t;
	char			*n;
}						t_f;

void					ft_ls(DIR *d, unsigned int o, int r, char *p);
int						err_ret(char *s, int r);
void					sort(char **d, unsigned int o, int s);

#endif
