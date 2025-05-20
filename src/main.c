#include "cub3d.h"

t_game *start_allocation(void)
{
	t_game *game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		ft_printf("Error: malloc failed (t_game)\n");
		return NULL;
	}

	game->data = ft_calloc(1, sizeof(t_data));
	game->player = ft_calloc(1, sizeof(t_player));


	if (!game->data || !game->player)
	{
		ft_printf("Error: malloc failed (sub-struct)\n");
		free_game(game);
		return NULL;
	}
	return game;
}

int main(int argc, char **argv)
{
	t_game *game;

	if (argc != 2)
	{
		ft_printf("Error: invalid number of arguments\n");
		exit(1); // jess: as error we should exit instead of return
	}
	game = start_allocation(); // if anything fails, game will be null and be handled in the conditional below
	if (!game || !parse_assets(argv[1], game)) // jess: if parsing fails, code should stop here
	{
		// VALGRIND: all leaks handled if game returns null
		free_game(game);
		exit(1);
	}
	// print_map(game->data, game->player);
	init_game(game);
	mlx_hook(game->window, 2, 1, key_press, game); //2 is KEYPRESS event and 1 for listen to keys "pressed"
	mlx_hook(game->window, 3, 2, key_release, game);
	mlx_hook(game->window, 17, 0, on_destroy, game); //17 event to close game with X
	mlx_loop_hook(game->mlx, draw_loop, game);
	mlx_loop(game->mlx);

	return (0);
}
