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
int	draw_loop(t_game *game)
{

	move_player(game);
	clear(game);
	draw_square(game->player->x, game->player->y, 30, 0xFF0000, game);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->window, game->img, 0, 0);
	return (1);
}


