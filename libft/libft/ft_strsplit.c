/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:25:38 by tberthie          #+#    #+#             */
/*   Updated: 2016/11/09 13:16:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_add_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	i = 0;
	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	word = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (*s && *s != c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

char		**ft_strsplit(char const *s, char c)
{
	int		words;
	char	**tab;
	int		i;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	tab = (char**)malloc(sizeof(char*) * (words + 1));
	if (!tab)
		return (NULL);
	tab[words] = 0;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			tab[i++] = ft_add_word(s, c);
			while (*s && *s != c)
				s++;
		}
		else
			while (*s && *s == c)
				s++;
	}
	return (tab);
}
