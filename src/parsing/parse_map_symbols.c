/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:48:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 18:01:14 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	collect_character(char **map, int r, int c, t_player *player)
{
	if (ft_strchr("NSEW", map[r][c]) != NULL)
	{
		player->orientation = map[r][c];
		player->y = r;
		player->x = c;
	}
}

bool	has_required_text(char **map, t_player *player)
{
	int		r;
	int		c;

	r = 0;
	while (map[r] != NULL)
	{
		c = 0;
		while (map[r][c] != '\0')
		{
			if (ft_strchr("01 NSEW", map[r][c]) != NULL)
				collect_character(map, r, c, player);
			else
			{
				printf("Error: Invalid character '%c' found in map[%d][%d]\n",
					map[r][c], r, c);
				return (false);
			}
			c++;
		}
		r++;
	}
	return (true);
}

int	count_sprite(char **map, char c)
{
	int	row;
	int	col;
	int	amount;

	amount = 0;
	row = 0;
	while (map[row] != NULL)
	{
		col = 0;
		while (map[row][col] != '\0')
		{
			if (map[row][col] == c)
				amount++;
			col++;
		}
		row++;
	}
	return (amount);
}

bool	has_enough_sprites(char **map)
{
	int	floor;
	int	wall;
	int	player;

	floor = count_sprite(map, '0');
	wall = count_sprite(map, '1');
	player = count_sprite(map, 'N')
		+ count_sprite(map, 'S')
		+ count_sprite(map, 'E')
		+ count_sprite(map, 'W');
	if (player == 0 || player > 1 || floor < 0 || wall < 0)
	{
		ft_printf("Error: Map does not have the required amount assets:\n");
		ft_printf("player: %d (needs to be 1 between N, S, E, W) \n", player);
		ft_printf("walls: %d (cannot be 0) \n", wall);
		ft_printf("floor: %d (cannot be 0) \n", floor);
		return (false);
	}
	return (true);
}
