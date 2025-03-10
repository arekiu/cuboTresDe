#include "cub3d.h"

void draw_square(mlx_image_t *image, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_put_pixel(image, i , j, color);
			j++;
		}
		i++;
	}
}

void ft_hook(void *param)
{
	t_game *game = (t_game *)param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		game->image->instances[0].y -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		game->image->instances[0].y += 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->image->instances[0].x -= 5;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->image->instances[0].x += 5;
}
