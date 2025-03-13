#include "cub3d.h"

static void	move_in_direct(t_game *game, float sin_angle, float cos_angle, int speed)
{
	if (game->player->key_up)
	{
		game->player->x += cos_angle * speed;
		game->player->y += sin_angle * speed;
	}
	if (game->player->key_down)
	{
		game->player->x -= cos_angle * speed;
		game->player->y -= sin_angle * speed;
	}
	if (game->player->key_left)
	{
		game->player->x += sin_angle * speed;
		game->player->y -= cos_angle * speed;
	}
	if (game->player->key_right)
	{
		game->player->x -= sin_angle * speed;
		game->player->y += cos_angle * speed;
	}
}

void	 move_player(t_game *game)
{
	int		speed;
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;

	speed = 3;
	angle_speed = 0.1;
	cos_angle = cos(game->player->angle);
	sin_angle = sin(game->player->angle);
	if (game->player->left_rotate)
		game->player->angle -= angle_speed;
	if (game->player->right_rotate)
		game->player->angle += angle_speed;
	if (game->player->angle > 2 * PI)
		game->player->angle = 0;
	if (game->player->angle < 0)
		game->player->angle = 2 * PI;
	move_in_direct(game, sin_angle, cos_angle, speed);
}

bool	collide(float ray_x, float ray_y, t_game *game)
{
	int	x;
	int	y;

	x = ray_x/BLOCK;
	y = ray_y/BLOCK;
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

void	draw_line(t_game *game, float start_x)
{
	float	ray_x;
	float	ray_y;
	float	cos_angle;
	float	sin_angle;

	ray_x = game->player->x;
	ray_y = game->player->y;
	cos_angle = cos(start_x);
	sin_angle = sin(start_x);

	while (!collide(ray_x, ray_y, game))
	{
		put_pixel(ray_x, ray_y, 0xFF0000, game);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

int	draw_loop(t_game *game)
{
	float	fraction;
	float	start_x;
	int		i;

	fraction = PI / 3 / WIDTH;
	start_x = game->player->angle - PI / 6;
	i = 0;
	move_player(game);
	clear(game);
	draw_square(game->player->x, game->player->y, 30, 0xFF0000, game);
	draw_map(game);
	while (i < WIDTH)
	{
		draw_line(game, start_x);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (1);
}


