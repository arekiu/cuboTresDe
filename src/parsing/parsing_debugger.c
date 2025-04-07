/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_debugger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:38:12 by jslusark          #+#    #+#             */
/*   Updated: 2025/04/07 15:07:41 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_map(t_data *data)
{
    int i = 0;
    printf(GREEN_T"\n---DATA COLLECTED FROM .CUB FILE---\n"RESET_T);
    printf(BLUE_T"\nCoordinates\n"RESET_T);
    printf("Times_found:%d  NO: %s\n",data->no_found, data->NO_path); // time found is used to handle duplicates as an error
    printf("Times_found:%d  SO: %s\n",data->so_found, data->SO_path);
    printf("Times_found:%d  WE: %s\n",data->we_found, data->WE_path);
    printf("Times_found:%d  EA: %s\n",data->ea_found, data->EA_path);
    printf(BLUE_T"\nRGB ARRAY\n"RESET_T);
    printf("Times_found:%d  CEILING R:'%d', G:'%d', B:'%d'\n", data->c_found, data->C_rgb[0], data->C_rgb[1], data->C_rgb[2]);
    printf("Times_found:%d  FLOOR   R:'%d', G:'%d', B:'%d'\n", data->f_found, data->F_rgb[0], data->F_rgb[1], data->F_rgb[2]);


    printf(BLUE_T"\nMAP\n"RESET_T);
    while (data->map[i] != NULL)
    {
        printf("%s\n", data->map[i]);
        i++;
    }
    printf("\n");
}