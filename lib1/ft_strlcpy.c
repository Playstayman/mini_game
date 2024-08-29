#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (size > 1 && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}
