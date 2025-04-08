#include "../cub3d.h"

void calc_side_dist(t_game *game)
{
    if (game->ray->dir_x < 0)
    {
        game->ray->step_x = -1;
        game->ray->side_x = (game->player->x / BLOCK - game->ray->map_x) * game->ray->delta_x;
    }
    else
    {
        game->ray->step_x = 1;
        game->ray->side_x = (game->ray->map_x + 1.0 - game->player->x / BLOCK) * game->ray->delta_x;
    }


    if (game->ray->dir_y < 0)
    {
        game->ray->step_y = -1;
        game->ray->side_y = (game->player->y / BLOCK - game->ray->map_y) * game->ray->delta_y;
    }
    else
    {
        game->ray->step_y = 1;
        game->ray->side_y = (game->ray->map_y + 1.0 - game->player->y / BLOCK) * game->ray->delta_y;
    }

}

void	calc_delta_dist(t_ray *ray)
{
	//calculate delta dist x
	if (ray->dir_x == 0)
		ray->delta_x = 1e30; //ray parallel to x-axis, give super high value
	else if (ray->dir_x > 0)
		ray->delta_x = 1 / ray->dir_x;
	else
		ray->delta_x = 1 / -ray->dir_x;
//calculate delta dist y
	if (ray->dir_y == 0)
		ray->delta_y = 1e30; //ray parallel to y-axis, give super high value
	else if (ray->dir_y > 0)
		ray->delta_y = 1 / ray->dir_y;
	else
		ray->delta_y = 1 / -ray->dir_y;

}

void	perform_DDA(t_game *game)
{
	game->ray->hit_side = 0;
	while (game->ray->hit_side == 0)
	{
		if (game->ray->map_x < 0 || game->ray->map_x >= get_map_width(game->data->map) ||
    game->ray->map_y < 0 || game->ray->map_y >= get_map_height(game->data->map))
        {
            printf("Ray went out of bounds: map_x=%d, map_y=%d\n", game->ray->map_x, game->ray->map_y);
            game->ray->hit_side = 1; // Stop the loop
            break;
        }
		if (game->ray->side_x < game->ray->side_y)//jump to next map square, either in x-direction, or in y-direction
		{
			game->ray->side_x += game->ray->delta_x;
			game->ray->map_x += game->ray->step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray->side_y += game->ray->delta_y;
			game->ray->map_y += game->ray->step_y;
			game->ray->side = 1;
		}
		if (game->data->map[game->ray->map_y][game->ray->map_x] == '1')
			game->ray->hit_side = 1;
		if (game->ray->side == 0)
			game->ray->wall_dist = (game->ray->side_x - game->ray->delta_x);
		else
			game->ray->wall_dist = (game->ray->side_y - game->ray->delta_y);
	}
}

void	raycaster(t_game *game)
{
	game->ray->camera_x = 2 * game->ray->current_x / (double)WIN_WIDTH - 1; //x-coord in camera space
	game->ray->dir_x = game->player->dir_x + game->player->plane_x * game->ray->camera_x;
	game->ray->dir_y = game->player->dir_y + game->player->plane_y * game->ray->camera_x;
	game->ray->map_x = (int)(game->player->x / BLOCK);
	game->ray->map_y = (int)(game->player->y / BLOCK);
	calc_delta_dist(game->ray);
	calc_side_dist(game);
	perform_DDA(game);
}

int	draw_loop(t_game *game)
{
	game->ray->current_x = 0;
	move_player(game);
	clear(game);
	/*draw_square((int)game->player->x - PLAYER_SIZE / 2,\
		(int)game->player->y - PLAYER_SIZE / 2, PLAYER_SIZE,0xFF0000,game);
	draw_map(game);*/
	while (game->ray->current_x < WIN_WIDTH)
	{
		raycaster(game);
		/*
        // Calculate ray end position for debugging
       float ray_end_x = game->player->x + game->ray->dir_x * game->ray->wall_dist * BLOCK;
       float ray_end_y = game->player->y + game->ray->dir_y * game->ray->wall_dist * BLOCK;

        draw_debug_ray(game, ray_end_x, ray_end_y, 0x00FF00);*/
		ray_drawer(game);
        game->ray->current_x++;
    }
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (1);
}

