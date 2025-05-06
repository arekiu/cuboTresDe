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
