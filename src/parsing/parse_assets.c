/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_assets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birdieber <birdieber@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:57:41 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/25 17:31:23 by birdieber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	check_fd(char *file, char *type, t_data *data, char *obj)
{
	if (file == NULL)
	{
		printf("Error: %s coordinate path invalid or not found\n", obj);
		return (false);
	}
	data->fd = open(file, O_RDONLY);
	if (!has_file_extension(file, type) || data->fd < 0)
	{
		printf("Error: %s used for %s does not exist or has wrong extension\n",
			file, obj);
		return (false);
	}
	if (ft_strcmp(obj, "map data") != 0)
	{
		close(data->fd);
		return (true);
	}
	return (true);
}

bool	parse_assets(char *file_name, t_game *game)
{
	if (!check_fd(file_name, ".cub", game->data, "map data")
		|| !collect_map_data(game->data->fd, &game->data->map, game))
	{
		if (game->data->fd > 0)
			close(game->data->fd);
		return (false);
	}
	close(game->data->fd);
	if (!parse_textures(game->data))
		return (false);
	if (!parse_map(game->data, game->player))
		return (false);
	return (true);
}
