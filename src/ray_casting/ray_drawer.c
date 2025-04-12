#include "../cub3d.h"

void ray_drawer(t_game *game)
{
	int	y;

	y = 0;
	game->ray->line_height = (int)(WIN_HEIGHT / game->ray->wall_dist);
	game->ray->draw_start = -(game->ray->line_height) / 2 + WIN_HEIGHT / 2;
	if (game->ray->draw_start < 0)
		game->ray->draw_start = 0;
	game->ray->draw_end = game->ray->line_height / 2 + WIN_HEIGHT /2;
	if (game->ray->draw_end > WIN_HEIGHT)
		game->ray->draw_end = WIN_HEIGHT - 1;
	y = paint_line(game, game->ray->draw_start, y, 0xFF0000); //draw ceiling
	//y = paint_line(game, game->ray->draw_end, y, 0x00FF00); //walls
	y = draw_texture(game, y);
	paint_line(game, WIN_HEIGHT, y, 0x0000FF); //floor
}

void	set_texture(t_game *game)
{
	t_ray	*ray;

	ray = game->ray;
	if (ray->side == EAST || ray->side == WEST)
	{
		ray->wall_x = game->player->y + ray->wall_dist * ray->dir_y;
		ray->wall_x -= floor(ray->wall_x);
		ray->text_x = (int)(ray->wall_x * (double)game->no_text->width);
		if (ray->dir_x > 0)
			ray->text_x = game->no_text->width - ray->text_x - 1;
	}
	else if (ray->side == NORTH || ray->side == SOUTH)
	{
		ray->wall_x = game->player->x + ray->wall_dist * ray->dir_x;
		ray->wall_x -= floor(ray->wall_x);
		ray->text_x = (int)(ray->wall_x * (double)game->no_text->width);
		if (ray->dir_x < 0)
			ray->text_x = game->no_text->width - ray->text_x - 1;
	}
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
	int color;
	char *pixel;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return 0;
	pixel = texture->addr + (y * texture->line_length + x * (texture->bpp / 8));
	color = *(int *)pixel;  // Extract the pixel color from the memory address
	return (color);
}

int draw_texture(t_game *game, int y_start)
{
	int		pix_color;
	t_ray	*ray;

	ray = game->ray;
	set_texture(game);
	ray->step = 1.0 * game->no_text->height / ray->line_height;
	ray->text_start = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * ray->step;

	while (y_start < ray->draw_end - 1)
	{
		ray->text_y = (int)ray->text_start % game->no_text->height;
		ray->text_start += ray->step;
		pix_color = get_pixel(game->no_text, ray->text_x, ray->text_y);
		put_pixel(ray->current_x, y_start, pix_color, game);  // Update y_start dynamically
		y_start++;
	}
	return (y_start);
}
