#include "../cub3d.h"

void ray_drawer(t_game *game)
{
	int	y;

	y = 0;
	game->ray->line_height = (int)(WIN_HEIGHT / game->ray->wall_dist);
	game->ray->draw_start = -(game->ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = game->ray->line_height / 2 + WIN_HEIGHT /2;
	if (game->ray->draw_end > WIN_HEIGHT)
		game->ray->draw_end = WIN_HEIGHT - 1;
	y = paint_line(game, game->ray->draw_start, y, 0xFF0000); //draw ceiling
	y = paint_line(game, game->ray->draw_end, y, 0x00FF00); //walls
	paint_line(game, WIN_HEIGHT, y, 0x0000FF); //floor
}


int	paint_line(t_game *game, int y_end, int y_start, int color) // or paint_texture_line
{
	while (y_start <= y_end) //the = fix problem showing pixel line at the bottom
	{
		put_pixel(game->ray->current_x, y_start, color, game);
		y_start++;
	}
	return (y_start);
}
