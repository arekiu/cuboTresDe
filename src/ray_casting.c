#include "cub3d.h"

void calc_side_dist(t_game *game)
{
    if (game->raycaster->dir_x < 0)
    {
        game->raycaster->step_x = -1;
        game->raycaster->side_x = (game->player->x / BLOCK - game->raycaster->map_x) * game->raycaster->delta_x;
    }
    else
    {
        game->raycaster->step_x = 1;
        game->raycaster->side_x = (game->raycaster->map_x + 1.0 - game->player->x / BLOCK) * game->raycaster->delta_x;
    }

    if (game->raycaster->dir_y < 0)
    {
        game->raycaster->step_y = -1;
        game->raycaster->side_y = (game->player->y / BLOCK - game->raycaster->map_y) * game->raycaster->delta_y;
    }
    else
    {
        game->raycaster->step_y = 1;
        game->raycaster->side_y = (game->raycaster->map_y + 1.0 - game->player->y / BLOCK) * game->raycaster->delta_y;
    }
}

void	calc_delta_dist(t_ray *raycaster)
{
	//calculate delta dist x
	if (raycaster->dir_x == 0)
		raycaster->delta_x = 1e30; //ray parallel to y-axis, give super high value
	else if (raycaster->dir_x > 0)
		raycaster->delta_x = 1 / raycaster->dir_x;
	else
		raycaster->delta_x = 1 / -raycaster->dir_x;
//calculate delta dist y
	if (raycaster->dir_y == 0)
		raycaster->delta_y = 1e30; //ray parallel to y-axis, give super high value
	else if (raycaster->dir_y > 0)
		raycaster->delta_y = 1 / raycaster->dir_y;
	else
		raycaster->delta_y = 1 / -raycaster->dir_y;

}

void	perform_DDA(t_game *game)
{

	game->raycaster->hit_side = 0;
	while (game->raycaster->hit_side == 0)
	{
		if (game->raycaster->map_x < 0 || game->raycaster->map_x >= get_map_width(game->map) ||
    game->raycaster->map_y < 0 || game->raycaster->map_y >= get_map_height(game->map))
        {
            printf("Ray went out of bounds: map_x=%d, map_y=%d\n", game->raycaster->map_x, game->raycaster->map_y);
            game->raycaster->hit_side = 1; // Stop the loop
            break;
        }
		//jump to next map square, either in x-direction, or in y-direction
		if (game->raycaster->side_x < game->raycaster->side_y)
		{
			game->raycaster->side_x += game->raycaster->delta_x;
			game->raycaster->map_x += game->raycaster->step_x;
			game->raycaster->side = 0;
		}
		else
		{
			game->raycaster->side_y += game->raycaster->delta_y;
			game->raycaster->map_y += game->raycaster->step_y;
			game->raycaster->side = 1;
		}

		if (game->map[game->raycaster->map_y][game->raycaster->map_x] == '1')
			game->raycaster->hit_side = 1;
		if (game->raycaster->side == 0)
			game->raycaster->wall_dist = (game->raycaster->side_x - game->raycaster->delta_x);
		else
			game->raycaster->wall_dist = (game->raycaster->side_y - game->raycaster->delta_y);
	}
}

void	raycaster(t_game *game, int i)
{
	game->raycaster->camera_x = 2 * i / (double)game->screen_width - 1; //x-coord in camera space
	game->raycaster->dir_x = game->player->dir_x + game->player->plane_x * game->raycaster->camera_x;
	game->raycaster->dir_y = game->player->dir_y + game->player->plane_y * game->raycaster->camera_x;
	game->raycaster->map_x = (int)(game->player->x / BLOCK);
	game->raycaster->map_y = (int)(game->player->y / BLOCK);
	calc_delta_dist(game->raycaster);
	calc_side_dist(game);
	perform_DDA(game);
}

int	draw_loop(t_game *game)
{
	int		i;

	i = 0;
	move_player(game);
	clear(game);
	draw_square((int)game->player->x - PLAYER_SIZE / 2,\
		(int)game->player->y - PLAYER_SIZE / 2, PLAYER_SIZE,0xFF0000,game);
	draw_map(game);
	while (i < game->screen_width)
	{
		raycaster(game, i);

        // Calculate ray end position for debugging
       float ray_end_x = game->player->x + game->raycaster->dir_x * game->raycaster->wall_dist * BLOCK;
       float ray_end_y = game->player->y + game->raycaster->dir_y * game->raycaster->wall_dist * BLOCK;

        draw_debug_ray(game, ray_end_x, ray_end_y, 0x00FF00);
        i++;
    }
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (1);
}

