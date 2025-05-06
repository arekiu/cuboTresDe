/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:08:36 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/06 13:27:45 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_player(t_game *game)
{
	if (game->player->left_rotate)
		game->player->angle -= game->player->angle_speed * game->delta_time;
	if (game->player->right_rotate)
		game->player->angle += game->player->angle_speed * game->delta_time;
	if (game->player->angle > 2 * PI)
		game->player->angle = 0;
	if (game->player->angle < 0)
		game->player->angle = 2 * PI;
	game->player->dir_x = cos(game->player->angle);
	game->player->dir_y = sin(game->player->angle);
	game->player->plane_x = -game->player->dir_y * 0.66;
	game->player->plane_y = game->player->dir_x * 0.66;
}

static void	try_move_player(t_game *game, float next_x, float next_y)
{
	t_player	*p;
	float		s;
	char		**map;

	p = game->player;
	s = p->player_size / 2;
	map = game->data->map;
	if (map[(int)((p->y - s) / BLOCK)][(int)((next_x - s) / BLOCK)] != '1' && \
		map[(int)((p->y + s) / BLOCK)][(int)((next_x - s) / BLOCK)] != '1' && \
		map[(int)((p->y - s) / BLOCK)][(int)((next_x + s) / BLOCK)] != '1' && \
		map[(int)((p->y + s) / BLOCK)][(int)((next_x + s) / BLOCK)] != '1')
	{
		p->x = next_x;
	}
	if (map[(int)((next_y - s) / BLOCK)][(int)((p->x - s) / BLOCK)] != '1' && \
		map[(int)((next_y + s) / BLOCK)][(int)((p->x - s) / BLOCK)] != '1' && \
		map[(int)((next_y - s) / BLOCK)][(int)((p->x + s) / BLOCK)] != '1' && \
		map[(int)((next_y + s) / BLOCK)][(int)((p->x + s) / BLOCK)] != '1')
	{
		p->y = next_y;
	}
}

static void	calc_next_pos(t_game *game, float *next_x, float *next_y, int dir)
{
	int			speed;
	t_player	*player;

	player = game->player;
	speed = player->speed;
	if (dir == NORTH)
	{
		*next_x = player->x + player->dir_x * speed * game->delta_time;
		*next_y = player->y + player->dir_y * speed * game->delta_time;
	}
	if (dir == SOUTH)
	{
		*next_x = player->x - player->dir_x * speed * game->delta_time;
		*next_y = player->y - player->dir_y * speed * game->delta_time;
	}
	if (dir == WEST)
	{
		*next_x = player->x + player->dir_y * speed * game->delta_time;
		*next_y = player->y - player->dir_x * speed * game->delta_time;
	}
	if (dir == EAST)
	{
		*next_x = player->x - player->dir_y * speed * game->delta_time;
		*next_y = player->y + player->dir_x * speed * game->delta_time;
	}
}

void	move_in_direct(t_game *game)
{
	float	next_x;
	float	next_y;

	if (game->player->key_up)
	{
		calc_next_pos(game, &next_x, &next_y, NORTH);
		try_move_player(game, next_x, next_y);
	}
	if (game->player->key_down)
	{
		calc_next_pos(game, &next_x, &next_y, SOUTH);
		try_move_player(game, next_x, next_y);
	}
	if (game->player->key_left)
	{
		calc_next_pos(game, &next_x, &next_y, WEST);
		try_move_player(game, next_x, next_y);
	}
	if (game->player->key_right)
	{
		calc_next_pos(game, &next_x, &next_y, EAST);
		try_move_player(game, next_x, next_y);
	}
}

void	move_player(t_game *game)
{
	rotate_player(game);
	move_in_direct(game);
}
