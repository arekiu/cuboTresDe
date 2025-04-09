/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:31:06 by jslusark          #+#    #+#             */
/*   Updated: 2025/04/09 15:43:10 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// bool check_top(char **map, int i)
// {
// 	if(i > 0) // if we are on the 2nd line
// 	{
// 		// check up down left right
// 		if

// 	}
// }


// int count_map_lines(char **map)
// {
// 	int count = 0;

// 	if (!map)
// 		return (0);

// 	while (map[count])
// 		count++;

// 	return (count);
// }
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

// bool space_contained(char *line, int pos, int last_r, int last_c) // should i do the same with 0?
// {
// 	(void)last_r;
// 	int i = 0;
// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == ' ') // space cannot touch 0 or NEWS
// 		{
// 			// if(pos != 0) // check up
// 			// {
// 			// 	if(line[i - 1] == '0' || line[i - 1] == 'N' || line[i - 1] == 'S' || line[i - 1] == 'W' || line[i - 1] == 'E')
// 			// 	{
// 			// 		printf("Error: space at line[%d] col[%d] touches invalid character\n", pos, i);
// 			// 		return (false);
// 			// 	}
// 			// }
// 			// if(pos != last_r) // Check dowm
// 			// {
// 			// 	if (line[i + 1] == '0' || line[i + 1] == 'N' || line[i + 1] == 'S' || line[i + 1] == 'W' || line[i + 1] == 'E')
// 			// 	{
// 			// 		printf("Error: space at line[%d] col[%d] touches invalid character\n", pos, i);
// 			// 		return (false);
// 			// 	}
// 			// }
// 			if(i != 0) // we check left
// 			{
// 				if (line[i - 1] == '0' || line[i - 1] == 'N' || line[i - 1] == 'S' || line[i - 1] == 'W' || line[i - 1] == 'E')
// 				{
// 					printf("Error: space at line[%d] col[%d] touches invalid character(%c) on the left\n", pos, i, line[i - 1]);
// 					return (false);
// 				}
// 			}
// 			if(i != last_c) // we check right
// 			{
// 				if( line[i + 1] == '0' || line[i + 1] == 'N' || line[i + 1] == 'S' || line[i + 1] == 'W' || line[i + 1] == 'E')
// 				{
// 					printf("Error: space at line[%d] col[%d] touches invalid character(%c) on the right\n", pos, i, line[i + 1]);
// 					return (false);
// 				}
// 			}
// 		}
// 		i++;
// 	}
// 	return (true); // edges are valis
// }
bool is_framed(char **map, int last_r, int last_c)
{
	(void)map;
	printf("Map has %d lines and each line has %d characters\n", last_r+1, last_c+1);

	int	r;
	// int c;
	// bool has_top; // map[0] has no top line to compare, map[1] until map[len] yes
	// bool has_bottom; // map[len] has no bottom line to compare, map[0] until map[len - 1] yes


	// // first line can never have 0,N,S,W,E
	// // last line can never have a 0,N,S,W,E
	// // first c can naver start with 0
	// // last c can naver start with 0


	// // check spaces
	// // check floor

	r = 0;
	while (map[r] != NULL) // we check every line
	{
		// c = 0;
		// for every line we check if there are characters that should not be out of the walls
		// in valid_edges we check if this happens in the first and last line and on the side of the lines
		// the check is only done thorugh the x axis, and y axis only for the first and last line since I will use spaces to determine the rest
		if(!valid_edges(map[r], r, last_r, last_c))
			return (false);
		// in space_contained we check if the spaces are not touching 0,N,S,W,E, outside and inside the walls, on every axis
		// if(!space_contained(map[r], r, last_r, last_c))
		// 	return (false);
		r++;
	}
	return (true);
}