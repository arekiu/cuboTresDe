#include "cub3d.h"

int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

int	esc_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		on_destroy(game);
	return (0);
}
