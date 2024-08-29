#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;

	if ((nitems > LONG_MAX && size > 0) || (size > LONG_MAX && nitems > 0))
		return (NULL);
	res = malloc(nitems * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nitems * size);
	return (res);
}
