/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birdieber <birdieber@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:34:24 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/25 17:39:40 by birdieber        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_game	*start_allocation(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		ft_printf("Error: malloc failed (t_game)\n");
		return (NULL);
	}
	game->data = ft_calloc(1, sizeof(t_data));
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->data || !game->player)
	{
		ft_printf("Error: malloc failed (sub-struct)\n");
		free_game(game);
		return (NULL);
	}
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error: invalid number of arguments\n");
		exit(1);
	}
	game = start_allocation();
	if (!game || !parse_assets(argv[1], game))
	{
		free_game(game);
		exit(1);
	}
	init_game(game);
	mlx_hook(game->window, 2, 1, key_press, game);
	mlx_hook(game->window, 3, 2, key_release, game);
	mlx_hook(game->window, 17, 0, on_destroy, game);
	mlx_loop_hook(game->mlx, draw_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
