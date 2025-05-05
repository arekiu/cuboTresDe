#include "../cub3d.h"

void	rotate_player(t_game *game)
{
	if (game->player->left_rotate)
		game->player->angle -= game->player->angle_speed * game->delta_time;
	if (game->player->right_rotate)
		game->player->angle += game->player->angle_speed * game->delta_time;
	if (game->player->angle > 2 * PI) //it means that the angle it's bigger than 360 and get reset to 0;
		game->player->angle = 0;
	if (game->player->angle < 0) //less than 0, gets 360
		game->player->angle = 2 * PI;
	game->player->dir_x = cos(game->player->angle);
	game->player->dir_y = sin(game->player->angle);
	game->player->plane_x = -game->player->dir_y * 0.66;  // FOV scaling factor
	game->player->plane_y = game->player->dir_x * 0.66;

}

static void try_move_player(t_game *game, float next_x, float next_y)
{
	t_player	*p;
	float		size;

	p = game->player;
	size = p->player_size / 2;
	if (game->data->map[(int)((p->y - size) / BLOCK)][(int)((next_x - size) / BLOCK)] != '1' &&
		game->data->map[(int)((p->y + size) / BLOCK)][(int)((next_x - size) / BLOCK)] != '1' &&
		game->data->map[(int)((p->y - size) / BLOCK)][(int)((next_x + size) / BLOCK)] != '1' &&
		game->data->map[(int)((p->y + size) / BLOCK)][(int)((next_x + size) / BLOCK)] != '1')
	{
		p->x = next_x;
	}
	if (game->data->map[(int)((next_y - size) / BLOCK)][(int)((p->x - size) / BLOCK)] != '1' &&
		game->data->map[(int)((next_y + size) / BLOCK)][(int)((p->x - size) / BLOCK)] != '1' &&
		game->data->map[(int)((next_y - size) / BLOCK)][(int)((p->x + size) / BLOCK)] != '1' &&
		game->data->map[(int)((next_y + size) / BLOCK)][(int)((p->x + size) / BLOCK)] != '1')
	{
		p->y = next_y;
	}
}


static void calculate_next_position(t_game  *game, float *next_x, float *next_y, int direction)
{
	int			speed;
	t_player	*player;

	player = game->player;
	speed = player->speed;
	if (direction == NORTH)
	{
		*next_x = player->x + player->dir_x * speed * game->delta_time;
		*next_y = player->y + player->dir_y * speed * game->delta_time;
	}
	if (direction == SOUTH)
	{
		*next_x = player->x - player->dir_x * speed * game->delta_time;
		*next_y = player->y - player->dir_y * speed * game->delta_time;
	}
	if (direction == WEST)
	{
		*next_x = player->x + player->dir_y * speed * game->delta_time;
		*next_y = player->y - player->dir_x * speed * game->delta_time;
	}
	if (direction == EAST)
	{
		*next_x = player->x - player->dir_y * speed * game->delta_time;
		*next_y = player->y + player->dir_x * speed * game->delta_time;
	}
}

void move_in_direct(t_game *game)
{

	float	next_x;
	float	next_y;

	if (game->player->key_up)
	{
		calculate_next_position(game, &next_x, &next_y, NORTH);
		try_move_player(game, next_x, next_y);
	}
	if (game->player->key_down)
	{
		calculate_next_position(game, &next_x, &next_y, SOUTH);
		try_move_player(game, next_x, next_y);
	}
	if (game->player->key_left)
	{
		calculate_next_position(game, &next_x, &next_y, WEST);
		try_move_player(game, next_x, next_y);
	}
	if (game->player->key_right)
	{
		calculate_next_position(game, &next_x, &next_y, EAST);
		try_move_player(game, next_x, next_y);
	}
}

void	move_player(t_game *game)
{
	rotate_player(game);
	move_in_direct(game);
}
