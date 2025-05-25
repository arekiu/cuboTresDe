/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_frame_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birdieber <birdieber@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 18:13:43 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/25 17:30:17 by birdieber        ###   ########.fr       */
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

void	skip_spaces(char *line, int *i)
{
	while (line[(*i)] != '\0' && line[(*i)] == ' ')
		(*i)++;
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
		skip_spaces(line, &i);
		if (!is_valid_edge_char(line, r, i))
			return (false);
		while (end > 0 && line[end] == ' ')
			end--;
		if (!is_valid_edge_char(line, r, end))
			return (false);
	}
	return (true);
}
