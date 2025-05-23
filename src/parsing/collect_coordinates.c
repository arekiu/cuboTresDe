/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:15:25 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 13:36:40 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	collect_coordinates(char *line, int *i, t_game *game)
{
	if (match_texture("NO ", &game->data->no_found, i, line))
	{
		if (game->data->no_found == 1)
			game->data->no_path = store_texture(i, line, game->data->no_path);
		return (true);
	}
	if (match_texture("SO ", &game->data->so_found, i, line))
	{
		if (game->data->so_found == 1)
			game->data->so_path = store_texture(i, line, game->data->so_path);
		return (true);
	}
	if (match_texture("EA ", &game->data->ea_found, i, line))
	{
		if (game->data->ea_found == 1)
			game->data->ea_path = store_texture(i, line, game->data->ea_path);
		return (true);
	}
	if (match_texture("WE ", &game->data->we_found, i, line))
	{
		if (game->data->we_found == 1)
			game->data->we_path = store_texture(i, line, game->data->we_path);
		return (true);
	}
	return (false);
}
