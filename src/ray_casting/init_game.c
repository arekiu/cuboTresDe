#include "../cub3d.h"

void	init_game(t_game *game)
{
	int	map_height;
	int	map_width;

	map_width = get_map_width(game->data->map);
	map_height = get_map_height(game->data->map);
	game->screen_width = map_width * BLOCK;
	game->screen_height = map_height * BLOCK;

	game->raycaster = malloc(sizeof(t_ray));
	if (!game->raycaster)
		exit(1);
	init_player(game->player, game->player->orientation, game->player->x, game->player->y);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->screen_width, game->screen_height, "cub3d");
	game->img = mlx_new_image(game->mlx,game->screen_width, game->screen_height);
	game->buffer = mlx_get_data_addr(game->img, &game->bpp, &game->stride, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}

void	init_player(t_player *player, float orientation, int x, int y)
{
	if(orientation == 'W')
		player->angle = WE;
	else if (orientation == 'E')
		player->angle = EA;
	else if (orientation == 'N')
		player->angle = NO;
	else if (orientation == 'S')
		player->angle = SO;
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
