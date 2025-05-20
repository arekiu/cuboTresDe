/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:48:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/20 11:55:21 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


bool	has_required_text(char **map, t_player *player) // i need a diff function to colculate coords!!
{
	int	r;
	int	c;

	char *valid_chars = "01 NSEW"; // valid characters in the map - this gives me probke

	r = 0;
	while (map[r] != NULL)
	{
		c = 0;
		while (map[r][c] != '\0')
		{
            if (strchr(valid_chars, map[r][c]) != NULL) // check if the character is valid
            {
				if (strchr("NSEW", map[r][c]) != NULL) // if any of the chars are players we store them
				{
					player->orientation = map[r][c];
					player->y = r; // vertical poisition / line / row of the array
					player->x = c; // horizontal poisition / index / column of the array
					// does not need to be in the map
				}
            }
            else
            {
                printf("Error: Invalid character '%c' found in map at line[%d][%d]\n", map[r][c], r, c);
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

    int floor;
    int wall;
    int player;
    floor = count_sprite(map, '0');
    wall = count_sprite(map, '1');
    player = count_sprite(map, 'N') + count_sprite(map, 'S') + count_sprite(map, 'E') + count_sprite(map, 'W');
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