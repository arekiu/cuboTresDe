/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:10:03 by jslusark          #+#    #+#             */
/*   Updated: 2025/03/31 16:38:14 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// bool is_map()
// {

// }

//jump the coord
char	*store_texture(int *i, char *line, char *path)
{
	int	len;

	*i = *i + 2;
	// printf("c: %c\n", line[*i]);
	//skip spaces
	while (line[*i] == ' ' && line[*i] 
		!= '\0' && line[*i] 
		!= '\n' )
		(*i)++;
	// if line is \0 rrepeated check here
	// printf("c: %c\n len path: ", line[*i]);
	len = 0;
	while (line[*i + len] 
		!= '\0' && line[*i + len] 
		!= '\n' && line[*i + len] != ' ')
	{
		// printf("%c\n", line[*i + len]);
		len++;
	}
	// printf("len: %d | line: %s\n", len, line);
	path = malloc(sizeof(char) * (len + 1));
	if (!path || len == 0)
	{
		// printf("error\n");
		return (NULL);
	}
	// fixes issue of saving \n (could use strncpy instead)
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

	if (collect_coordinates(line, i, game) || collect_rgb(line, i, game)) // returns true if at least one of them is true
		return (true);
	return (false); // if both are false returns false
}

bool	check_start_map(int *i, char *line, bool *map_started)
{
	*i = 0;
	while (line[*i] == ' ')
		(*i)++;

	if (line[*i] == '\n' || line[*i] == '\0')
	{
		if (!*map_started)
			return (true); // skip line
		else
			return (false); // empty line after map started → invalid
	}
	if (line[*i] == '1' || line[*i] == '0' || line[*i] == ' ' || line[*i] == '\n')
		*map_started = true;
	return (false);
}


bool	process_line(char *line, t_game *game, int *line_n, int *j)
{
	int	i;
	i = 0;
	(void)line_n;

	if (check_start_map(&i, line, &game->data->map_started))
		return (true);
	if (!is_texture(line, &i, game) && !game->data->map_started)
		return false;
	if (game->data->map_started) // unsure if i should add also tabs 
		assign_to_map(line, &game->data->map, j, line_n);
	return (true);
}
