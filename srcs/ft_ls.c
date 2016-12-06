/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:16:20 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/05 13:50:14 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			dfiles(char **d, unsigned int o)
{
	struct stat		*s;

	while (*d)
	{
		
//		if dir > = 0;
		ft_printf("%s\n", *d);
		d++;
	}
}

void			ft_ls(char *d, unsigned int o)
{
}
