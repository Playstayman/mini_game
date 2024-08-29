#include "so_long.h"

int	redraw(t_char *wiff)
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

int	move_up(t_char *wiff, mlx_image_t *img)
{
	if (wiff->shift < 4)
	{
		wiff->prev_shift = wiff->shift;
		wiff->shift += 4;
	}
	if (redraw(wiff))
		return (EXIT_FAILURE);
	img = wiff->myimg[0];
	if (wiff->map[wiff->x / 100 + (wiff->y / 100 - 1) * \
		wiff->map_x] != '1')
	{
		img->instances[0].y -= img->height;
		wiff->y -= 100;
		wiff->moves++;
	}
	if (wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] == 'C')
		collect(wiff);
	if (wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] == 'E' && \
		wiff->collectabes == 0)
		finish(wiff);
	return (0);
}

int	move_left(t_char *wiff, mlx_image_t *img)
{
	wiff->shift = 0;
	if (redraw(wiff))
		return (EXIT_FAILURE);
	img = wiff->myimg[0];
	if (wiff->map[wiff->x / 100 - 1 + wiff->y / 100 * wiff->map_x] != '1')
	{
		img->instances[0].x -= img->width;
		wiff->x -= 100;
		wiff->moves++;
	}
	if (wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] == 'C')
		collect(wiff);
	if (wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] == 'E' && \
		wiff->collectabes == 0)
		finish(wiff);
	return (0);
}

int	move_right(t_char *wiff, mlx_image_t *img)
{
	wiff->shift = 2;
	if (redraw(wiff))
		return (EXIT_FAILURE);
	img = wiff->myimg[0];
	if (wiff->map[wiff->x / 100 + 1 + wiff->y / 100 * wiff->map_x] != '1')
	{
		img->instances[0].x += img->width;
		wiff->x += 100;
		wiff->moves++;
	}
	if (wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] == 'C')
		collect(wiff);
	if (wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] == 'E' && \
		wiff->collectabes == 0)
		finish(wiff);
	return (0);
}

int	move_down(t_char *wiff, mlx_image_t *img)
{
	wiff->shift = wiff->prev_shift;
	if (redraw(wiff))
		return (EXIT_FAILURE);
	img = wiff->myimg[0];
	if (wiff->map[wiff->x / 100 + (wiff->y / 100 + 1) * \
		wiff->map_x] != '1')
	{
		img->instances[0].y += img->height;
		wiff->y += 100;
		wiff->moves++;
	}
	if (wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] == 'C')
		collect(wiff);
	if (wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] == 'E' && \
		wiff->collectabes == 0)
		finish(wiff);
	return (0);
}
