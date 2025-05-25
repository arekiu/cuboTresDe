/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_map_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birdieber <birdieber@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:55:29 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/25 17:31:47 by birdieber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*store_texture(int *i, char *line, char *path)
{
	int	len;

	*i = *i + 2;
	while (line[*i] == ' ' && line[*i]
		!= '\0' && line[*i]
		!= '\n' )
		(*i)++;
	len = 0;
	while (line[*i + len]
		!= '\0' && line[*i + len]
		!= '\n' && line[*i + len] != ' ')
		len++;
	path = malloc(sizeof(char) * (len + 1));
	if (!path || len == 0)
		return (NULL);
	ft_strlcpy(path, line + *i, len + 1);
	return (path);
}

bool	match_texture(char *id, int *counter, int *i, char *line)
{
	if (ft_strncmp(id, &line[*i], ft_strlen(id)) == 0)
	{
		(*counter)++;
		return (true);
	}
	return (false);
}

bool	is_texture(char *line, int *i, t_game *game)
{
	if (collect_coordinates(line, i, game) || collect_rgb(line, i, game))
		return (true);
	return (false);
}

bool	check_start_map(int *i, char *line, bool *map_started)
{
	*i = 0;
	while (line[*i] == ' ')
		(*i)++;
	if (line[*i] == '\n' || line[*i] == '\0')
	{
		if (!*map_started)
			return (true);
		else
			return (false);
	}
	if (line[*i] == '1'
		|| line[*i] == '0'
		|| line[*i] == ' '
		|| line[*i] == '\n')
		*map_started = true;
	return (false);
}

bool	process_line(char *line, t_game *game, int *array_i)
{
	int	i;

	i = 0;
	if (check_start_map(&i, line, &game->data->map_started))
		return (true);
	if (!is_texture(line, &i, game) && !game->data->map_started)
	{
		printf("Error: Invalid format at line[%d]:%s", *array_i, line);
		free(line);
		return (false);
	}
	if (game->data->map_started)
		assign_to_map(line, &game->data->map, array_i);
	return (true);
}
