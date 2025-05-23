/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:12:55 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/23 15:35:27 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->stride + x * game->bpp / 8;
	game->buffer[index] = color & 0xFF;
	game->buffer[index + 1] = (color >> 8) & 0xFF;
	game->buffer[index + 2] = (color >> 16) & 0xFF;
}

unsigned int	rgb_to_hex(int rgb[3])
{
	return (rgb[0] * 65536 + rgb[1] * 256 + rgb[2]);
}

void	clear(t_game *game)
{
	ft_memset(game->buffer, 0, WIN_WIDTH * WIN_HEIGHT * (game->bpp / 8));
}

double	get_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000.0) + (time.tv_usec / 1000.0));
}

int	get_map_width(char **map)
{
	int	max_width;
	int	i;
	int	len;

	max_width = 0;
	i = 0;
	while (map[i] != NULL)
	{
		len = ft_strlen(map[i]);
		if (len > max_width)
			max_width = len;
		i++;
	}
	return (max_width);
}
