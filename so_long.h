#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include "lib/get_next_line.h"
# include "lib1/libft.h"
# include "lib1/ft_printf.h"

typedef struct t_exit
{
	mlx_image_t		*myimg[12];
	mlx_texture_t	*mytext[12];
}	t_exit;

typedef struct t_apple
{
	mlx_image_t		*myimg[4];
	int				x;
	int				y;
	struct t_apple	*next;
}	t_apple;

// int				time_since_move;
// int				sleeping;
// int				locked;
typedef struct t_char
{
	mlx_t			*mlx;
	int				x;
	int				y;
	int				map_x;
	int				map_y;
	int				frame;
	int				collectabes;
	int				reachable;
	int				shift;
	int				exit;
	int				reach_exit;
	int				player;
	char			*map;
	int				moves;
	int				prev_shift;
	t_apple			*apples;
	mlx_image_t		*myimg[2];
	mlx_image_t		*movedisplay;
	mlx_image_t		*rect;
	mlx_texture_t	*text[8];
	mlx_texture_t	*aptext[4];
	t_exit			*the_hole;
}	t_char;

int		place_floor(t_char *wiff);
int		place_walls(t_char *wiff);
int		place_exit(t_char *wiff);
char	*handleinput(int argc, char **argv, t_char *wiff);
int		handle_map(t_char *wiff, char *map);
int		amounts(t_char *wiff, char *map);
int		set_wiff(t_char *wiff);
int		animate_apples(t_char *wiff, t_apple *tmp);
int		animate_wiff(t_char *wiff);
int		set_apples(t_char *wiff);
void	reach(t_char *wiff, char *map, int x, int y);
int		move_up(t_char *wiff, mlx_image_t *img);
int		move_left(t_char *wiff, mlx_image_t *img);
int		move_right(t_char *wiff, mlx_image_t *img);
int		move_down(t_char *wiff, mlx_image_t *img);
void	collect(t_char *wiff);
void	finish(t_char *wiff);
char	*ft_strjoin2(const char *s1, char *s2);
void	end_it_all(t_char *wiff);
int		failure(t_char *wiff);
int		set_rect(t_char *wiff);
void	kill_textures(t_char *wiff);
void	del_nul(mlx_texture_t **text);

#endif
