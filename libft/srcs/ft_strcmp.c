/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:37:19 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:37:20 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1++ == *s2++ && *(s1 - 1))
		;
	return ((unsigned char)*(s1 - 1) - (unsigned char)*(s2 - 1));
}