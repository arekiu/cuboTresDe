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

// void	save_texture(char*line, t_game *game, int *i)
// {
// 	while(line[*i] != '/0')
// 	{
        
//     }
    
// }


// bool line_is_rgb(char *line, t_game *game, int *line_n)
// {
//     (void)game;
//     (void)line_n;
//     (void)line;
//     // check if the line starts with F or C
//     // if (line[0] == 'F' || line[0] == 'C')
//     // 	return (true);
//     return (false);
// }

char	*save_texture(int *amount_found, int *i, char *line, char *path)
{
	(void)path;
	(*amount_found)++;
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
	path = malloc(sizeof(char) * len + 1);
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
		*i = *i + 2; //jump the coord 
		game->data->NO_path = save_texture(&game->data->no_found, i, line, game->data->NO_path);
		printf("NO found %d with path %s\n", game->data->no_found, game->data->NO_path);
		return(true);
	}
	if(ft_strncmp("SO ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		*i = *i + 2; //jump the coord 
		game->data->SO_path = save_texture(&game->data->so_found, i, line, game->data->SO_path);
		printf("SO found %d with path %s\n", game->data->so_found, game->data->SO_path);
		return(true);
	}
	if(ft_strncmp("WE ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		*i = *i + 2; //jump the coord 
		game->data->WE_path = save_texture(&game->data->we_found, i, line, game->data->WE_path);
		printf("WE found %d with path %s\n", game->data->we_found, game->data->WE_path);
		return(true);
	}
	if(ft_strncmp("EA ", &line[*i], 3) == 0) // added a space after NO to avoid NOx passing the condition
	{
		*i = *i + 2; //jump the coord 
		game->data->EA_path = save_texture(&game->data->ea_found, i, line, game->data->EA_path);
		printf("WE found %d with path %s\n", game->data->ea_found, game->data->EA_path);
		return(true);
	}
	if(ft_strncmp("C ", &line[*i], 2) == 0) // added a space after NO to avoid NOx passing the condition
	{
		game->data->c_found++;
		// save texture func
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
		// else
		// {
		// 	printf("Error: invalid format or duplicate in line %d\n", *line_n);
		// 	*err = true;
		// 	return(true); // check_map(line, game)
		// }
	
		// if got all textures - check if we got dups or enough
		// if(game->data->n_found > 1)
		// {
		// 	printf("Error: found duplicate coordinates in NO\n");
		// }

		i++;
	}
	return (false);
}