#include "cub3d.h"

void	init_game(t_game *game)
{
	int	map_height;
	int	map_width;

	game->map = get_map();
	map_width = get_map_width(game->map);
	map_height = get_map_height(game->map);
	game->screen_width = map_width * BLOCK;
	game->screen_height = map_height * BLOCK;

	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		ft_printf("Error: Memory allocation failed\n");
		exit(1);
	}
	game->raycaster = malloc(sizeof(t_ray));
	if (!game->raycaster)
		exit(1);
	init_player(game->player, WE, 5, 7);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "cub3d");
	game->img = mlx_new_image(game->mlx,game->screen_width, game->screen_height);
	game->buffer = mlx_get_data_addr(game->img, &game->bpp, &game->stride, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}

void	init_player(t_player *player, float orientation, int x, int y)
{
	player->angle = orientation;
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);
	player->player_size = PLAYER_SIZE;
	player->x = x * BLOCK;
	player->y = y * BLOCK;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
	player->speed = PLAYER_SPEED;
	player->angle_speed = PLAYER_ANGLE_SPEED;
	// Set the plane perpendicular to the direction
	player->plane_x = -player->dir_y * 0.66;  // 0.66 controls FOV (default 66°)
	player->plane_y = player->dir_x * 0.66;
}
