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

// void	store_texture(char*line, t_game *game, int *i)
// {
// 	while(line[*i] != '/0')
// 	{
        
//     }
    
// }

// int remaining_len()
// {

// }


bool store_rgb(int *amount_found, int *i, char *line, char *rgb_array)
{
	(void)rgb_array;
	char *value;
	value = NULL;
	// int edge = 0;
	// int j = 0;
	int	times;
	printf("LINE: %s", line); // C 120,0,16

	amount_found++;
	int len = 0;
	times = 0;
	(*i)++; // jump the letter
	// we stop grabbing rgb value at ,
	// cannot have more than 3 rgb values
	// atoi to detect errors
	while(line[*i] != 0 && line[*i] != '\n')// when , is found it means we have to stop grab rgb
	{
		while(line[*i] == ' ' && line[*i] != '\0')
			(*i)++; //skip spaces
		while (line[*i + len] != '\0' && line[*i + len] != '\n' && line[*i + len] != ',') // counts value len unril ,
			len++;
		value = malloc(sizeof(char) * (len + 1));
		printf("value %d has len %d - from char[%d]:%c to char[%d]: %c\n", times, len, *i, line[*i], (*i)+len, line[(*i)+len]);
		ft_strlcpy(value, line + *i, len + 1);
		*i += len;
		printf("VALUE %d: %s\n", times, value);
		len = 0; // resets for next value
		times++;
		(*i)++;
	}
	if (times > 3)
	{
		printf("Error: rgb is more than 3 values");
		return(false);
	}
	return(true);
}

char	*store_texture(int *amount_found, int *i, char *line, char *path)
{
	(void)path;
	(*amount_found)++;
	*i = *i + 2; //jump the coord 
	// printf("c: %c\n", line[*i]);
	while(line[*i] == ' ' && line[*i] != '\0')
		(*i)++; //skip spaces
	// printf("c: %c\n len path: ", line[*i]);
	int len = 0;
	while (line[*i + len] != '\0' && line[*i + len] != '\n')
	{
		// printf("%c", line[*i + len]);
		len++;
	}
	// printf("len: %d\n", len);
	path = malloc(sizeof(char) * (len + 1));
	if (!path || len == 0)
	{
		// printf("error\n");
		return (NULL);
	}
	return(ft_strcpy(path, line + *i));
}


bool	search_textures(char *line, int *i, t_game *game)
{
	if(ft_strncmp("NO ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->NO_path = store_texture(&game->data->no_found, i, line, game->data->NO_path);
		printf("NO found %d with path %s\n", game->data->no_found, game->data->NO_path);
		return(true);
	}
	if(ft_strncmp("SO ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->SO_path = store_texture(&game->data->so_found, i, line, game->data->SO_path);
		printf("SO found %d with path %s\n", game->data->so_found, game->data->SO_path);
		return(true);
	}
	if(ft_strncmp("WE ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->WE_path = store_texture(&game->data->we_found, i, line, game->data->WE_path);
		printf("WE found %d with path %s\n", game->data->we_found, game->data->WE_path);
		return(true);
	}
	if(ft_strncmp("EA ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->EA_path = store_texture(&game->data->ea_found, i, line, game->data->EA_path);
		printf("WE found %d with path %s\n", game->data->ea_found, game->data->EA_path);
		return(true);
	}
	if(ft_strncmp("C ", &line[*i], 2) == 0) // added a space after NO to avoid NOx passing the condition
	{
		// game->data->c_found++;
		// save texture func
		store_rgb(&game->data->c_found, i, line, "TEST");
		printf("C found %d\n", game->data->c_found);
		return(true);
	}
	if(ft_strncmp("F ", &line[*i], 2) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->f_found++;
		// save texture func
		printf("F found %d\n", game->data->f_found);
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
			return(true); // check_map(line, game)
		}

		i++;
	}
	return (false);
}