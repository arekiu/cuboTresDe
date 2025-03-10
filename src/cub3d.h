/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:56:54 by aschmidt          #+#    #+#             */
/*   Updated: 2025/03/10 15:24:38 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/src/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <MLX42/MLX42.h>

#define WIDTH 1280
#define HEIGHT 720

#define W 119
#define A 97
#define D 100
#define S 115

#define PI 3.1415926535

/*typedef struct s_map{
	//parsed map with needed information
	int	map_length;
}	t_map;*/


typedef struct s_player{
	int		x;
	int		y;
	char	orientation;

}	t_player;

typedef struct s_game{
	mlx_t		*mlx;
	mlx_image_t	*image;
	//t_map		map;
	t_player	*player;


}	t_game;

//PARSE FILE
int	parse_file(char	*file_name);

//DRAW PLAYER
void draw_square(mlx_image_t *image, int size, int color);

//INIT GAME
int init_mlx(t_game *game);
int	init_player(t_game *game);
void	init_game(t_game *game);

//MOVE PLAYER
void ft_hook(void *param);

//FREE GAME
void	free_game(t_game *game);

#endif
