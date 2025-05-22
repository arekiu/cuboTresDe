/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:10:33 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/22 15:11:49 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ray_drawer(t_game *game)
{
	int				y;
	unsigned int	c_color;
	unsigned int	f_color;

	c_color = rgb_to_hex(game->data->C_rgb);
	f_color = rgb_to_hex(game->data->F_rgb);
	game->ray->line_height = (int)(WIN_HEIGHT / game->ray->wall_dist);
	game->ray->draw_start = -(game->ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = game->ray->line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray->draw_end >= WIN_HEIGHT)
		game->ray->draw_end = WIN_HEIGHT - 1;
	y = paint_line(game, game->ray->draw_start, 0, c_color);
	y = draw_texture(game);
	paint_line(game, WIN_HEIGHT, y, f_color);
}

t_texture	*get_wall_texture(t_game *game)
{
	if (game->ray->side == NORTH)
		return (game->no_text);
	else if (game->ray->side == SOUTH)
		return (game->so_text);
	else if (game->ray->side == EAST)
		return (game->ea_text);
	else
		return (game->we_text);
}

void	set_texture(t_game *game, t_texture *texture)
{
	t_ray	*ray;
	double	px;
	double	py;

	ray = game->ray;
	px = game->player->x / BLOCK;
	py = game->player->y / BLOCK;
	if (ray->side == EAST || ray->side == WEST)
		ray->wall_x = py + ray->wall_dist * ray->dir_y;
	else
		ray->wall_x = px + ray->wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->text_x = (int)(ray->wall_x * (double)texture->width);
	if ((ray->side == EAST && ray->dir_x > 0) || (ray->side == WEST && \
			ray->dir_x < 0))
		ray->text_x = texture->width - ray->text_x - 1;
	else if ((ray->side == NORTH && ray->dir_y < 0) || (ray->side == SOUTH \
			&& ray->dir_y > 0))
		ray->text_x = texture->width - ray->text_x - 1;
}

int	paint_line(t_game *game, int y_end, int y_start, int color)
{
	while (y_start <= y_end)
	{
		put_pixel(game->ray->current_x, y_start, color, game);
		y_start++;
	}
	return (y_start);
}

int	get_pixel(t_texture *texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0);
	pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	return (*(int *)pixel);
}
