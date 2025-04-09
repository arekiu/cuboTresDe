/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:48:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/04/09 14:30:34 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../cub3d.h"
// int	has_required_text(char **map)
// {
// 	int	r;
// 	int	c;

// 	r = 0;
// 	while (map[r] != NULL)
// 	{
// 		c = 0;
// 		while (map[r][c] != '\0')
// 		{
// 			if (map[r][c] == '0' || map[r][c] == '1' || map[r][c] == 'C' ||
// 				map[r][c] == 'E' || map[r][c] == 'P' || map[r][c] == 'K')
// 				c++;
// 			else
// 			{
// 				ft_printf("Error: text %c at r[%d]c[%d]\n", map[r][c], r, c);
// 				return (0);
// 			}
// 		}
// 		r++;
// 	}
// 	return (1);
// }

// static int	count_sprite(char **map, char c)
// {
// 	int	row;
// 	int	col;
// 	int	amount;

// 	amount = 0;
// 	row = 0;
// 	while (map[row] != NULL)
// 	{
// 		col = 0;
// 		while (map[row][col] != '\0')
// 		{
// 			if (map[row][col] == c)
// 				amount++;
// 			col++;
// 		}
// 		row++;
// 	}
// 	return (amount);
// }

// int	has_enough_sprites(char **map, t_map *map_data)
// {
// 	/*
// 	smallest map horizontal

// 	 11
// 	10N1
// 	 11

// 	smallest map vertical
// 	 1
// 	101
// 	1N1
// 	 1

// 	- 0 should be at least 1
// 	- 1 should be at least 6
// 	- NSEW should be at least 1 (and between these 4 letters)
// 	*/
// 	int	e;
// 	int	c;
// 	int	p;
// 	int	k;

// 	e = count_sprite(map, 'E');
// 	c = count_sprite(map, 'C');
// 	p = count_sprite(map, 'P');
// 	k = count_sprite(map, 'K');
// 	if (p == 0 || p > 1 || c == 0 || e == 0 || e > 1 || k == 0)
// 	{
// 		ft_printf("Error: Map does not have the required amount assets:\n");
// 		ft_printf("- C: %d (needs to be 1 or more) \n", c);
// 		ft_printf("- P: %d (needs to be 1) \n", p);
// 		ft_printf("- E: %d (needs to be 1) \n", e);
// 		ft_printf("- K: %d (needs to be 1 or more) \n", e);
// 		return (0);
// 	}
// 	map_data->loot_n = c;
// 	map_data->moves = 0;
// 	return (1);
// }

// int	is_framed(char **map, int last_r, int last_c)
// {
// 	int	r;
// 	int	c;

// 	r = 0;
// 	while (map[r] != NULL)
// 	{
// 		c = 0;
// 		while (map[r][c] != '\0')
// 		{
// 			if (r == 0 || r == last_r || c == 0 || c == last_c)
// 			{
// 				if (map[r][c] != '1')
// 				{
// 					ft_printf("Error: Not framed at map[%d][%d]\n", r, c);
// 					return (0);
// 				}
// 			}
// 			c++;
// 		}
// 		r++;
// 	}
// 	return (1);
// }