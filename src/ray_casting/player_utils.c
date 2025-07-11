/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:09:04 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/06 13:15:34 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		on_destroy(game);
		return (0);
	}
	if (keycode == W)
		game->player->key_up = true;
	if (keycode == S)
		game->player->key_down = true;
	if (keycode == A)
		game->player->key_left = true;
	if (keycode == D)
		game->player->key_right = true;
	if (keycode == LEFT)
		game->player->left_rotate = true;
	if (keycode == RIGHT)
		game->player->right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player->key_up = false;
	if (keycode == S)
		game->player->key_down = false;
	if (keycode == A)
		game->player->key_left = false;
	if (keycode == D)
		game->player->key_right = false;
	if (keycode == LEFT)
		game->player->left_rotate = false;
	if (keycode == RIGHT)
		game->player->right_rotate = false;
	return (0);
}
