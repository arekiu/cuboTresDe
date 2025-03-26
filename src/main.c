#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Error!!!\nInvalid number of arguments\n");
		return (1);
	}
	parse_file(argv[1]); // this is where i should use the stuff
	init_game(&game);
	mlx_hook(game.window, 2, 1, key_press, &game); //2 is KEYPRESS event and 1 for listen to keys "pressed"
	mlx_hook(game.window, 3, 2, key_release, &game);
	mlx_hook(game.window, 17, 0, on_destroy, &game); //17 event to close game with X
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);

	return (0);
}
