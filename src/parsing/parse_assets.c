/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:43:41 by jslusark          #+#    #+#             */
/*   Updated: 2025/03/28 13:50:57 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_map(char *file, t_game *game) // returns null if fails
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (!has_file_extension(file, ".cub") || fd < 0)
	{
		ft_printf("Error: file does not exist or has wrong extension format\n");
		close(fd);
        return (NULL);
	}
	if(!collect_map(fd, &game->data->map, game))
	{
		close(fd);
		return (false);
	}
	close(fd);
	print_map(game->data);
	// exit(0); // removing this after testing
	return (true);
}


bool	parse_assets(char	*file_name, t_game *game) // error handling if we have more
{
    (void)game;
    if(!check_map(file_name, game))
		return (false);
	if(!parse_textures(game->data))
		return (false);

	
	// parse_map(game->data->map, game); -- parse items in the map array
	// parse textures -- parse textures if they can be found and valid
    return (true);
}

