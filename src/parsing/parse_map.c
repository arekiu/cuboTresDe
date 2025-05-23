/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:12:20 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 18:21:27 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	found_empty_line(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] == ' ')
			x++;
		if (data->map[y][x] == '\0')
		{
			printf("Error: found a new line inside map at line[%d]\n", y);
			return (true);
		}
		y++;
	}
	return (false);
}

bool	parse_map(t_data *data, t_player *player)
{
	int	longest_len;
	int	total_lines;

	remove_nl(data);
	longest_len = find_longest_line(data);
	total_lines = count_map_lines(data->map);
	expand_line_len(data, longest_len);
	if (found_empty_line(data)
		|| !is_shaped(data->map, total_lines - 1, longest_len -1)
		|| !has_required_text(data->map, player)
		|| !has_enough_sprites(data->map))
		return (false);
	return (true);
}
