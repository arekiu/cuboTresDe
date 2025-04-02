#include "../cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if(x >= game->screen_width || y >= game->screen_height || x < 0 || y < 0)
		return;
	index = y * game->stride + x * game->bpp / 8;
	game->buffer[index] = color & 0xFF;
	game->buffer[index + 1] = (color >> 8) & 0xFF;
	game->buffer[index + 2] = (color >> 16) & 0xFF;
}

void	draw_square(int x, int y, int size, int color, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(x + i, y, color, game);
		put_pixel(x, y + i, color, game);
		put_pixel(x + size, y + i, color, game);
		put_pixel(x + i, y + size, color, game);
		i++;
	}
}

void draw_debug_ray(t_game *game, float end_x, float end_y, int color)
{
    float dx = end_x - game->player->x;
    float dy = end_y - game->player->y;
    float steps = fmax(fabs(dx), fabs(dy));

    for (int i = 0; i <= steps; i++) {
        float x = game->player->x + dx * (i/steps);
        float y = game->player->y + dy * (i/steps);
        put_pixel((int)x, (int)y, color, game);
    }
}

void	clear(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->screen_height)
	{
		x = 0;
		while (x < game->screen_width)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}


