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


int	store_value(const char *nptr)// returns -1 if not valid key
{
	int	num;
	size_t				i;

	num = 0;
	i = 0;

	// printf("nptr: '%s'\n", nptr);
	if (!ft_isdigit(nptr[i]))
		return (-2);
	while (ft_isdigit(nptr[i]))
	{
		num = (num * 10) + (nptr[i] - '0');
		if (num > INT_MAX || num < INT_MIN) // to avoid overflow
			return (-2);
		i++;
	}
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		(i)++;
	if (nptr[i] != '\0')
		return (-2);
	return (num);
}

int *store_rgb(int *found, int *i, char *line)
{
	int *rgb = malloc(sizeof(int) * 3);
	char *value;
	int	indexes;
	int len;

	(*found)++;
	value = NULL;
	// printf("LINE: %s", line); // C 120,0,16
	indexes = 0;
	(*i)++; // jump the C or F
	if (!rgb)
	    return (false);
	while(line[*i] != 0 && line[*i] != '\n')// loop thorugh the line until is over
	{
		len = 0; // resets for next value
		if (indexes > 2)
			return(NULL);
		while(line[*i] == ' ' && line[*i] != '\0')
			(*i)++; //skip spaces
		if(line[*i] == '\0' || line[*i] == ',') // if line ends or comma is found we shoot an error
			return(NULL);
		while (line[*i + len] != '\0' && line[*i + len] != '\n' && line[*i + len] != ',') // counts value len unril ,
			len++;
		// printf("collected value %d has len %d - from char[%d]:%c to char[%d]: %c,\n", indexes, len, *i, line[*i], (*i)+(len-1), line[(*i)+(len - 1)]);
		value = malloc(sizeof(char) * (len + 1));
		ft_strlcpy(value, line + *i, len + 1);
		rgb[indexes] = store_value(value); // need to use better atoi from philo
		free(value);
		*i += len;
		// printf("N %d: %d\n", indexes, rgb[indexes]);
		indexes++;
		// printf("c: '%c'\n", line[*i]); // have a problem with \n at the end for comma edge
		(*i)++;
	}
	if(indexes < 2)
		return(NULL);
	return(rgb);
}

char	*store_texture(int *amount_found, int *i, char *line, char *path)
{
	(void)path;
	(*amount_found)++;
	*i = *i + 2; //jump the coord
	// printf("c: %c\n", line[*i]);
	while(line[*i] == ' ' && line[*i] != '\0' && line[*i] != '\n' )
		(*i)++; //skip spaces
	// if line is \0 rrepeated check here
	// printf("c: %c\n len path: ", line[*i]);
	int len = 0;
	while (line[*i + len] != '\0' && line[*i + len] != '\n' && line[*i + len] != ' ')
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
	ft_strlcpy(path, line + *i, len + 1); // fixes issue of saving \n (could use strncpy instead)
	return(path);
}


bool	search_textures(char *line, int *i, t_game *game)
{
	if(ft_strncmp("NO ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->NO_path = store_texture(&game->data->no_found, i, line, game->data->NO_path);
		return(true);
	}
	if(ft_strncmp("SO ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->SO_path = store_texture(&game->data->so_found, i, line, game->data->SO_path);
		return(true);
	}
	if(ft_strncmp("WE ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->WE_path = store_texture(&game->data->we_found, i, line, game->data->WE_path);
		return(true);
	}
	if(ft_strncmp("EA ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->EA_path = store_texture(&game->data->ea_found, i, line, game->data->EA_path);
		return(true);
	}
	if(ft_strncmp("C ", &line[*i], 2) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->C_rgb = store_rgb(&game->data->c_found, i, line); // or use strdup?
		return(true);
	}
	if(ft_strncmp("F ", &line[*i], 2) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->F_rgb = store_rgb(&game->data->f_found, i, line); // or use strdup?
		return(true);
	}
	return(false);
}

bool texture_data(char *line, t_game *game, int *line_n, bool *err)
{
	(void)line_n;
	(void)err;
	int i = 0;

	while (line[i] != '\0')
	{
		while (line[i] == ' ') // skip spaces
			i++;
		if (line[i] == '\n' || line[i] == '\0' ) // if only spaces found until end
		{
			if(!game->data->map_started) // and if map hasn't started yet
				return (true); //skip the lines
			else
				return (false); // if map started we have to include in the map
		}
		if(search_textures(line, &i, game))
			return(true);
		if(line[i] == '1' || line[i] == '0' || line[i] == ' ' || line[i] == '\n') // check if its a map
		{
			game->data->map_started = true; // flag to avoid skipping spac
			return(false); // false - should be saved in map
		}
		else
		{
			printf("Error: invalid coord format in line %d\n", *line_n);
			*err = true;
			return(true); // check_fd(line, game)
		}

		i++;
	}
	return (false);
}
