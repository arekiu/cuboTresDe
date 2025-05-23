/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:34:26 by jslusark          #+#    #+#             */
/*   Updated: 2025/05/23 13:37:17 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


bool	check_amount(int amount, char *type)
{
	if (amount > 1)
	{
		printf("Error: found duplicate %s data\n", type);
		return (false);
	}
	if (amount == 0)
	{
		printf("Error: %s data is missing \n", type);
		return (false);
	}
	return (true);
}

bool	check_rgb_values(int   *code, char *type)
{
	const char	*color[3];
	int			i;

	if (code == NULL)
	{
		printf("Error: %s rgb data has to have 3 values [0-255], separated by comma\n", type);
		return (false);
	}
	i = 0;
	color[0] = "RED";
	color[1] = "GREEN";
	color[2] = "BLUE";
	while (i < 3)
	{
		if (code[i] > 255 || code[i] < 0)
		{
			printf("Error: %s[%s]:\'%d\' is not a valid digit between 0 and 255\n", type, color[i], code[i]);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	parse_textures(t_data *data)
{
	if (!check_amount(data->c_found, "CEILING")
		|| !check_amount(data->f_found, "FLOOR")
		|| !check_rgb_values(data->c_rgb, "CEILING")
		|| !check_rgb_values(data->r_rgb, "FLOOR"))
		return (false);
	if (!check_amount(data->no_found, "NORTH")
		|| !check_amount(data->so_found, "SOUTH")
		|| !check_amount(data->ea_found, "EAST")
		|| !check_amount(data->we_found, "WEST"))
		return (false);
	// also add not found
	if (!check_fd(data->no_path, ".xpm", data, "NORTH")
		|| !check_fd(data->so_path, ".xpm", data, "SOUTH")
		|| !check_fd(data->ea_path, ".xpm", data, "EAST")
		|| !check_fd(data->we_path, ".xpm", data, "WEST"))
		return (false);
	return (true);
}
