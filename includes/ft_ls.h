/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 16:07:47 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/05 13:49:14 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define l	(1 << 0)
# define R	(1 << 1)
# define a	(1 << 2)
# define r	(1 << 3)
# define t	(1 << 4)

void		ft_ls(char *d, unsigned int o);
void		dfiles(char **s, unsigned int o);

void		sort_insert(char **d, char *s, unsigned int o);
void		sort(char **s, unsigned int o);

#endif
