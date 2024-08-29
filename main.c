#include "so_long.h"

#define WIDTH 1000
#define HEIGHT 1000

void	animate(void *placeholder)
{
	t_char	*wiff;
	t_apple	*tmp;

	wiff = placeholder;
	tmp = wiff->apples;
	if (wiff->frame % 30 == 0)
		if (animate_apples(wiff, tmp))
			exit (EXIT_FAILURE);
	if ((wiff->frame + 15) % 60 == 0)
		if (animate_wiff(wiff))
			exit (EXIT_FAILURE);
	wiff->frame++;
}
// wiff->time_since_move++;
//code sleeping

void	key_press(struct mlx_key_data data, void *param)
{
	t_char		*wiff;
	mlx_image_t	*img;
	char		*temp;

	wiff = param;
	img = wiff->myimg[0];
	if (wiff->movedisplay)
		mlx_delete_image(wiff->mlx, wiff->movedisplay);
	if (mlx_is_key_down(wiff->mlx, MLX_KEY_UP))
		move_up(wiff, img);
	else if (mlx_is_key_down(wiff->mlx, MLX_KEY_DOWN))
		move_down(wiff, img);
	else if (mlx_is_key_down(wiff->mlx, MLX_KEY_LEFT))
		move_left(wiff, img);
	else if (mlx_is_key_down(wiff->mlx, MLX_KEY_RIGHT))
		move_right(wiff, img);
	temp = ft_strjoin2("moves: ", ft_itoa(wiff->moves));
	wiff->movedisplay = mlx_put_string(wiff->mlx, temp, 0, 0);
	free(temp);
}

void	ft_hook(void *param)
{
	t_char	*wiff;

	wiff = param;
	if (mlx_is_key_down(wiff->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(wiff->mlx);
	mlx_key_hook(wiff->mlx, &key_press, wiff);
}

// -----------------------------------------------------------------------------

int	main(int argc, char **argv)
{
	t_char	wiff;

	if (set_wiff(&wiff))
		return (EXIT_FAILURE);
	wiff.map = handleinput(argc, argv, &wiff);
	if (!wiff.map)
		return (failure(&wiff));
	wiff.mlx = mlx_init(wiff.map_x * 100, wiff.map_y * 100, "Wiff", false);
	if (!(wiff.mlx))
		return (failure(&wiff));
	if (place_floor(&wiff) || place_walls(&wiff) || set_apples(&wiff))
		return (EXIT_FAILURE);
	if (place_exit(&wiff) || set_rect(&wiff))
		return (EXIT_FAILURE);
	wiff.myimg[0] = mlx_texture_to_image(wiff.mlx, wiff.text[0]);
	if (mlx_image_to_window(wiff.mlx, wiff.myimg[0], wiff.x, wiff.y) == -1)
		return (failure(&wiff));
	wiff.movedisplay = mlx_put_string(wiff.mlx, "moves: 0", 0, 0);
	mlx_loop_hook(wiff.mlx, animate, &wiff);
	mlx_loop_hook(wiff.mlx, ft_hook, &wiff);
	mlx_loop(wiff.mlx);
	end_it_all(&wiff);
	return (EXIT_SUCCESS);
}
