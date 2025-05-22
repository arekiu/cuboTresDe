/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_drawer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:12:32 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/06 13:44:56 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	draw_texture(t_game *game)
{
	t_texture	*texture;
	double		step;
	double		tex_pos;

	prep_text_drawing(game, &texture, &step, &tex_pos);
	return (render_text_line(game, texture, step, tex_pos));
}

int	render_text_line(t_game *game, t_texture *text, double step, double tex_pos)
{
	t_ray	*ray;
	int		y;
	int		color;
	int		tex_y;

	ray = game->ray;
	y = ray->draw_start;
	if (y < 0)
		y = 0;
	while (y < ray->draw_end && y < WIN_HEIGHT)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= text->height)
			tex_y = text->height - 1;
		color = get_pixel(text, ray->text_x, tex_y);
		put_pixel(ray->current_x, y, color, game);
		tex_pos += step;
		y++;
	}
	return (y);
}

void	prep_text_drawing(t_game *game, t_texture **text, double *step, \
	double *tex_pos)
{
	t_ray	*ray;

	ray = game->ray;
	*text = get_wall_texture(game);
	set_texture(game, *text);
	*step = 1.0 * (*text)->height / ray->line_height;
	*tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) \
		* (*step);
	if (ray->draw_start < 0)
		*tex_pos += (*step) * -ray->draw_start;
}
