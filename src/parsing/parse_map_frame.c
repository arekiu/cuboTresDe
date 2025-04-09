/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:31:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/04/09 16:44:52 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool valid_edges(char *line, int r, int last_r, int last_c) // checks each line withou affecting main loop
{
	// 0,N,S,W,E should not be on line[0] and line[last_r] as it means the map is not framed
	// 0,N,S,W,E should also not be the first character we catch from the left and right of the line
	int i = 0;
	int end = last_c;
	if (r == 0 || r == last_r) // top-bottom edges
	{
		while (line[i] != '\0')
		{
			if (line[i] == '0' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
			{
				printf("Error: map not enclosed, found %c at line[%d]\n", line[i], r);
				return (false);
			}
			i++;
		}
	}
	else // side edges
	{
		// we check left by looping from  the start
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		if(line[i] == '0' || line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
		{
			printf("Error: map not enclosed on left side on line[%d], found %c index %d\n", r, line[i], i);
			return (false);
		}
		//we check right by looping from the end
		while (end > 0 && line[end] == ' ')
			end--;
		if(line[end] == '0' || line[end] == 'N' || line[end] == 'S' || line[end] == 'W' || line[end] == 'E')
		{
			printf("Error: map not enclosed on right side on line[%d], found %c index %d\n", r, line[end], end);
			return (false);
		}
	}
	return (true); // edges are valis
}

bool space_contained(char **map, char *line, int line_index, int last_r) // should i do the same with 0?
{
	int last_c = ft_strlen(line) - 1;
	int top = line_index - 1;
	int bottom = line_index + 1;
	int i = 0;
	// printf(RED_T"Space check\n"RESET_T);
	// printf("line[%d]:%s\n", top, map[top]);
	// printf("line[%d]:%s\n", line_index, line);
	// printf("line[%d]:%s\n", bottom, map[bottom]);
	while (line[i] != '\0') // go through the line
	{
		if (line[i] == ' ') // we check that ' ' is not surrounded by 0NSEW top,left,right, bottom
		{
			if(line_index != 0) // check top of i
			{
				if(map[top][i] == '0' || map[top][i] == 'N' || map[top][i] == 'S' || map[top][i] == 'W' || map[top][i] == 'E')
				{
					printf("Error: space at line[%d][%d]:'%c' touches line[%d][%d]:'%c' at top\n", line_index, i, line[i], top, i, map[top][i]);
					return (false);
				}
			}
			if(line_index != last_r) // Check dowm
			{
				if(map[bottom][i] == '0' || map[bottom][i] == 'N' || map[bottom][i] == 'S' || map[bottom][i] == 'W' || map[bottom][i] == 'E')
				{
					printf("Error: space at line[%d][%d]:'%c' touches line[%d][%d]:'%c' at bottom\n", line_index, i, line[i], bottom, i, map[bottom][i]);
					return (false);
				}
			}
			if(i != 0) // we check left
			{
				if (line[i - 1] == '0' || line[i - 1] == 'N' || line[i - 1] == 'S' || line[i - 1] == 'W' || line[i - 1] == 'E')
				{
					printf("Error: space at line[%d] col[%d] touches invalid character(%c) on the left\n", line_index, i, line[i - 1]);
					return (false);
				}
			}
			if(i != last_c) // we check right
			{
				if( line[i + 1] == '0' || line[i + 1] == 'N' || line[i + 1] == 'S' || line[i + 1] == 'W' || line[i + 1] == 'E')
				{
					printf("Error: space at line[%d] col[%d] touches invalid character(%c) on the right\n", line_index, i, line[i + 1]);
					return (false);
				}
			}
		}
		i++; // check next character
	}
	return (true); // edges are valis
}

bool is_shaped(char **map, int last_r, int last_c)
{
	// printf("Map has %d lines and each line has %d characters\n", last_r+1, last_c+1);
	int	r;
	r = 0;
	(void)last_c;
	while (map[r] != NULL) // we check every line
	{
		// for every line we check if there are characters that should not be out of the walls
		// in valid_edges we check if this happens in the first and last line and on the side of the lines
		// the check is only done thorugh the x axis, and y axis only for the first and last line since I will use spaces to determine the rest
		if(!valid_edges(map[r], r, last_r, last_c))
			return (false);
		// in space_contained we check if the spaces are not touching 0,N,S,W,E, outside and inside the walls, on every axis
		if(!space_contained(map, map[r], r, last_r))
			return (false);
		r++;
	}
	return (true);
}