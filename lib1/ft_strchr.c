#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*res;

	c = c % 256;
	res = (char *)str;
	while (*res != 0)
	{
		if (*res == c)
			return (res);
		res++;
	}
	if (c == 0)
		return (res);
	return (NULL);
}
