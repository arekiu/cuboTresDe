#include "../cub3d.h"

int draw_texture(t_game *game)
{
	t_texture	*texture;
	double		step;
	double		tex_pos;

	prepare_texture_drawing(game, &texture, &step, &tex_pos);
	return (render_texture_line(game, texture, step, tex_pos));
}
int render_texture_line(t_game *game, t_texture *texture, double step, double tex_pos)
{
	t_ray	*ray;
	int		y;
	int		color;

	ray = game->ray;
	y = ray->draw_start;
	if (y < 0)
		y = 0;
	while (y < ray->draw_end && y < WIN_HEIGHT)
	{
		int tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		else if (tex_y >= texture->height)
			tex_y = texture->height - 1;

		color = get_pixel(texture, ray->text_x, tex_y);
		put_pixel(ray->current_x, y, color, game);

		tex_pos += step;
		y++;
	}
	return (y);
}

void prepare_texture_drawing(t_game *game, t_texture **texture, double *step, double *tex_pos)
{
	t_ray *ray;

	ray = game->ray;
	*texture = get_wall_texture(game);
	set_texture(game, *texture);
	*step = 1.0 * (*texture)->height / ray->line_height;
	*tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * (*step);
	if (ray->draw_start < 0)
		*tex_pos += (*step) * -ray->draw_start;
}
