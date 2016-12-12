/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:07:47 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/12 16:56:56 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <time.h>

# define L	(1 << 0)
# define RR	(1 << 1)
# define A	(1 << 2)
# define R	(1 << 3)
# define T	(1 << 4)
# define U	(1 << 5)
# define F	(1 << 6)
# define G	(1 << 7)
# define D	(1 << 8)

typedef struct stat	t_s;

typedef struct		s_file
{
	char	*path;
	char	*name;
	t_s		stat;
}					t_file;

void				ft_ls(t_file *d, unsigned int o, int r);
void				output(t_file **files, unsigned int o, int root);
void				loutput(t_file **files, int root, unsigned int o);

t_file				*getfile(char *p, char *n);
t_file				**insert(t_file **files, t_file *file, unsigned int o);

int					get_max(t_file **files, int type);
void				print_total(t_file **files);
void				print_rights(t_file *file);
void				print_date(t_file *file, char *cs);
void				print_link(t_file *file);

char				*get_date(void);
void				setcolor(t_file *file);
int					cmp(t_file *a, t_file *b, unsigned int o);
void				freetab(t_file **files);
void				freefile(t_file *file);
int					error_ret(char *s, int n);
int					free_ret(void *p, int n);
int					init(t_file ***files);

#endif
