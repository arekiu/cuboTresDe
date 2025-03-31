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

bool texture_data(char *line, t_game *game, int *line_n, bool *err)
{
	// bool found_texture = 0;
	int i = 0;
	// bool map_started = false;
	(void)game;
	(void)err;
	(void)line_n;
	// printf("line %d: %c\n", *line_n, line[0]);

	while (line[i] != '\0')
	{
		while (line[i] == ' ') // skip spaces
			i++;
		if (line[i] == '\n' || line[i] == '\0' ) // end of line
		{
			if(!game->data->map_started) 
				return (true); // if map did not start we can skip empyt lines and not include them 
			else
				return (false); // if map started we have to include in the map
		}
		if(line[i] == 'N') // skip spaces
			return(true);
		if (line[i] == 'S')
			return(true);
		if (line[i] == 'W')
			return(true);
		if (line[i] == 'E')
			return(true);
		if (line[i] == 'C' || line[i] == 'F')
			return(true); // check colors(line[i], line, game)
		if(line[i] == '1' || line[i] == '0' || line[i] == ' ' || line[i] == '\n') // check if its a map
		{	
			game->data->map_started = true;
			return(false); // check_map(line, game)
		}
		else
		{
			printf("Error: invalid format or duplicate in line %d\n", *line_n);
			*err = true;
			return(true); // check_map(line, game)
		}
		i++;
	}
	return (false);


		// else if(line[i] == 'N')
		// {
		// 	printf("heyyyyy 1\n");
		// 	i++;
		// 	if(line[i] == 'O' && !game->data->n_found) // NO SO 
		// 	{	
		// 		game->data->n_found = true;
		// 		printf("heyyyyy 2\n");
		// 		// save_texture(line, game, i);
		// 	}
		// 	else // its an error
		// 	{
		// 		printf("Error: invalid format or duplicate in line %d\n", *line_n);
		// 		*err = true;
		// 	}
		// 	return (true);
		// }
		// 	if(line[i] == 'S')
		// 	{
		// 		i++;
		// 		if(line[i] == 'O' && line[i] != '\0' && !game->data->s_found) // NO SO 
		// 		{	
		// 			game->data->s_found = true;
		// 			// save_texture(line, game, i);
		// 		}
		// 		else // its an error
		// 		{
		// 			printf("Error: invalid format or duplicate in line %d\n", *line_n);
		// 			line = NULL; //(so it triggers error)
		// 		}
        //         return (false);
		// 	}
		// 	if(line[i] == 'W' &&  !game->data->w_found)
		// 	{
		// 		i++;
		// 		if(line[i] == 'E' && line[i] != '\0') 
		// 		{	
		// 			game->data->w_found = true;
		// 			// save_texture(line, game, i);
		// 		}
		// 		else // its an error
		// 		{
		// 			printf("Error: invalid format or duplicate in line %d\n", *line_n);
		// 			line = NULL; //(so it triggers error)
		// 		}
        //         return (false);
		// 	}
		// }
		// if(line[i] == 'E' && !game->data->e_found)
		// {
		// 	i++; // its an error
		// 	if(line[i] == 'A') // NO SO 
		// 	{	
		// 		game->data->e_found = true;
		// 		// save_texture(line, game, i);
		// 	}
		// 	else
		// 	{
		// 		printf("Error: invalid format or duplicate in line %d\n", *line_n);
		// 		line = NULL; //(so it triggers error)
		// 	}
        //     return (false);
		// }
		// i++;
	// }
	// return (false);
}