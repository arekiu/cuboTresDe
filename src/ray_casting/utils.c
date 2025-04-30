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

unsigned int rgb_to_hex(int rgb[3])
{
	return (rgb[0] * 65536 + rgb[1] * 256 + rgb[2]);
}


void	clear(t_game *game)
{
	ft_memset(game->buffer, 0, WIN_WIDTH * WIN_HEIGHT * (game->bpp / 8));
}

double	get_time_in_ms(void)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000.0) + (time.tv_usec / 1000.0);
}
