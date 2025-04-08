#include "../cub3d.h"

void	draw_player_dir(t_game *game)
{
	int		start_x, start_y;
	int		end_x, end_y;

	start_x = MINIMAP_OFFSET_X + (int)(game->player->x / BLOCK * MINI_BLOCK);
	start_y = MINIMAP_OFFSET_Y + (int)(game->player->y / BLOCK * MINI_BLOCK);

	end_x = start_x + cos(game->player->angle) * 20;
	end_y = start_y + sin(game->player->angle) * 20;

	draw_line(game, start_x, start_y, end_x, end_y, 0xFFFF00);
}

void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int		dx = abs(x1 - x0);
	int		dy = abs(y1 - y0);
	int		sx = (x0 < x1) ? 1 : -1;
	int		sy = (y0 < y1) ? 1 : -1;
	int		err = dx - dy;
	int		e2;

	while (x0 != x1 || y0 != y1)
	{
		put_pixel(x0, y0, color, game);
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw_player(t_game *game)
{
	int px = MINIMAP_OFFSET_X + (int)(game->player->x / BLOCK * MINI_BLOCK);
	int py = MINIMAP_OFFSET_Y + (int)(game->player->y / BLOCK * MINI_BLOCK);
	draw_square(px - 2, py - 2, PLAYER_SIZE, 0x000000, game);
}

void	draw_minimap(t_game *game)
{
	int		x, y;
	int		color;
	char	**map = game->data->map;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && map[y][x] != '\n')
		{
			if (map[y][x] == '1')
				color = 0xFFFFFF; // white for walls
			else
				color = 0x000000; // black for empty space

			draw_square(MINIMAP_OFFSET_X + x * MINI_BLOCK,
						MINIMAP_OFFSET_Y + y * MINI_BLOCK,
						MINI_BLOCK,
						color,
						game);
			x++;
		}
		y++;
	}
	draw_player(game);
	draw_player_dir(game);
}
