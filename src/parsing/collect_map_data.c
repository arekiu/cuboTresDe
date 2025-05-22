/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:52:46 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/22 14:59:43 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	allocate_map(char ***map, t_game *game)
{
	*map = malloc(sizeof(char *) * (1024 + 1));
	if (!*map)
	{
		game->data->map = NULL;
		printf("Error: malloc failed (map)\n");
		return (false);
	}
	return (true);
}

void	assign_to_map(char *line, char ***map, int *array_i)
{
	(*map)[*array_i] = ft_strdup(line);
	(*array_i)++;
}

bool	collect_map_data(int fd, char ***map, t_game *game)
{
	char	*line;
	int		array_i;
	int		file_i;

	array_i = 0;
	file_i = array_i;
	if (!allocate_map(map, game))
		return (false);
	while (1)
	{
		line = ft_get_line(fd);
		if (line == NULL)
			break ;
		if (!process_line(line, game, &array_i))
		{
			printf("Error: Invalid format at line[%d]:%s", file_i, line);
			free(line);
			return (false); 
		}
		free(line);
		file_i++;
	}
	if (array_i == 0)
	{
		free(line);	
		return (false);
	}
	(*map)[array_i] = NULL;
	return (true);
}
