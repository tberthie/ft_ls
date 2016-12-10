/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:07:47 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/10 22:01:56 by tberthie         ###   ########.fr       */
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

typedef struct stat	t_s;

typedef struct		s_file
{
	char	*path;
	char	*name;
	t_s		stat;
}					t_file;

void				ft_ls(t_file *d, unsigned int o, int r);
void				output(t_file **files, char *p, unsigned int o);
void				loutput(t_file **files, char *p);

t_file				*getfile(char *p, char *n);
t_file				**insert(t_file **files, t_file *file, unsigned int o);

void				freetab(t_file **files);
int					error_ret(char *s, int n);
int					free_ret(void *p, int n);
int					init(t_file ***files);

#endif
