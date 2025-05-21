/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 10:15:23 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/21 10:28:32 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	collect_rgb(char *line, int *i, t_game *game)
{
	if (match_texture("C ", &game->data->c_found, i, line))
		return ((game->data->C_rgb = store_rgb(i, line)), true);
	if (match_texture("F ", &game->data->f_found, i, line))
		return ((game->data->F_rgb = store_rgb(i, line)), true);
	return (false);
}