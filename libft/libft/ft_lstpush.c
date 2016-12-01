/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:21:54 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 13:26:16 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstpush(t_list **alst, t_list *new)
{
	if (*alst)
	{
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = new;
	}
	else
		*alst = new;
}
