#include "so_long.h"

int	surrounding(t_char *wiff, char *map)
{
	int		x;
	int		y;
	char	point;

	x = 0;
	while (x < wiff->map_x)
	{
		y = 0;
		while (y < wiff->map_y)
		{
			point = map[y * wiff->map_x + x];
			if ((x == 0 || x == wiff->map_x - 1) && point != '1')
				return (write(2, "not enclosed\n", 14), 1);
			if ((y == 0 || y == wiff->map_y - 1) && point != '1')
				return (write(2, "not enclosed\n", 14), 1);
			y++;
		}
		x++;
	}
	return (0);
}

// 111111000111111

int	symb(t_char *wiff, char *map)
{
	int		x;
	char	point;

	x = 0;
	point = map[x];
	while (point != 0)
	{
		if (point == '1' || point == '0' || \
			point == 'C' || point == 'E' || point == 'P')
			x++;
		else
			return (write(2, "wrong marks\n", 13), 1);
		point = map[x];
	}
	return (0);
}

int	handle_map(t_char *wiff, char *map)
{
	char	*maptocheck;

	if (symb(wiff, map))
		return (1);
	if (surrounding(wiff, map))
		return (1);
	if (amounts(wiff, map))
		return (1);
	maptocheck = malloc(ft_strlen(map) + 1);
	ft_strlcpy(maptocheck, map, ft_strlen(map) + 1);
	reach(wiff, maptocheck, wiff->x / 100, wiff->y / 100);
	free(maptocheck);
	if (wiff->reach_exit == 0 || wiff->collectabes > wiff->reachable)
		return (write(2, "smth isn't reachable\n", 22), 1);
	return (0);
}

char	*get_map(t_char *wiff, char **argv, int fd)
{
	char	*temp;
	int		x;
	int		y;
	char	*map;

	map = NULL;
	if (fd < 0)
		return (write(2, "file bruh\n", 11), NULL);
	temp = ft_strtrim(get_next_line(fd), "\n");
	x = ft_strlen(temp);
	while (temp)
	{
		map = ft_strjoin(map, temp);
		free(temp);
		if (!map)
			return (close(fd), NULL);
		temp = ft_strtrim(get_next_line(fd), "\n");
		if (x != ft_strlen(temp) && temp != NULL)
			return (write(2, "not rectang\n", 13), free(temp), \
				free(map), close(fd), NULL);
		wiff->map_y++;
	}
	wiff->map_x = x;
	return (close(fd), map);
}

char	*handleinput(int argc, char **argv, t_char *wiff)
{
	char	*temp;
	char	*map;
	int		fd;

	if (argc != 2)
		return (write(2, "just one argument\n", 19), NULL);
	if (ft_strncmp((argv[1] + ft_strlen(argv[1]) - 4), ".ber", 4) != 0)
		return (write(2, "not a map format\n", 18), NULL);
	fd = open(argv[1], O_RDONLY);
	map = get_map(wiff, argv, fd);
	if (!map)
		return (write(2, "malloc error or empty map\n", 27), NULL);
	if (handle_map(wiff, map))
		return (free(map), NULL);
	return (map);
}
