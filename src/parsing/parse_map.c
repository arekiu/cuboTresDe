/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:12:20 by jslusark          #+#    #+#             */
/*   Updated: 2025/04/08 13:06:11 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void expand_map_lines(t_data *data, int longest_len)
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
    int line_n = 0;

    while (data->map[i])
    {
        line_len = ft_strlen(data->map[i]);
        if (line_len > longest_len)
        {    
            longest_len = line_len;
            line_n = i;
        }
        i++;
    }
    printf("Line[%d] has the longest len of %d \nLine:'%s'\n", line_n, longest_len, data->map[line_n]);
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

bool found_empty_line(t_data *data) // as remove_nl and expand_map_lines fille the nl only line with space we check if there are lines only 
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

bool parse_map(t_data *data)
{
    (void)data;
    remove_nl(data);
    int longest_len = find_longest_line(data);
    expand_map_lines(data, longest_len);
    if(found_empty_line(data))
    {
        printf("Error: map is not closed\n");
        return(false);
    }
    (void)longest_len;
    return(true);
}
