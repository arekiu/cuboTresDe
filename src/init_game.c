#include "cub3d.h"

int	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		ft_printf("Error allocating memory for player\n");
		return (0);
	}
	game->player->x = WIDTH / 2;
	game->player->y = HEIGHT / 2;
	return (1);
}

void init_game(t_game *game)
{
	game->image = NULL;
	game->mlx = NULL;
}

int init_mlx(t_game *game)
{
	init_player(game);
	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!game->mlx)
	{
		ft_printf("Error initializing MLX\n");
		return (0);
	}
	game->image = mlx_new_image(game->mlx, 50, 50);
	if (!game->image)
	{
		mlx_close_window(game->mlx);
		ft_printf("Error creating image\n");
		return (0);
	}

	draw_square(game->image, 50, 0xFF0000FF);
	if (mlx_image_to_window(game->mlx, game->image, game->player->x, game->player->y) == -1)
	{
		mlx_close_window(game->mlx);
		ft_printf("Error adding image to window\n");
		return (0);
	}

	return (1);
}
