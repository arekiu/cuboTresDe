#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_game game;

	if (argc != 2)
	{
		ft_printf("Error!!!\nInvalid number of arguments\n");
		return (1);
	}
	parse_file(argv[1]);
	init_game(&game);
	if (!init_mlx(&game))
		return (1);

	mlx_loop_hook(game.mlx, ft_hook, &game);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
	free_game(&game);
	return (0);
}
