/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:13:23 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/22 15:27:55 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_textures(t_game *game)
{
	if (game->no_text && game->no_text->img)
		mlx_destroy_image(game->mlx, game->no_text->img);
	free(game->no_text);
	if (game->so_text && game->so_text->img)
		mlx_destroy_image(game->mlx, game->so_text->img);
	free(game->so_text);
	if (game->we_text && game->we_text->img)
		mlx_destroy_image(game->mlx, game->we_text->img);
	free(game->we_text);
	if (game->ea_text && game->ea_text->img)
		mlx_destroy_image(game->mlx, game->ea_text->img);
	free(game->ea_text);
}

int	on_destroy(t_game *game)
{
	free_textures(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->ray);
	free(game->mlx);
	exit(0);
}
