#include "../cub3d.h"

void	load_texture(t_game *game, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
	{
		ft_printf("Error: failed to load texture: %s\n", path);
		exit(1);
	}
	printf("Texture loaded!");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length, &tex->endian);
}
