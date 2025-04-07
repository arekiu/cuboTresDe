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


char *ft_get_line(int fd)
{
	static char	buff[42];
	char		line[70000];
	static int		buff_read;
	static int		buff_pos;
	int i = 0;

	if(fd < 0 || 42 <= 0) // <-------------- FD SHOULD BE < 0 AND NOT <= 0
		return(NULL);
	while(1)
	{
		if(buff_pos >= buff_read)
		{
			buff_read = read(fd, buff, 42);
			buff_pos = 0;
			if(buff_read <= 0)
				break;
		}
		if(buff[buff_pos] == '\n')
		{
			line[i++] = buff[buff_pos++]; // <------ THIS WAS I DID NOT ADD :(((
			break;
		}
		line[i] = buff[buff_pos++];
		i++;
	}
	if(i == 0)
		return(NULL);
	line[i] = '\0';
	return(ft_strdup(line));
}

bool	get_fd_data(int fd, char ***map, t_game *game)
{
	char *line;
	bool err = false;
	(void)game;
	int i = 0;
	int line_n = i;
	*map = malloc(sizeof(char *) * 1024 + 1);
	if (!*map) // and free?
		return (false);

	while(1) // get next line returns the full line until /n
	{
		line = ft_get_line(fd);
		if(line == NULL) // null check before processing the line after
		{
			if(i == 0) // if no lines were read
				return (false);
			break; // else break the loop as no lines left to read
		}
		// check if the line is part of the map or other data
		if(texture_data(line, game, &line_n, &err))
		{
			if(err)// if texture_data finds an error is overwrites line as null to trigger the error
			{
				err = false;
				free(line);
				return(false);
			}
			line_n++;
		}
		else
		{
			// printf("is_map: %s\n", line);
			(*map)[i] = ft_strdup(line);
			free(line);
			i++;
			line_n++;
		}
	}
	(*map)[i] = NULL; // add null terminator to the end of the map
	return(true);
}