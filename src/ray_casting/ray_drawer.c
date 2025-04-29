#include "../cub3d.h"

void ray_drawer(t_game *game)
{
	int	y;
	unsigned int c_color = rgb_to_hex(game->data->C_rgb);
	unsigned int f_color = rgb_to_hex(game->data->F_rgb);

	game->ray->line_height = (int)(WIN_HEIGHT / game->ray->wall_dist);
	game->ray->draw_start = -(game->ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = game->ray->line_height / 2 + WIN_HEIGHT / 2;
	if (game->ray->draw_end >= WIN_HEIGHT)
		game->ray->draw_end = WIN_HEIGHT - 1;

	y = paint_line(game, game->ray->draw_start, 0, c_color); // ceiling
	y = draw_texture(game);                                // textured wall
	paint_line(game, WIN_HEIGHT, y, f_color);                 // floor
}

t_texture *get_wall_texture(t_game *game)
{
	if (game->ray->side == NORTH)
		return game->no_text;
	else if (game->ray->side == SOUTH)
		return game->so_text;
	else if (game->ray->side == EAST)
		return game->ea_text;
	else // WEST
		return game->we_text;
}

void set_texture(t_game *game, t_texture *texture)
{
	t_ray *ray = game->ray;

	if (ray->side == EAST || ray->side == WEST)
	{
		ray->wall_x = game->player->y + ray->wall_dist * ray->dir_y;
	}
	else
	{
		ray->wall_x = game->player->x + ray->wall_dist * ray->dir_x;
	}
	ray->wall_x -= floor(ray->wall_x);

	ray->text_x = (int)(ray->wall_x * (double)texture->width);

	if ((ray->side == EAST && ray->dir_x > 0) || (ray->side == WEST && ray->dir_x < 0))
		ray->text_x = texture->width - ray->text_x - 1;
	else if ((ray->side == NORTH && ray->dir_y < 0) || (ray->side == SOUTH && ray->dir_y > 0))
		ray->text_x = texture->width - ray->text_x - 1;
}

int	paint_line(t_game *game, int y_end, int y_start, int color) // or paint_texture_line
{
	while (y_start <= y_end) //the = fix problem showing pixel line at the bottom
	{
		put_pixel(game->ray->current_x, y_start, color, game);
		y_start++;
	}
	return (y_start);
}

int get_pixel(t_texture *texture, int x, int y)
{
	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return 0;
	char *pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	return *(int *)pixel;
}

int draw_texture(t_game *game)
{
	t_ray		*ray = game->ray;
	t_texture	*texture = get_wall_texture(game);
	double		step;
	double		tex_pos;
	int			color;
	int			y;

	set_texture(game, texture);
	step = 1.0 * texture->height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;

	y = ray->draw_start;
	if (y < 0)
	{
		tex_pos += step * -y;
		y = 0;
	}
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
	return y;
}
