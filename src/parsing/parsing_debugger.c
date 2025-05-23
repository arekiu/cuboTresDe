/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_debugger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:38:12 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 15:14:01 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_map(t_data *data, t_player *player)
{
	int	i;
	int	j;
	int	line_len;

	i = 0;
	j = 0;
	line_len = data->map && data->map[0] ? ft_strlen(data->map[0]) : 0;

	printf(GREEN_T"\n---DATA COLLECTED FROM .CUB FILE---\n"RESET_T);
	printf(BLUE_T"\nCoordinates\n"RESET_T);	
	printf("Times_found:%d  NO: %s\n", data->no_found, data->NO_path ? data->NO_path : RED_T"NOT FOUND"RESET_T);
	printf("Times_found:%d  SO: %s\n", data->so_found, data->SO_path ? data->SO_path : RED_T"NOT FOUND"RESET_T);
	printf("Times_found:%d  WE: %s\n", data->we_found, data->WE_path ? data->WE_path : RED_T"NOT FOUND"RESET_T);
	printf("Times_found:%d  EA: %s\n", data->ea_found, data->EA_path ? data->EA_path : RED_T"NOT FOUND"RESET_T);
	printf(BLUE_T"\nRGB ARRAY\n"RESET_T);
	if (data->C_rgb)
		printf("Times_found:%d  CEILING R:'%d', G:'%d', B:'%d'\n", data->c_found, data->C_rgb[0], data->C_rgb[1], data->C_rgb[2]);
	else
		printf("Times_found:%d  CEILING R:'%s', G:'%s', B:'%s'\n", data->c_found, RED_T"0"RESET_T, RED_T"0"RESET_T, RED_T"0"RESET_T);

	if (data->F_rgb)
		printf("Times_found:%d  FLOOR   R:'%d', G:'%d', B:'%d'\n", data->f_found, data->F_rgb[0], data->F_rgb[1], data->F_rgb[2]);
	else
		printf("Times_found:%d  FLOOR   R:'%s', G:'%s', B:'%s'\n", data->f_found, RED_T"0"RESET_T, RED_T"0"RESET_T, RED_T"0"RESET_T);

	printf(BLUE_T"\nPLAYER INFO\n"RESET_T);
	if (player)
	{
		printf("Player Y-axis: %f\n", player->y);
		printf("Player X-axis: %f\n", player->x);
		printf("Player[%f][%f] Orientation: %c\n", player->y, player->x, player->orientation);
	}
	else
	{
		printf(RED_T"Player: NOT FOUND\n"RESET_T);
	}

	printf(BLUE_T"\nMAP\n"RESET_T);
	printf("  y");
    int y;
    y = 0;
    while (y < line_len)
	{
		printf(YELLOW_T"%d"RESET_T, y % 10);
		y++;
	}
	printf("\n x \n");

	while (data->map && data->map[i] != NULL)
	{
		printf(BLUE_T"%2d "RESET_T"%s\n", i, data->map[i]);
		i++;
	}

	printf("\n");
}
