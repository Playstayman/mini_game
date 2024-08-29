#include "so_long.h"

int	make_apple(t_char *wiff, int x)
{
	t_apple	*tmp;
	t_apple	*new;

	tmp = wiff->apples;
	while (tmp && tmp->next)
		tmp = tmp->next;
	new = malloc(sizeof(t_apple));
	if (!new)
		return (1);
	new->x = x % wiff->map_x * 100;
	new->y = x / wiff->map_x * 100;
	new->next = NULL;
	new->myimg[0] = NULL;
	new->myimg[1] = NULL;
	new->myimg[2] = NULL;
	new->myimg[3] = NULL;
	wiff->collectabes++;
	if (tmp)
		tmp->next = new;
	else
		wiff->apples = new;
	return (0);
}

int	amounts(t_char *wiff, char *map)
{
	int		x;
	char	point;

	x = 0;
	point = map[x];
	while (point != '\0')
	{
		if (point == 'C')
			if (make_apple(wiff, x))
				return (write(2, "apple malloc error\n", 20), 1);
		if (point == 'E')
			wiff->exit++;
		if (point == 'P')
		{
			wiff->x = x % wiff->map_x * 100;
			wiff->y = x / wiff->map_x * 100;
			wiff->player++;
		}
		x++;
		point = map[x];
	}
	if (wiff->exit != 1 || wiff->collectabes < 1 || wiff->player != 1)
		return (write(2, "wrong number of smth\n", 22), 1);
	return (0);
}

void	reach(t_char *wiff, char *map, int x, int y)
{
	int	pos;

	pos = x + y * wiff->map_x;
	if (map[pos] == '1')
		return ;
	if (map[pos] == 'C')
		wiff->reachable++;
	if (map[pos] == 'E')
		wiff->reach_exit++;
	map[pos] = '1';
	if (x < wiff->map_x && x > 0)
		(reach(wiff, map, x + 1, y), reach(wiff, map, x - 1, y));
	if (y < wiff->map_y && y > 0)
		(reach(wiff, map, x, y + 1), reach(wiff, map, x, y - 1));
}
