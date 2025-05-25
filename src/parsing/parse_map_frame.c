/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birdieber <birdieber@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:31:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/25 17:34:15 by birdieber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	space_contained(char **map, char *line, int line_index, int last_r)
{
	int	last_c;
	int	i;

	last_c = ft_strlen(line) - 1;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
		{
			if (!valid_top_bottom(map, line_index, i, last_r))
				return (false);
			if (!valid_sides (line, line_index, i, last_c))
				return (false);
		}
		i++;
	}
	return (true);
}

bool	is_shaped(char **map, int last_r, int last_c)
{
	int	r;

	r = 0;
	while (map[r] != NULL)
	{
		if (!valid_edges(map[r], r, last_r, last_c)
			|| !space_contained(map, map[r], r, last_r))
			return (false);
		r++;
	}
	return (true);
}
