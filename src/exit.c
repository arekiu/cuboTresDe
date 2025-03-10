#include "cub3d.h"

void	free_game(t_game *game)
{
	if (game->player)
		free(game->player);
}
