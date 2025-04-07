#include "cub3d.h"

int main(int argc, char **argv)
{
	t_game *game;
	// jess: to avoid segfaults while we code it's better
	// we allocate the structs at least at the beginning
	game = malloc(sizeof(t_game));
	game->data = malloc(sizeof(t_data));
	game->player = malloc(sizeof(t_data));
	if (!game || !game->data || !game->player)
	{
		ft_printf("Error: malloc failed\n");
		exit(1); // jess: as error we should exit instead of return
	}
	if (argc != 2)
	{
		ft_printf("Error: invalid number of arguments\n");
		exit(1); // jess: as error we should exit instead of return
	}
	if (!parse_assets(argv[1], game)) // jess: if parsing fails, code should stop here
	{
		// jess: no need to print error message as it will be printed in the functions where it fails
		// we still need to free stuff here i think because parsing will also allocate the map and data
		// that exec will use
		// free(game.map); // should free all game data and have if statements to check if they are not null before freeing
		// print_map(game->data);
		printf("MAP DOES NOT PASS! \n");
		exit(1);
	}
	print_map(game->data);
	printf("MAP PASSES! \n");
	exit(0);
	// init_game(game);
	// mlx_hook(game->window, 2, 1, key_press, game); //2 is KEYPRESS event and 1 for listen to keys "pressed"
	// mlx_hook(game->window, 3, 2, key_release, game);
	// mlx_hook(game->window, 17, 0, on_destroy, game); //17 event to close game with X
	// mlx_loop_hook(game->mlx, draw_loop, game);
	// mlx_loop(game->mlx);

	return (0);
}
