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

int check_fd(char *file, char *type)
{
	int fd = open(file, O_RDONLY);
	if (!has_file_extension(file, type) || fd < 0)
	{
		ft_printf("Error: file does not exist or has wrong extension\n");
		return (-1);
	}
	return (fd);
}

bool parse_assets(char *file_name, t_game *game)
{
	game->data->fd = check_fd(file_name, ".cub");
	if (game->data->fd == -1 || !get_fd_data(game->data->fd, &game->data->map, game))
	{
		if (game->data->fd != -1)
			close(game->data->fd);
		return (false);
	}
	close(game->data->fd);
	if(!parse_textures(game->data))
		return (false);
	// print_map(game->data);
	exit(0);
	// parse_map(game->data->map, game); -- parse items in the map array
	// parse textures -- parse textures if they can be found and valid
	return (true);
}