#include "get_next_line.h"

void	*ft_gnlcalloc(int size)
{
	char	*res;
	int		i;

	i = size;
	res = malloc(size);
	if (!res)
		return (NULL);
	while (i-- > 0)
		res[i] = '\0';
	return (res);
}

void	line_filler(t_list **temp, int fd, char *buffer, char **line)
{
	if ((*temp)->leftower)
		ft_strlencpy(*line, 1, (*temp)->leftower, \
			ft_strlencpy((*temp)->leftower, 0, NULL, 0) + 1);
	while (!ft_gnlstrchr(*line, '\n') && (*temp)->i == BUFFER_SIZE)
	{
		(*temp)->i = read(fd, buffer, BUFFER_SIZE);
		if ((*temp)->i != BUFFER_SIZE && (*temp)->i != 0 && (*temp)->i != -1)
			buffer[(*temp)->i] = 0;
		if ((*temp)->i >= 1)
		{
			*line = ft_gnlstrjoin(*line, buffer, BUFFER_SIZE);
			if (!*line)
				return ;
		}
	}
	return ;
}

void	freer(t_list **temp, char *buffer)
{
	if (*temp)
	{
		free(buffer);
		free ((*temp)->leftower);
		(*temp)->fd = 0;
		(*temp)->next = NULL;
		(*temp)->leftower = NULL;
		(*temp)->i = 0;
		free(*temp);
		*temp = NULL;
	}
}

char	*get_next_line(int fd)
{
	char			*buffer;
	static t_list	*list;
	t_list			*temp;
	char			*line;

	if (fd < 0)
		return (NULL);
	temp = finder(&list, fd, BUFFER_SIZE);
	if (!temp)
		return (freer(&list, NULL), NULL);
	line = ft_gnlcalloc (sizeof(char) * (BUFFER_SIZE));
	buffer = ft_gnlcalloc(BUFFER_SIZE * sizeof(char));
	if (!line || !buffer)
		return (free(line), freer(&temp, buffer), NULL);
	line_filler(&temp, fd, buffer, &line);
	if (line == NULL)
		return (freer (&temp, buffer), NULL);
	if (!*line || temp->i < 0)
		return (freer(&list, buffer), free(line), NULL);
	if (!helper(&temp, BUFFER_SIZE, line))
		return (freer (&list, buffer), free (line), NULL);
	return (free (buffer), line);
}

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *pr;
// 	while (1)
// 	{
// 		pr = get_next_line(fd);
// 		if (pr)
// 		{
// 			printf("%s", pr);
// 			free (pr);
// 		}
// 		else
// 			break;
// 	}
// 	close (fd);
// }