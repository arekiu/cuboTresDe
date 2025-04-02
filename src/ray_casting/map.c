#include "../cub3d.h"

void	draw_map(t_game *game)
{
	int	color;
	int x;
	int	y;

	color = 0x0000FF;
	y = 0;
    while (game->data->map[y])
    {
        x = 0;
        while (game->data->map[y][x])
        {
            if (game->data->map[y][x] == '1') // jess: if wall we draw the wall
			{
                    draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
            }
            x++;
        }
        y++;
    }
}

int get_map_height(char **map)
{
    int height = 0;
    while (map[height])
        height++;
    return height;
}

int get_map_width(char **map)
{
    if (!map[0])
        return 0;
    return strlen(map[0]);
}
