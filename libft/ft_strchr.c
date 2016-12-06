#include "libft.h"

char	*ft_strchr(char *str, char c)
{
	while (*str && *str != c)
		++str;
	return (*str) ? str : (char*)0;
}
