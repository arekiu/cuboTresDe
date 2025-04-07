/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslusark <jslusark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:34:26 by jslusark          #+#    #+#             */
/*   Updated: 2025/04/07 15:06:03 by jslusark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


bool check_amount(int   amount, char *type)
{
    if(amount > 1)
    {
        printf("Error: found duplicate %s data\n", type);
        return(false);
    }
    if(amount == 0)
    {
        printf("Error: %s data is missing\n", type);
        return(false);
    }
    return(true);
}

bool check_rgb_values(int   *code, char *type)
{
      const char *color[3];
      int i;

      i = 0;
      color[0] = "R";
      color[1] = "G";
      color[2] = "B";
      while(i < 3)
      {
          if(code[i] > 255 || code[i] < 0)
          {
              printf("Error: %s's %s:%d is not a valid number between 0 and 255\n", type, color[i], code[i]);
              return(false);
          }
          i++;
      }
    return(true);
}

bool    parse_textures(t_data *data)
{
    if (!check_amount(data->c_found, "ceiling")
        || !check_amount(data->f_found, "floor")
        || !check_rgb_values(data->C_rgb, "ceiling")
        || !check_rgb_values(data->F_rgb, "flooring"))
        return(false);
    if (!check_amount(data->no_found, "north")
        || !check_amount(data->so_found, "south")
        || !check_amount(data->ea_found, "east")
        || !check_amount(data->we_found, "west"))
        return(false);
   if (!check_fd(data->NO_path, ".xpm", data, "NORTH") // also add not found
        || !check_fd(data->SO_path, ".xpm", data, "SOUTH")
        || !check_fd(data->EA_path, ".xpm", data, "EAST")
        || !check_fd(data->WE_path, ".xpm", data, "WEST"))
        return(false);
    return(true);
}