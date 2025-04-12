#include "../cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if(x >= WIN_WIDTH || y >= WIN_HEIGHT || x < 0 || y < 0)
		return;
	index = y * game->stride + x * game->bpp / 8;
	game->buffer[index] = color & 0xFF;
	game->buffer[index + 1] = (color >> 8) & 0xFF;
	game->buffer[index + 2] = (color >> 16) & 0xFF;
}

void draw_square(int x, int y, int size, int color, t_game *game)
{
	int i;
	int j;

	i = 0;
	while (i < size)// Fill the square
	{
		j = 0;
		while (j < size)
		{
			put_pixel(x + i, y + j, color, game);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size) // Draw the borders
	{
		put_pixel(x + i, y, color, game);             // Top border
		put_pixel(x + i, y + size - 1, color, game);  // Bottom border
		put_pixel(x, y + i, color, game);             // Left border
		put_pixel(x + size - 1, y + i, color, game);  // Right border
		i++;
	}
}

void	clear(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			put_pixel(x, y, 0, game);
			x++;
		}
		y++;
	}
}
