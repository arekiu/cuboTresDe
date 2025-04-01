/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_debugger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:38:12 by jslusark          #+#    #+#             */
/*   Updated: 2025/04/01 11:48:40 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void print_map(t_data *data)
{
    int i = 0;
    printf("\n---DATA COLLECTED---\n");
    printf("Coordinates\n");
    printf("F:%d NO: %s",data->no_found, data->NO_path);
    printf("F:%d SO: %s",data->so_found, data->SO_path);
    printf("F:%d WE: %s",data->we_found, data->WE_path);
    printf("F:%d EA: %s",data->ea_found, data->EA_path);
    printf("Colors\n");
    printf("still (NULL)\n");

    printf("MAP\n");
    while (data->map[i] != NULL)
    {
        printf("%s", data->map[i]);
        i++;
    }
    printf("\n");
}