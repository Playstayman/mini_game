#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
{
	size_t	i;
	int		start_rem;
	int		end_rem;
	char	*res;

	if (s1 == NULL)
		return (NULL);
	res = 0;
	start_rem = 0;
	end_rem = 0;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[start_rem]))
		start_rem++;
	while (start_rem + end_rem < (int)i && ft_strchr(set, s1[i - end_rem - 1]))
		end_rem++;
	if (start_rem + end_rem == (int)i)
		return (malloc (0));
	res = ft_substr(s1, start_rem, i - start_rem - end_rem);
	return (res);
}

char	*ft_frstrtrim(char *s1, char const *set)
{
	size_t	i;
	int		start_rem;
	int		end_rem;
	char	*res;

	res = 0;
	start_rem = 0;
	end_rem = 0;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[start_rem]))
		start_rem++;
	while (start_rem + end_rem < (int)i && ft_strchr(set, s1[i - end_rem - 1]))
		end_rem++;
	if (start_rem + end_rem == (int)i)
		return (free (s1), malloc (0));
	res = ft_substr(s1, start_rem, i - start_rem - end_rem);
	return (free (s1), res);
}
