/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:56:54 by aschmidt          #+#    #+#             */
/*   Updated: 2025/03/06 15:36:11 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/src/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>

#define WIDTH 512
#define HEIGHT 512

/*typedef struct s_map{
	//parsed map with needed information
	int	map_length;
}	t_map;*/

/*typedef struct s_player{
	int	player_x;
	int	player_y;
	//something else related to player is coming?
}	t_player;*/

typedef struct s_game{
	mlx_t		*mlx;
	mlx_image_t	*image;
	//t_map		map;
	//t_player	player;


}	t_game;

#endif
