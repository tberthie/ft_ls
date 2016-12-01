/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:15:44 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/16 23:09:24 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content && !(new->content = malloc(content_size)))
		return (NULL);
	new->content = (content ? ft_memcpy(new->content, content, content_size)
	: NULL);
	new->content_size = (content ? content_size : 0);
	new->next = NULL;
	return (new);
}
