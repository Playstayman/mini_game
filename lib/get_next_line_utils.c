#include "get_next_line.h"

char	*ft_gnlstrjoin(char *s1, char *s2, int size)
{
	char	*res;
	size_t	i;
	size_t	one;
	size_t	two;

	i = 0;
	one = ft_strlencpy(s1, 0, NULL, 0);
	two = size;
	res = (char *) ft_gnlcalloc(one + two + 1);
	if (!res)
		return (free(s1), NULL);
	while (i < one + two)
	{
		if (i < one)
			res[i] = s1[i];
		else
			res[i] = s2[i - one];
		i++;
	}
	free(s1);
	res[i] = 0;
	return (res);
}

//mode 0 == len, 1 == copy
size_t	ft_strlencpy(char *str, int mode, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (mode == 0)
	{
		if (!str)
			return (0);
		while (str[i] != 0)
			i++;
	}
	else
	{
		while (size > 1 && src[i] != 0)
		{
			str[i] = src[i];
			i++;
			size--;
		}
		str[i] = 0;
	}
	return (i);
}

char	*ft_gnlstrchr(const char *str, int c)
{
	char	*res;

	if (str == NULL)
		return (NULL);
	if (!*str && c != 0)
		return (NULL);
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

t_list	*finder(t_list **lst, int fd, size_t size)
{
	t_list	**temp;
	t_list	*nnode;

	nnode = ft_gnlcalloc (sizeof(t_list));
	if (!nnode)
		return (NULL);
	nnode->fd = fd;
	nnode->i = size;
	nnode->leftower = NULL;
	nnode->next = NULL;
	temp = lst;
	if (!*lst || !lst)
	{
		*lst = nnode;
		return (*lst);
	}
	while ((*temp)->next && (*temp)->fd != fd)
		temp = &(*temp)->next;
	if ((*temp)->fd == fd)
		return (free(nnode), *temp);
	(*temp)->next = nnode;
	return (nnode);
}

char	*helper(t_list **temp, size_t size, char *line)
{
	size_t	len;

	if (ft_gnlstrchr(line, '\n'))
	{
		len = ft_strlencpy(ft_gnlstrchr(line, '\n') + 1, 0, NULL, 0) + 1;
		free((*temp)->leftower);
		(*temp)->leftower = ft_gnlcalloc (len * sizeof(char));
		if (!(*temp)->leftower)
			return (NULL);
		ft_strlencpy((*temp)->leftower, 1, \
			ft_gnlstrchr(line, '\n') + 1, len);
		*(ft_gnlstrchr(line, '\n') + 1) = 0;
		return (line);
	}
	else
	{
		free((*temp)->leftower);
		(*temp)->leftower = NULL;
		if ((*temp)->i < (long)size)
			(*temp)->i = 0;
		return (line);
	}
}
