/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:31:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 18:03:18 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	is_valid_edge_char(char *line, int r, int c)
{
	if (ft_strchr("0NSEW", line[c]))
	{
		printf("Error: incorrect map framing on line[%d][%d]:'%c'\n",
			r, c, line[c]);
		return (false);
	}
	return (true);
}

bool	valid_top_bottom(char **map, int line_index, int i, int last_r)
{
	int	bottom;
	int	top;

	bottom = line_index + 1;
	top = line_index - 1;
	if (line_index != 0) 
	{
		if (!is_valid_edge_char(map[top], top, i))
			return (false);
	}
	if (line_index != last_r)
	{
		if (!is_valid_edge_char(map[bottom], bottom, i))
			return (false);
	}
	return (true);
}

bool	valid_sides(char *line, int line_index, int i, int last_c)
{
	if (i != 0)
	{
		if (!is_valid_edge_char(line, line_index, i - 1))
			return (false);
	}
	if (i != last_c)
	{
		if (!is_valid_edge_char(line, line_index, i + 1))
			return (false);
	}
	return (true);
}

bool	valid_edges(char *line, int r, int last_r, int last_c)
{
	int	i;
	int	end;

	i = 0;
	end = last_c;
	if (r == 0 || r == last_r)
	{
		while (line[i] != '\0')
		{
			if (!is_valid_edge_char(line, r, i))
				return (false);
			i++;
		}
	}
	else
	{
		while (line[i] != '\0' && line[i] == ' ') // skip line
			i++;
		if (!is_valid_edge_char(line, r, i))
			return (false);
		while (end > 0 && line[end] == ' ')
			end--;
		if (!is_valid_edge_char(line, r, end))
			return (false);
	}
	return (true);
}

bool	space_contained(char **map, char *line, int line_index, int last_r)
{
	int	last_c;
	int	bottom;
	int	top;
	int	i;

	last_c = ft_strlen(line) - 1;
	bottom = line_index + 1;
	top = line_index - 1;
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
