#include "../cub3d.h"

void ray_drawer(t_game *game)
{
	int	y;

	y = 0;
	game->raycaster->line_height = (int)(WIN_HEIGHT / game->raycaster->wall_dist);
	game->raycaster->draw_start = -(game->raycaster->line_height) / 2 + WIN_HEIGHT / 2;
	if (game->raycaster->draw_start < 0)
		game->raycaster->draw_start = 0;
	game->raycaster->draw_end = game->raycaster->line_height / 2 + WIN_HEIGHT /2;
	if (game->raycaster->draw_end > WIN_HEIGHT)
		game->raycaster->draw_end = WIN_HEIGHT - 1;
	y = paint_line(game, game->raycaster->draw_start, y, 0xFF0000); //draw ceiling
	y = paint_line(game, game->raycaster->draw_end, y, 0x00FF00); //walls
	paint_line(game, WIN_HEIGHT, y, 0x0000FF); //floor
}


int	paint_line(t_game *game, int y, int i, int color) // or paint_texture_line
{
	while (i<y)
	{
		put_pixel(game->raycaster->current_x, i, color, game);
		i++;
	}
	return (i);
}
