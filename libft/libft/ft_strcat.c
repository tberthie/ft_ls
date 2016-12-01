/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:37:10 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 12:37:11 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char				*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		++i;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
