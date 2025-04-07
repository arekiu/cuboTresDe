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

int check_fd(char *file, char *type, t_data *data)
{
	data->fd = open(file, O_RDONLY);
	printf("%d\n", data->fd);
	if (!has_file_extension(file, type) || data->fd < 0)
	{
		printf("bubu\n");
		ft_printf("Error: file%s does not exist or has wrong extension\n", type);
		return (false);
	}
	return (true);
}

bool parse_assets(char *file_name, t_game *game)
{
	if (!check_fd(file_name, ".cub", game->data) || !get_fd_data(game->data->fd, &game->data->map, game))
	{
		close(game->data->fd);
		return (false);
	}
	close(game->data->fd);
	if(!parse_textures(game->data))
		return (false);
	// print_map(game->data);
	// parse_map(game->data->map, game); -- parse items in the map array
	// parse textures -- parse textures if they can be found and valid
	return (true);
}