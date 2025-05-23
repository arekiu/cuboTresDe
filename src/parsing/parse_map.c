/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:12:20 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 18:03:55 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_map_lines(char **map)
{
	int	count;

	count = 0;
	if (!map)
		return (0);
	while (map[count])
		count++;
	return (count);
}

void	fill_line(int len, int longest_len, char *new_line)
{
	int		j;

	j = len;
	while (j < longest_len)
	{
		new_line[j] = ' ';
		j++;
	}
	new_line[longest_len] = '\0';
}

void	expand_line_len(t_data *data, int longest_len)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	while (data->map[i])
	{
		len = ft_strlen(data->map[i]);
		if (len < longest_len)
		{
			new_line = malloc(sizeof(char) * (longest_len + 1));
			if (!new_line)
			{
				ft_printf("Error: malloc failed on map line expansion %d\n", i);
				return ;
			}
			ft_memcpy(new_line, data->map[i], len);
			fill_line(len, longest_len, new_line);
			free(data->map[i]);
			data->map[i] = new_line;
		}
		i++;
	}
}

int	find_longest_line(t_data *data)
{
	int	i;
	int	longest_len;
	int	line_len;

	i = 0;
	longest_len = 0;
	while (data->map[i])
	{
		line_len = ft_strlen(data->map[i]);
		if (line_len > longest_len)
		{
			longest_len = line_len;
		}
		i++;
	}
	return (longest_len);
}

void	remove_nl(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '\n')
			{
				data->map[y][x] = '\0';
				break ;
			}
			x++;
		}
		y++;
	}
}

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
