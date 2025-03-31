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

bool not_map(char *line, t_game *game, int *line_n)
{
	// bool found_texture = 0;
	int i = 0;
	(void)game;
	(void)line_n;
	// printf("line %d: %c\n", *line_n, line[0]);

	while (line[i] != '\0')
	{
		// while(line[i] != ' ') // skip spaces
		// 	i++;
		// if(line[i] != '\0')
		// {
		// 	if(line[i] == 'N')
		// 	{
		// 		i++;
		// 		if(line[i] == 'O' && line[i] != '\0' && !game->data->n_found) // NO SO 
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
		i++;
	}
	return (false);
}