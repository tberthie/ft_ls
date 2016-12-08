/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:14:52 by tberthie          #+#    #+#             */
/*   Updated: 2016/12/08 15:25:13 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <unistd.h>

int				error_ret(char *s, int n)
{
	write(2, "ft_ls: ", 7);
	perror(s);
	return (n);
}

int				freeret_ret(void *p, int n)
{
	free(p);
	return (n);
}
