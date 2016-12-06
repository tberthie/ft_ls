#include "libft.h"

#include <stdlib.h>

void	*ft_memalloc(unsigned int size)
{
	char	*mem;

	if (!(mem = (char*)malloc(size)))
		return ((void*)0);
	while (size--)
		mem[size] = 0;
	return ((void*)mem);
}
