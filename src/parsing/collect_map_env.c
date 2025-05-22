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

bool	texture_is_found(char *line, t_game *game, int *line_n, bool *unrecognised_line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		//while is spaces skip
		while (line[i] == ' ')
			i++;
		// if only spaces found until end
		if (line[i] == '\n' || line[i] == '\0' )
		{
			// and if map hasn't started yet skip the lines
			if (!game->data->map_started)
				return (true); //skip the lines
			else 
				return (false);
			// if map started we have to include in the map
		}
		if (is_texture(line, &i, game))
			return (true);
		//check if its a map
		if (line[i] == '1' 
			|| line[i] == '0' 
			|| line[i] == ' ' 
			|| line[i] == '\n')
		{
			game->data->map_started = true; // flag to avoid skipping spac
			return (false);
			// false -> should be saved in map
		}
		else
		{
			*unrecognised_line = true;
			printf("Error: invalid line format at line index %d\n", *line_n);
			return (true); 
		}
		i++;
	}
	return (false);
}
