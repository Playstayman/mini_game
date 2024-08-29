#include "so_long.h"

int	place_floor(t_char *wiff)
{
	mlx_texture_t	*floor;
	mlx_image_t		*img;
	size_t			i;

	i = 0;
	wiff->prev_shift = 0;
	floor = mlx_load_png("textures/ground.png");
	if (!floor)
		return (failure(wiff));
	img = mlx_texture_to_image(wiff->mlx, floor);
	if (!img)
		return (failure(wiff));
	while (wiff->map[i])
	{
		if (wiff->map[i] == '0' || wiff->map[i] == 'P' || \
			wiff->map[i] == 'E' || wiff->map[i] == 'C')
			if (mlx_image_to_window(wiff->mlx, img, i % wiff->map_x * \
			100, i / wiff->map_x * 100) == -1)
				return (failure(wiff));
		i++;
	}
	del_nul(&floor);
	return (0);
}

int	place_walls(t_char *wiff)
{
	mlx_texture_t	*wall;
	mlx_image_t		*img;
	size_t			i;

	i = 0;
	wall = mlx_load_png("textures/wall.png");
	if (!wall)
		return (failure(wiff));
	img = mlx_texture_to_image(wiff->mlx, wall);
	if (!img)
		return (failure(wiff));
	while (wiff->map[i])
	{
		if (wiff->map[i] == '1')
			if (mlx_image_to_window(wiff->mlx, img, i % wiff->map_x * \
			100, i / wiff->map_x * 100) == -1)
				return (failure(wiff));
		i++;
	}
	del_nul(&wall);
	return (0);
}

int	set_exit(t_char *wiff, int i)
{
	wiff->the_hole->mytext[0] = mlx_load_png("textures/exit1.png");
	wiff->the_hole->mytext[1] = mlx_load_png("textures/exit2.png");
	wiff->the_hole->mytext[2] = mlx_load_png("textures/exit3.png");
	wiff->the_hole->mytext[3] = mlx_load_png("textures/exit4.png");
	wiff->the_hole->mytext[4] = mlx_load_png("textures/exit5.png");
	wiff->the_hole->mytext[5] = mlx_load_png("textures/exit6.png");
	wiff->the_hole->mytext[6] = mlx_load_png("textures/exit7.png");
	wiff->the_hole->mytext[7] = mlx_load_png("textures/exit8.png");
	wiff->the_hole->mytext[8] = mlx_load_png("textures/exit9.png");
	wiff->the_hole->mytext[9] = mlx_load_png("textures/exit10.png");
	wiff->the_hole->mytext[10] = mlx_load_png("textures/exit11.png");
	wiff->the_hole->mytext[11] = mlx_load_png("textures/exit12.png");
	while (i < 12)
	{
		if (!wiff->the_hole->mytext[i])
			return (failure(wiff));
		wiff->the_hole->myimg[i] = \
			mlx_texture_to_image(wiff->mlx, wiff->the_hole->mytext[i]);
		del_nul(&(wiff->the_hole->mytext[i]));
		if (!wiff->the_hole->myimg[i])
			return (failure(wiff));
		wiff->the_hole->myimg[i]->enabled = false;
		i++;
	}
	return (0);
}

int	place_exit(t_char *wiff)
{
	int	i;
	int	j;

	wiff->the_hole = malloc(sizeof(t_exit));
	if (!wiff->the_hole)
		return (failure(wiff));
	if (set_exit(wiff, 0))
		return (1);
	i = 0;
	j = 0;
	while (wiff->map[i])
	{
		if (wiff->map[i] == 'E')
			while (j < 12)
				if (mlx_image_to_window(wiff->mlx, \
					wiff->the_hole->myimg[j++], i % wiff->map_x * 100, \
					i / wiff->map_x * 100) == -1)
					return (failure(wiff));
		i++;
	}
	wiff->the_hole->myimg[0]->enabled = true;
	return (0);
}
