/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birdieber <birdieber@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:09:18 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/25 17:42:18 by birdieber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calc_side_dist(t_game *game)
{
	if (game->ray->dir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->side_x = (game->player->x / BLOCK - game->ray->map_x)
			* game->ray->delta_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->side_x = (game->ray->map_x + 1.0 - game->player->x
				/ BLOCK) * game->ray->delta_x;
	}
	if (game->ray->dir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->side_y = (game->player->y / BLOCK - game->ray->map_y)
			* game->ray->delta_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->side_y = (game->ray->map_y + 1.0 - game->player->y
				/ BLOCK) * game->ray->delta_y;
	}
}

void	calc_delta_dist(t_ray *ray)
{
	if (ray->dir_x == 0)
		ray->delta_x = 1e30;
	else if (ray->dir_x > 0)
		ray->delta_x = 1 / ray->dir_x;
	else
		ray->delta_x = 1 / -ray->dir_x;
	if (ray->dir_y == 0)
		ray->delta_y = 1e30;
	else if (ray->dir_y > 0)
		ray->delta_y = 1 / ray->dir_y;
	else
		ray->delta_y = 1 / -ray->dir_y;
}

void	set_side(t_game *game, char hit)
{
	t_ray	*ray;

	ray = game->ray;
	if (hit == 'x')
	{
		if (ray->dir_x < 0)
			ray->side = WEST;
		else
			ray->side = EAST;
	}
	else if (hit == 'y')
	{
		if (ray->dir_y < 0)
			ray->side = NORTH;
		else
			ray->side = SOUTH;
	}
}

void	perform_dda(t_game *game)
{
	game->ray->hit_side = 0;
	while (game->ray->hit_side == 0)
	{
		if (game->ray->side_x < game->ray->side_y)
		{
			game->ray->side_x += game->ray->delta_x;
			game->ray->map_x += game->ray->step_x;
			set_side(game, 'x');
		}
		else
		{
			game->ray->side_y += game->ray->delta_y;
			game->ray->map_y += game->ray->step_y;
			set_side(game, 'y');
		}
		if (game->data->map[game->ray->map_y][game->ray->map_x] == '1')
			game->ray->hit_side = 1;
		if (game->ray->side == 0 || game->ray->side == 1)
			game->ray->wall_dist = (game->ray->side_x - game->ray->delta_x);
		else
			game->ray->wall_dist = (game->ray->side_y - game->ray->delta_y);
	}
}

void	raycaster(t_game *game)
{
	game->ray->camera_x = 2 * game->ray->current_x / (double)WIN_WIDTH - 1;
	game->ray->dir_x = game->player->dir_x + game->player->plane_x
		* game->ray->camera_x;
	game->ray->dir_y = game->player->dir_y + game->player->plane_y
		* game->ray->camera_x;
	game->ray->map_x = (int)(game->player->x / BLOCK);
	game->ray->map_y = (int)(game->player->y / BLOCK);
	calc_delta_dist(game->ray);
	calc_side_dist(game);
	perform_dda(game);
}
