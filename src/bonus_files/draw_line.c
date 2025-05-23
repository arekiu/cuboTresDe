/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:11:55 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/23 14:17:36 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_line_data(t_game *game, t_line *line)
{
	int			square_size;

	square_size = set_square_size(game->data->map);
	line->x0 = MINIMAP_OFFSET_X + (int)(game->player->x / BLOCK * square_size);
	line->y0 = MINIMAP_OFFSET_Y + (int)(game->player->y / BLOCK * square_size);
	line->x1 = line->x0 + cos(game->player->angle) * 20;
	line->y1 = line->y0 + sin(game->player->angle) * 20;
	line->dx = abs(line->x1 - line->x0);
	line->dy = abs(line->y1 - line->y0);
	line->sx = 1;
	if (line->x0 > line->x1)
		line->sx = -1;
	line->sy = 1;
	if (line->y0 > line->y1)
		line->sy = -1;
	line->err = line->dx - line->dy;
}

void	step_line(t_line *line)
{
	int	e2;

	e2 = 2 * line->err;
	if (e2 > -line->dy)
	{
		line->err -= line->dy;
		line->x0 += line->sx;
	}
	if (e2 < line->dx)
	{
		line->err += line->dx;
		line->y0 += line->sy;
	}
}

void	draw_line(t_game *game)
{
	t_line	line;
	int		color;

	color = 0xFFFF00;
	init_line_data(game, &line);
	while (line.x0 != line.x1 || line.y0 != line.y1)
	{
		put_pixel(line.x0, line.y0, color, game);
		step_line(&line);
	}
}
