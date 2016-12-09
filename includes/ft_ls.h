/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:07:47 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/09 18:33:54 by tberthie         ###   ########.fr       */
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

typedef struct		s_ls
{
	int				o;
	int				max_len;
	t_fold			**d
}					t_ls;

typedef struct		s_fold
{
	char			*p;
	char			**n;
	t_s				**s;
}					t_fold;






void				ft_ls(char *d, unsigned int o, int r);
void				display(t_s **s, unsigned int o, char *p);

void				display_l(t_s **s, char *p);
int					cmp(t_s *s1, t_s *s2, unsigned int o);
t_s					*filestat(char *n, char *p);
t_s					**insert(t_s **d, t_s *s, unsigned int o);
void				sort(t_s **s, unsigned int o);
void				setcolor(t_s *s);

int					error_ret(char *s, int n);
int					free_ret(void *p, int n);

#endif
