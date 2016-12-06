#include "libft.h"

unsigned int	ft_strlen(const char *str)
{
	const char	*beg;

	beg = str;
	while (*str)
		++str;
	return ((unsigned int)(str - beg));
}
