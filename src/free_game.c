/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:18:35 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/06 13:26:04 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
TO FREE

- frees the game for last, before freeing everything else
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
        return;
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}
static void    free_paths(t_data *data)
{
    if (data->NO_path)
        free(data->NO_path);
    if (data->SO_path)
        free(data->SO_path);
    if (data->WE_path)
        free(data->WE_path);
    if (data->EA_path)
        free(data->EA_path);
    if (data->F_rgb)
        free(data->F_rgb); // we just free once, not in the loop
    if (data->C_rgb)
        free(data->C_rgb); // we just free once, not in the loop
}

static void	free_data(t_data *data)
{
    if (!data)
		return;
    free_map(data->map);
    free_paths(data);
    free(data);
}

void	free_game(t_game *game)
{
    if (!game)
        return;
    // NEED TO FREE MLX LATER - keep in mind that order matters to avoid conditional jump
    // if (game->window)
    //     mlx_destroy_window(game->mlx, game->window);
    // if (game->img)
    //     mlx_destroy_image(game->mlx, game->img);
    // frees just the parsing data
    free_data(game->data);
    free_player(game->player);
    // free raycaster and other memeory allocated from alexis side
    // if (game->mlx)
	// 	free(game->mlx);
	free(game);
}