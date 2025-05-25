/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:18:35 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/20 12:38:53 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
INFO
- should free before exiting (either if exit code is 1 or 0)
- game has to be freed at the end
- close fd for map file and texture files
*/

static void	free_player(t_player *player)
{
	if (player)
		free(player);
}

static void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	free_paths(t_data *data)
{
	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->we_path)
		free(data->we_path);
	if (data->ea_path)
		free(data->ea_path);
	if (data->r_rgb)
		free(data->r_rgb);
	if (data->c_rgb)
		free(data->c_rgb);
}

static void	free_data(t_data *data)
{
	if (!data)
		return ;
	free_map(data->map);
	free_paths(data);
	free(data);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_data(game->data);
	free_player(game->player);
	free(game);
}
