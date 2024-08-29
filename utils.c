#include "so_long.h"

void	collect(t_char *wiff)
{
	t_apple	*tmp;
	t_apple	*swap;

	tmp = wiff->apples;
	if (tmp->x == wiff->x && tmp->y == wiff->y)
		wiff->apples = tmp->next;
	else
	{
		while (tmp->next->x != wiff->x || tmp->next->y != wiff->y)
		{
			tmp = tmp->next;
		}
		swap = tmp->next;
		tmp->next = tmp->next->next;
		tmp = swap;
	}
	mlx_delete_image(wiff->mlx, tmp->myimg[0]);
	mlx_delete_image(wiff->mlx, tmp->myimg[1]);
	mlx_delete_image(wiff->mlx, tmp->myimg[2]);
	mlx_delete_image(wiff->mlx, tmp->myimg[3]);
	free(tmp);
	wiff->collectabes--;
	wiff->map[wiff->x / 100 + wiff->y / 100 * wiff->map_x] = '0';
}

void	finish(t_char *wiff)
{
	mlx_put_string(wiff->mlx, "congrats", wiff->x, wiff->y);
}

char	*ft_strjoin2(const char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1)
		return (free(s2), NULL);
	if (!s2)
		j = 0;
	else
		j = ft_strlen(s2);
	i = 0;
	res = (char *)ft_calloc(j + ft_strlen(s1) + 1, 1);
	if (!res)
		return (free(s2), NULL);
	while (i < j + ft_strlen(s1))
	{
		if (i < ft_strlen(s1))
			res[i] = s1[i];
		else
			res[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	res[i] = 0;
	free (s2);
	return (res);
}

void	end_it_all(t_char *wiff)
{
	t_apple	*tmp;
	t_apple	*swap;

	tmp = NULL;
	del_nul(&(wiff->text[0]));
	del_nul(&(wiff->text[1]));
	del_nul(&(wiff->text[2]));
	del_nul(&(wiff->text[3]));
	del_nul(&(wiff->text[4]));
	del_nul(&(wiff->text[5]));
	del_nul(&(wiff->text[6]));
	del_nul(&(wiff->text[7]));
	mlx_terminate(wiff->mlx);
	free(wiff->map);
	free(wiff->the_hole);
	if (wiff->apples)
		tmp = wiff->apples;
	while (tmp)
	{
		swap = tmp->next;
		free(tmp);
		tmp = swap;
	}
}

int	failure(t_char *wiff)
{
	t_apple	*tmp;
	t_apple	*swap;

	kill_textures(wiff);
	if (wiff->mlx)
		mlx_terminate(wiff->mlx);
	free(wiff->map);
	free(wiff->the_hole);
	tmp = wiff->apples;
	while (tmp)
	{
		swap = tmp->next;
		free(tmp);
		tmp = swap;
	}
	if (mlx_errno != 0)
		ft_printf("%s\n", mlx_strerror(mlx_errno));
	exit(1);
}
