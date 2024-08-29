#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	size;

	size = sizeof(*s);
	while (n > 0)
	{
		*(char *)s = '\0';
		s = s + size;
		n = n - size;
	}
}
