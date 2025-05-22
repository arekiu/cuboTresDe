/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:52:46 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/22 13:28:33 by jslusark         ###   ########.fr       */
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

void assign_to_map(char *line, char ***map, int *i, int *line_n)
{
	(void)line_n;
	(*map)[*i] = ft_strdup(line);
	(*i)++;
}

bool	collect_map_data(int fd, char ***map, t_game *game)
{
	char	*line;
	int		i;
	int		line_n;

	i = 0;
	line_n = i;
	if (!allocate_map(map, game))
		return (false);
	while (1)
	{
		line = ft_get_line(fd);
		if (line == NULL)
			break ;
		if (!process_line(line, game, &line_n, &i))
		{
			printf("Error: Invalid format at line[%d]:%s", line_n, line);
			free(line);
			return (false); 
		}
		free(line);
		line_n++;
	}
	if (i == 0)
	{
		free(line);	
		return (false);
	}
	(*map)[i] = NULL;
	return (true);
}
