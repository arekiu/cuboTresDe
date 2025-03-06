#include "cub3d.h"

void draw_square(mlx_image_t *image, uint32_t size, int32_t color)
{
	for (uint32_t i = 0; i < size; ++i)
	{
		for (uint32_t y = 0; y < size; ++y)
		{
			mlx_put_pixel(image, i, y, color);
		}
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


void init_game(t_game *game)
{
	game->image = NULL;
	game->mlx = NULL;
}

int init_mlx(t_game *game)
{
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

	if (mlx_image_to_window(game->mlx, game->image, 0, 0) == -1)
	{
		mlx_close_window(game->mlx);
		ft_printf("Error adding image to window\n");
		return (0);
	}

	return (1);
}

int main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Error!!!\nInvalid number of arguments\n");
		return (1);
	}
	if(argv[1])
		ft_printf("Hay arg!");
	init_game(&game);
	if (!init_mlx(&game))
		return (1);

	mlx_loop_hook(game.mlx, ft_hook, &game);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	return (0);
}
