/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:48:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 14:13:05 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void collect_character(char **map, int r, int c,  t_player *player)
{
	// stores 1 or more player and position in the map
	if (strchr("NSEW", map[r][c]) != NULL)
	{
		player->orientation = map[r][c];
		// vertical poisition / line / row of the array
		player->y = r;
		// vertical poisition / line / row of the array
		player->x = c;
		// does not need to be in the map
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
			if (strchr("01 NSEW", map[r][c]) != NULL)
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

/*
smallest map horizontal

 11
10N1
 11

smallest map vertical
 1
101
1N1
 1

- 0 should be at least 1
- 1 should be at least 6
- NSEW should be at least 1 (and between these 4 letters)
*/
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
	// printf("floor: %d, wall: %d, player: %d\n", floor, wall, player);

	// see if a tile amount for floor and wall is
	if (player == 0 || player > 1 || floor < 0 || wall < 0)
	{
		ft_printf("Error: Map does not have the required amount assets:\n");
		ft_printf("player: %d (needs to be 1 between N, S, E, W) \n", player);
		ft_printf("walls: %d (cannot be 0) \n", wall);
		ft_printf("floor: %d (cannot be 0) \n", floor);
		return (false);
	}
	// map_data->loot_n = c; // useful for bonus
	// map_data->moves = 0; // we don't need this i think
	return (true);
}
