/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:11:38 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/23 15:40:57 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	set_square_size(char **map)
{
	int	square_size;

	square_size = MINI_BLOCK;
	if (get_map_width(map) > 30)
		square_size = MINI_BLOCK / 2;
	return (square_size);
}

void	draw_square(t_square sq, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < sq.size)
	{
		j = 0;
		while (j < sq.size)
		{
			put_pixel(sq.x + i, sq.y + j, sq.color, game);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < sq.size)
	{
		put_pixel(sq.x + i, sq.y, sq.color, game);
		put_pixel(sq.x + i, sq.y + sq.size - 1, sq.color, game);
		put_pixel(sq.x, sq.y + i, sq.color, game);
		put_pixel(sq.x + sq.size - 1, sq.y + i, sq.color, game);
		i++;
	}
}

void	draw_player(t_game *game, int square_size)
{
	int			px;
	int			py;
	t_square	sq;

	py = MINIMAP_OFFSET_Y + (int)(game->player->y / BLOCK * square_size);
	px = MINIMAP_OFFSET_X + (int)(game->player->x / BLOCK * square_size);
	sq.x = px - 2;
	sq.y = py - 2;
	sq.size = PLAYER_SIZE;
	sq.color = 0x0000FF;
	draw_square(sq, game);
	draw_line(game);
}

void	draw_minimap(t_game *game)
{
	int			x;
	int			y;
	t_square	sq;
	int			square_size;

	y = 0;
	square_size = set_square_size(game->data->map);
	while (game->data->map[y])
	{
		x = 0;
		while (game->data->map[y][x] && game->data->map[y][x] != '\n')
		{
			sq.x = MINIMAP_OFFSET_X + x * square_size;
			sq.y = MINIMAP_OFFSET_Y + y * square_size;
			sq.size = square_size;
			if (game->data->map[y][x] == '1')
				sq.color = 0xFFFFFF;
			else
				sq.color = 0x000000;
			draw_square(sq, game);
			x++;
		}
		y++;
	}
	draw_player(game, square_size);
}
