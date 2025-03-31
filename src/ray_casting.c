#include "cub3d.h"

bool	reach_wall(float ray_x, float ray_y, t_game *game)
{
	int	x;
	int	y;

	x = ray_x/BLOCK; //determine which tile in the grid the ray is in.
	y = ray_y/BLOCK;
	if (game->data->map[y][x] == '1')
		return (true);
	return (false);
}

void	draw_line(t_game *game, float start_x)
{
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;

	ray_x = game->player->x;
	ray_y = game->player->y;
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	/*The ray starts from the player's position.
	The direction of the ray is determined by cos(start_x) and sin(start_x).*/
	while (!reach_wall(ray_x, ray_y, game))
	{
		put_pixel(ray_x, ray_y, 0xFF0000, game); //The ray is extended until it hits a wall
		ray_x += cos_angle;//Each step of loop, the ray moves a little further along its angle
		ray_y += sin_angle;
	}
}

int	draw_loop(t_game *game)
{
	float	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / WIDTH; // PI = 180, PI/3 = 60 grades (common view angle used in games og this type)
	start_x = game->player->angle - PI / 6; // the position of player (center) - 30 grades ((end_x will be game->player->angle + PI / 6))
	i = 0;
	move_player(game);
	clear(game);
	draw_square(game->player->x, game->player->y, game->player->player_size, 0xFF0000, game);
	draw_map(game);
	while (i < WIDTH)
	{
		draw_line(game, start_x);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (1);
}
/*
Dividing the Screen into Rays:
	In raycasting, each vertical column on the screen corresponds to one ray.

	Let's assume:
		Screen width (WIDTH) = 800 pixels
		FOV = 60° (π/3 radians)
		Each pixel represents a small change in the angle.

	How do we calculate the angle step per pixel?
		The total angle we need to cover is PI / 3 (60°).
			We divide this by the number of pixels in width (WIDTH), so:

					fraction = 𝜋/3 ÷ WIDTH

		For example, if WIDTH = 800 pixels:

					𝜋/3 ÷	800 ≈	0.00131 radians per pixel

Each time we move one pixel to the right, the angle increases by this small fraction.
*/

