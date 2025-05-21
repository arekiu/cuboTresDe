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


// returns -1 if not valid key
int	store_value(const char *nptr)
{
	int		num;
	size_t	i;

	num = 0;
	i = 0;
	// printf("nptr: '%s'\n", nptr);
	if (!ft_isdigit(nptr[i]))
		return (-2);
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		// to avoid overflow
		if (num > INT_MAX || num < INT_MIN)
			return (-2);
		i++;
	}
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		(i)++;
	if (nptr[i] != '\0')
		return (-2);
	return (num);
}

int	*store_rgb( int *i, char *line)
{
	int		*rgb;
	char	*value;
	int		indexes;
	int		len;

	rgb = malloc(sizeof(int) * 3);
	value = NULL;
	// printf("LINE: %s", line); // C 120,0,16
	indexes = 0;
	// jump the C or F
	(*i)++;
	if (!rgb)
		return (false);
	// loop thorugh the line until is over
	while (line[*i] != 0 && line[*i] != '\n')
	{
		// resets for next value
		len = 0;
		if (indexes > 2)
		{
			free(rgb);	
			return (NULL);
		}
		 //skip spaces
		while (line[*i] == ' ' && line[*i] != '\0')
			(*i)++;
		// if line ends or comma is found we shoot an error
		if (line[*i] == '\0' || line[*i] == ',')
		{
			free(rgb);
			return (NULL);
		}
		// counts value len until
		while (line[*i + len] 
			!= '\0' && line[*i + len] 
			!= '\n' && line[*i + len] 
			!= ',') 
			len++;
		// printf("collected value %d has len %d - from char[%d]:%c to char[%d]: %c,\n", indexes, len, *i, line[*i], (*i)+(len-1), line[(*i)+(len - 1)]);
		value = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(value, line + *i, len + 1);
		// need to use better atoi from philo
		rgb[indexes] = store_value(value);
		free(value);
		*i += len;
		// printf("N %d: %d\n", indexes, rgb[indexes]);
		indexes++;
		// printf("c: '%c'\n", line[*i]); // have a problem with \n at the end for comma edge
		(*i)++;
	}
	// why less than 2
	if (indexes < 2)
	{
		return (NULL);
	}
	else
	{
		// if (line[*i] == '\0')
			// printf("END\n");
		while (line[*i] == ' ' 
			|| line[*i] == '\n' 
			|| line[*i] == '\t') // skip spaces
			(*i)--;
		// printf("----line %s", line);
		// printf("landed on %c | index %d  | indexes %d \n", line[*i], *i, indexes);
		if (line[*i] == ',')
		{
			free(rgb);
			return (NULL);
		}
	}
	return (rgb);
}

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
		if ((*counter) == 1)
			return (true);
	}
	return (false);
}


bool	find_textures(char *line, int *i, t_game *game)
{
	return (collect_coordinates(line, i, game) || collect_rgb(line, i, game));
}

bool	texture_data(char *line, t_game *game, int *line_n, bool *err)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
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
		if (find_textures(line, &i, game))
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
			printf("Error: invalid coord format in line index %d\n", *line_n);
			// no leaks if it
			// I DON'T REMEMBER THIS
			(void)err; // I DO NOT NEED ERROR I GUESS
			// *err = true;
			// check_fd(line, game)
			return (true); 
		}
		i++;
	}
	return (false);
}
