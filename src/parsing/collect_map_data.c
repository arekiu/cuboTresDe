/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_small.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 19:19:09 by jslusark          #+#    #+#             */
/*   Updated: 2025/03/28 19:20:31 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


char	*ft_get_line(int fd)
{
	static char		buff[42];
	char			line[70000];
	static int		buff_read;
	static int		buff_pos;
	int				i;

	i = 0;
	// <-------------- FD SHOULD BE < 0 AND NOT <= 0
	if (fd < 0 || 42 <= 0)
		return (NULL);
	while (1)
	{
		if (buff_pos >= buff_read)
		{
			buff_read = read(fd, buff, 42);
			buff_pos = 0;
			if (buff_read <= 0)
				break ;
		}
		if (buff[buff_pos] == '\n')
		{
			// <------ THIS WAS I DID NOT ADD :(((
			line[i++] = buff[buff_pos++];
			break ;
		}
		line[i] = buff[buff_pos++];
		i++;
		// if (i >= 1023) // avoid overflow
		// {
		// should i add a limit and also trigger an error if the line is too long?
		// 	break;
		// }
	}
	if (i == 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

bool	collect_map_data(int fd, char ***map, t_game *game)
{
	char	*line;
	bool	err;
	int		i;
	int		line_n;

	i = 0;
	line_n = i;
	err = false;
	*map = malloc(sizeof(char *) * (1024 + 1));
	if (!*map)
	{
		// ensures free_map is safe
		game->data->map = NULL;
		printf("Error: malloc failed (map)\n");
		// VALGRIND: all leaks handled if malloc fails, but conditional jumps to free as not calloced every line
		return (false);
	}
	// get next line returns the full line until /n
	while (1)
	{
		// make sure getline is freed accordingly
		line = ft_get_line(fd);
		// null check before processing the line after
		if (line == NULL)
		{
			// if no lines were read
			if (i == 0)
				return (false);
			// else break the loop as no lines left to read
			break ;
		}
		// check if the line is part of the map or other data
		// takes texture  and rgb data
		if (texture_data(line, game, &line_n, &err))
		{
			// if texture_data finds an error is overwrites line as null to trigger the error
			if (err)
			{
				printf("YOOOO\n");
				err = false;
				free(line);
				return (false);
			}
			line_n++;
			free(line);
		}
		else
		{
			// printf("is_map: %s\n", line);
			(*map)[i] = ft_strdup(line);
			free(line);
			// if (!(*map)[i])
			// {
			// 	while (--i >= 0)
			// 		free((*map)[i]); // Free only the strings you allocated
			// 	free(*map);         // Free the container
			// 	game->data->map = NULL; // So that free_map() does nothing
			// }
			i++;
			line_n++;
		}
	}
	// add null terminator to the end of the map
	(*map)[i] = NULL;
	return (true);
}
