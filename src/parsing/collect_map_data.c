/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:52:46 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/21 15:24:52 by jslusark         ###   ########.fr       */
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

static void assign_to_map(char *line, char ***map, int *i, int *line_n)
{
	(*map)[*i] = ft_strdup(line);
	free(line);
	(*i)++;
	(*line_n)++;
}

static bool	assign_to_texture(char *line, int *line_n, bool *unrecognoised_line)
{
	if (*unrecognoised_line)
	{
		printf("ERR TRUE with line_n[%d]:'%s'\n", *line_n,line );
		*unrecognoised_line = false;
		printf("ERR FALSE");
		free(line);
		return (false);
	}
	(*line_n)++;
	free(line);
	return (true);
}

bool	collect_map_data(int fd, char ***map, t_game *game)
{
	char	*line;
	bool	unrecognoised_line;
	int		i;
	int		line_n;

	i = 0;
	line_n = i;
	unrecognoised_line = false;
	if (!allocate_map(map, game))
		return (false);
	while (1)
	{
		line = ft_get_line(fd);
		if (line == NULL)
		{
			if (i == 0)
				return (false);
			break ;
		}
		// if (!assign_to_texture(line, game, &line_n, &unrecognoised_line))
		// 	return (false);
		if (texture_is_found(line, game, &line_n, &unrecognoised_line))
		{
			if (!assign_to_texture(line, &line_n, &unrecognoised_line))
				return (false);
				// return (true);
		}
		else
			assign_to_map(line, map, &i, &line_n);
		// else
		// {
		// 	(*map)[i] = ft_strdup(line);
		// 	free(line);
		// 	i++;
		// 	line_n++;
		// }
	}
	(*map)[i] = NULL;
	return (true);
}
