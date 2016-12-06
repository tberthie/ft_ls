#include "libft.h"

#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*beg;

	if (!(str = (char*)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return ((char*)0);
	beg = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	return (beg);
}
