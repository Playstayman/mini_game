#include "so_long.h"

void	wiff_text(t_char *wiff)
{
	wiff->text[0] = mlx_load_png("textures/left1.png");
	wiff->text[1] = mlx_load_png("textures/left2.png");
	wiff->text[2] = mlx_load_png("textures/right1.png");
	wiff->text[3] = mlx_load_png("textures/right2.png");
	wiff->text[4] = mlx_load_png("textures/forward1.png");
	wiff->text[5] = mlx_load_png("textures/forward2.png");
	wiff->text[6] = mlx_load_png("textures/forward3.png");
	wiff->text[7] = mlx_load_png("textures/forward4.png");
	wiff->aptext[0] = mlx_load_png("textures/apple1.png");
	wiff->aptext[1] = mlx_load_png("textures/apple2.png");
	wiff->aptext[2] = mlx_load_png("textures/apple3.png");
	wiff->aptext[3] = mlx_load_png("textures/apple4.png");
}

int	set_wiff(t_char *wiff)
{
	wiff->collectabes = 0;
	wiff->frame = 0;
	wiff->exit = 0;
	wiff->player = 0;
	wiff->reach_exit = 0;
	wiff->reachable = 0;
	wiff->shift = 0;
	wiff->map_x = 0;
	wiff->map_y = 0;
	wiff_text(wiff);
	wiff->apples = NULL;
	wiff->map = NULL;
	wiff->moves = 0;
	wiff->the_hole = NULL;
	wiff->movedisplay = NULL;
	wiff->rect = NULL;
	wiff->mlx = NULL;
	if (!wiff->text[0] || !wiff->text[1] || !wiff->text[2] || !wiff->text[3] \
		|| !wiff->text[4] || !wiff->text[5] || !wiff->aptext[0] || \
		!wiff->aptext[1] || !wiff->aptext[2] || !wiff->aptext[3])
		return (failure(wiff));
	return (0);
}
// wiff->locked = 0;
// wiff->sleeping = 0;
// wiff->time_since_move = 0;

int	draw_apples(t_char *wiff)
{
	t_apple	*tmp;
	int		i;

	tmp = wiff->apples;
	while (tmp)
	{
		i = 0;
		while (i < 4)
			if (mlx_image_to_window(wiff->mlx, tmp->myimg[i++], \
				tmp->x, tmp->y) == -1)
				return (failure(wiff));
		tmp = tmp->next;
	}
	return (0);
}

int	set_apples(t_char *wiff)
{
	t_apple	*temp;

	temp = wiff->apples;
	if (!wiff->aptext[0] || !wiff->aptext[1] || \
		!wiff->aptext[2] || !wiff->aptext[3])
		return (failure(wiff));
	while (temp)
	{
		temp->myimg[0] = mlx_texture_to_image(wiff->mlx, wiff->aptext[0]);
		temp->myimg[1] = mlx_texture_to_image(wiff->mlx, wiff->aptext[1]);
		temp->myimg[2] = mlx_texture_to_image(wiff->mlx, wiff->aptext[2]);
		temp->myimg[3] = mlx_texture_to_image(wiff->mlx, wiff->aptext[3]);
		temp->myimg[0]->enabled = true;
		temp->myimg[1]->enabled = false;
		temp->myimg[2]->enabled = false;
		temp->myimg[3]->enabled = false;
		temp = temp->next;
	}
	(del_nul(&(wiff->aptext[0])), del_nul(&(wiff->aptext[1])));
	(del_nul(&(wiff->aptext[2])), del_nul(&(wiff->aptext[3])));
	return (draw_apples(wiff));
}
