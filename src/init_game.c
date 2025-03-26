#include "cub3d.h"

void	init_game(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		ft_printf("Error: Memory allocation failed\n");
		exit(1);
	}
	init_player(game->player, NO, WIDTH / 2, HEIGHT/2); // jess: i guess x/y has to change based on the map file player position?
	game->map = get_map();
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
	game->img = mlx_new_image(game->mlx,WIDTH, HEIGHT);
	game->buffer = mlx_get_data_addr(game->img, &game->bpp, &game->stride, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}

void	init_player(t_player *player, float orientation, int x, int y)
{
	player->angle = orientation;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	player->player_size = PLAYER_SIZE;
	player->x = x;
	player->y = y;
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
	player->speed = PLAYER_SPEED;
	player->angle_speed = PLAYER_ANGLE_SPEED;
}
