#include "libft.h"

char	*search(char const *s, char c)
{
	char	*res;
	int		check;
	int		check2;

	check2 = -1;
	check = -1;
	c = c % 256;
	res = (char *)s;
	while (*res != 0)
	{
		if (*res == '\'')
			check *= -1;
		if (*res == '\"')
			check2 *= -1;
		if (*res == c && check == -1 && check2 == -1)
			return (res);
		res++;
	}
	if (c == 0)
		return (res);
	return (NULL);
}
