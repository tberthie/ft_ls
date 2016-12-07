/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:07:47 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/07 16:34:48 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>

# define L	(1 << 0)
# define RR	(1 << 1)
# define A	(1 << 2)
# define R	(1 << 3)
# define T	(1 << 4)

typedef struct		s_s
{
	struct stat		s;
	char			*n;
}					t_s;

void				ft_ls(char *d, unsigned int o, int r);
int					setup(char **s, unsigned int o, int r);
void				files(char **s, char *p, unsigned int o);
void				display(t_s **s, unsigned int o);

char				**insert(char **d, char *s, unsigned int o);
void				sort(char **s, unsigned int o);
void				error(char *s);

#endif
