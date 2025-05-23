/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:07:17 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/23 13:52:58 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_game(t_game *game)
{
	game->ray = malloc(sizeof(t_ray));
	if (!game->ray)
		exit(1);
	game->mlx = mlx_init();
	init_textures(game);
	init_player(game->player, game->player->orientation, \
		game->player->x, game->player->y);
	game->window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	game->img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	game->buffer = mlx_get_data_addr(game->img, &game->bpp, \
		&game->stride, &game->endian);
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
	load_texture(game, game->no_text, game->data->no_path);
	load_texture(game, game->so_text, game->data->so_path);
	load_texture(game, game->ea_text, game->data->ea_path);
	load_texture(game, game->we_text, game->data->we_path);
}

void	init_player(t_player *player, float orientation, int x, int y)
{
	if (orientation == 'W')
		player->angle = PI;
	else if (orientation == 'E')
		player->angle = 0;
	else if (orientation == 'N')
		player->angle = 3 * PI / 2;
	else if (orientation == 'S')
		player->angle = PI / 2;
	player->dir_x = cos(player->angle);
	player->dir_y = sin(player->angle);
	player->player_size = PLAYER_SIZE;
	player->x = (x * BLOCK) + (BLOCK / 2);
	player->y = (y * BLOCK) + (BLOCK / 2);
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
	player->speed = PLAYER_SPEED;
	player->angle_speed = PLAYER_ANGLE_SPEED;
	player->plane_x = -player->dir_y * 0.66;
	player->plane_y = player->dir_x * 0.66;
}

int	draw_loop(t_game *game)
{
	double	current_time;

	current_time = get_time_in_ms();
	game->delta_time = (current_time - game->last_frame_time) / 1000.0;
	game->last_frame_time = current_time;
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
