#include "so_long.h"

void	kill_textures(t_char *wiff)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (wiff->text[i])
			del_nul(&(wiff->text[i]));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (wiff->aptext[i])
			del_nul(&(wiff->aptext[i]));
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (wiff->the_hole)
			if (wiff->the_hole->mytext[i])
				del_nul(&(wiff->the_hole->mytext[i]));
		i++;
	}
}

int	set_rect(t_char *wiff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	wiff->rect = mlx_new_image(wiff->mlx, 100, 30);
	if (!wiff->rect)
		return (failure(wiff));
	while (i < 100)
	{
		while (j < 20)
		{
			mlx_put_pixel(wiff->rect, i, j++, 255);
		}
		i++;
		j = 0;
	}
	if (mlx_image_to_window(wiff->mlx, wiff->rect, 0, 0) == -1)
		return (failure(wiff));
	return (0);
}

void	del_nul(mlx_texture_t **text)
{
	mlx_delete_texture(*text);
	*text = NULL;
}
