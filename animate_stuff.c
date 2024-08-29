#include "so_long.h"

int	animate_apples(t_char *wiff, t_apple *tmp)
{
	while (tmp)
	{
		tmp->myimg[(wiff->frame / 30 + 1) % 4]->enabled = true;
		tmp->myimg[(wiff->frame / 30) % 4]->enabled = false;
		tmp = tmp->next;
	}
	wiff->the_hole->myimg[(wiff->frame / 30 + 1) % 12]->enabled = true;
	wiff->the_hole->myimg[(wiff->frame / 30) % 12]->enabled = false;
	return (0);
}

int	animate_wiff(t_char *wiff)
{
	wiff->myimg[1] = mlx_texture_to_image(wiff->mlx, \
		wiff->text[(wiff->frame / 60) % 2 + wiff->shift]);
	wiff->myimg[1]->enabled = false;
	if (mlx_image_to_window(wiff->mlx, wiff->myimg[1], wiff->x, wiff->y) == -1)
		return (failure(wiff));
	wiff->myimg[1]->enabled = true;
	mlx_delete_image(wiff->mlx, wiff->myimg[0]);
	wiff->myimg[0] = wiff->myimg[1];
	wiff->myimg[1] = NULL;
	return (0);
}
