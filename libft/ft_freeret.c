#include "libft.h"

#include <stdlib.h>

signed char		ft_freeret(void *ptr, signed char ret)
{
	free(ptr);
	return (ret);
}
