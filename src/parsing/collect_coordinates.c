/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:15:25 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/22 09:32:12 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	collect_coordinates(char *line, int *i, t_game *game)
{
	if (match_texture("NO ", &game->data->no_found, i, line))
	{
		if (game->data->no_found == 1)
			game->data->NO_path = store_texture(i, line, game->data->NO_path);
		return (true);
	}
	if (match_texture("SO ", &game->data->so_found, i, line))
	{
		if (game->data->so_found == 1)
			game->data->SO_path = store_texture(i, line, game->data->SO_path);
		return (true);
	}
	if (match_texture("EA ", &game->data->ea_found, i, line))
	{
		if (game->data->ea_found == 1)
			game->data->EA_path = store_texture(i, line, game->data->EA_path);
		return (true);
	}
	if (match_texture("WE ", &game->data->we_found, i, line))
	{
		if (game->data->we_found == 1)
			game->data->WE_path = store_texture(i, line, game->data->WE_path);
		return (true);
	}
	return (false);
}
