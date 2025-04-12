/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:12:20 by jslusark          #+#    #+#             */
/*   Updated: 2025/04/11 20:07:58 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int count_map_lines(char **map)
{
	int count = 0;

	if (!map)
		return (0);

	while (map[count])
		count++;

	return (count);
}

void expand_line_len(t_data *data, int longest_len)
{
	int i = 0;
	while (data->map[i])
	{
		int len = ft_strlen(data->map[i]);
		if (len < longest_len)
		{
			char *new_line = malloc(sizeof(char) * (longest_len + 1));
			if (!new_line)
			{
				ft_printf("Error: malloc failed when expanding map line %d\n", i);
				return;
			}
			ft_memcpy(new_line, data->map[i], len); // copies and allocated the string
			// Fill the rest with ' '
			for (int j = len; j < longest_len; j++) // change with while loop later
				new_line[j] = ' ';
			new_line[longest_len] = '\0';

			free(data->map[i]);
			data->map[i] = new_line;
		}
		i++;
	}
}


int find_longest_line(t_data *data)
{
    int i = 0;
    int line_len;
    int longest_len = 0;

    while (data->map[i])
    {
        line_len = ft_strlen(data->map[i]);
        if (line_len > longest_len)
        {
            longest_len = line_len;
        }
        i++;
    }
    // printf("Line[%d] has the longest len of %d \nLine:'%s'\n", line_n, longest_len, data->map[line_n]);
    return(longest_len);
}
// Copy the original content
void remove_nl(t_data *data) // better check this
{
	int x;
    int y = 0;

	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '\n')
			{
				data->map[y][x] = '\0'; // Replace newline with string terminator
				break; // Done with this line
			}
			x++;
		}
		y++;
	}
}

bool found_empty_line(t_data *data) // as remove_nl and expand_line_len fille the nl only line with space we check if there are lines only
{
    int x;
    int y = 0;

	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] == ' ')
			x++;
        if(data->map[y][x] == '\0')
        {
            printf("Error: found a new line inside map at line[%d]\n", y);
            return(true);
        }
		y++;
	}
    return(false);
}


bool parse_map(t_data *data, t_player *player)
{
	(void)data;
	remove_nl(data);
	int longest_len = find_longest_line(data);
	int total_lines = count_map_lines(data->map);
	// printf("Map has %d lines and each line is %d characters\n", total_lines, longest_len);
	expand_line_len(data, longest_len);
	// do i add null as last line of the array in gnl?
	if(found_empty_line(data) || !is_shaped(data->map, total_lines - 1, longest_len -1) ||
	   !has_required_text(data->map, player) || !has_enough_sprites(data->map))
		return(false);
	// error if there is space inside the map (can be checked with flood fill once we know the position of the player)
	// - check if character is blocked?
	return(true);
}
