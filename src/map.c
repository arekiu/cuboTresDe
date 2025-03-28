#include "cub3d.h"

char	**load_map(void)
{
    //jess: instead of doing this we could still add
    // some error management if the map fails to load
    // but besides parsing failing, what else could
    // make the map loading fail? rendering perhaps? but that is in the draw_map
    // so not sure if we need this function at all
	char	**map;

	map = malloc(sizeof(char *) * 11);
	if (!map)
    {
        ft_printf("Error loading map\n");
        return (NULL);
    }
	map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000100000001";
    map[3] = "100010000000001";
    map[4] = "100100000000001";
    map[5] = "100000000000001";
    map[6] = "100000000000001";
    map[7] = "100000000010001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
	return (map);
}

void	draw_map(t_game *game)
{
	int	color;
	int x;
	int	y;

	color = 0x0000FF;
	y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '1') // jess: if wall we draw the wall
			{
                    draw_square(x * BLOCK, y * BLOCK, BLOCK, color, game);
            }
            x++;
        }
        y++;
    }
}
