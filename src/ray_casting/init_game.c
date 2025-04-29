#include "../cub3d.h"

void	init_game(t_game *game)
{
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		exit(1);
	init_textures(game);
	init_player(game->player, game->player->orientation, game->player->x, game->player->y);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game->img = mlx_new_image(game->mlx,WIN_WIDTH, WIN_HEIGHT);
	game->buffer = mlx_get_data_addr(game->img, &game->bpp, &game->stride, &game->endian);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
}

void	init_textures(t_game *game)
{
	game->no_text = malloc(sizeof(t_texture));
	game->so_text = malloc(sizeof(t_texture));
	game->we_text = malloc(sizeof(t_texture));
	game->ea_text = malloc(sizeof(t_texture));
	if (!game->no_text || !game->so_text || !game->we_text || !game->ea_text)
		exit(1);
	load_texture(game, game->no_text, game->data->NO_path);
	load_texture(game, game->so_text, game->data->NO_path);
	load_texture(game, game->ea_text, game->data->NO_path);
	load_texture(game, game->we_text, game->data->NO_path);
	//CATCH POSSIBILIY THAT TEXTURE PATH IS WRONG
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


int	draw_loop(t_game *game)
{
	game->ray->current_x = 0;
	move_player(game);
	clear(game);
	while (game->ray->current_x < WIN_WIDTH)
	{
		raycaster(game);
		ray_drawer(game);
		game->ray->current_x++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (1);
}
