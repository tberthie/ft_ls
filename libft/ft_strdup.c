#include "libft.h"

#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char			*dup;

	if (!(dup = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return ((char*)0);
	ft_strcpy(dup, str);
	return (dup);
}
