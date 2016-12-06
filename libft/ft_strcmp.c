#include "libft.h"

char	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1++ == *s2++)
		;
	return (s1[-1] - s2[-1]);
}
