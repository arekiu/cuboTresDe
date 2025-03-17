#include "cub3d.h"


static void	rotate_player(t_game *game)
{
	if (game->player->left_rotate)
		game->player->angle -= game->player->angle_speed;
	if (game->player->right_rotate)
		game->player->angle += game->player->angle_speed;
	if (game->player->angle > 2 * PI)
		game->player->angle = 0;
	if (game->player->angle < 0)
		game->player->angle = 2 * PI;
}

static bool is_wall_collision(t_game *game, float next_x, float next_y)
{
    // Check four corners of the player
    if (game->map[(int)((next_y) / BLOCK)][(int)((next_x) / BLOCK)] == '1' || // Top-left
        game->map[(int)((next_y) / BLOCK)][(int)((next_x + game->player->player_size) / BLOCK)] == '1' || // Top-right
        game->map[(int)((next_y + game->player->player_size) / BLOCK)][(int)((next_x) / BLOCK)] == '1' || // Bottom-left
        game->map[(int)((next_y + game->player->player_size) / BLOCK)][(int)((next_x + game->player->player_size) / BLOCK)] == '1')   // Bottom-right
    {
        return true;
    }
    return false;
}


static void try_move_player(t_game *game, float next_x, float next_y)
{
    if (!is_wall_collision(game, next_x, next_y))
    {
        game->player->x = next_x;
        game->player->y = next_y;
    }
}

static void move_in_direct(t_game *game, float sin_angle, float cos_angle)
{
    int speed = game->player->speed;
    float next_x, next_y;

    if (game->player->key_up)
    {
        next_x = game->player->x + cos_angle * speed;
        next_y = game->player->y + sin_angle * speed;
        try_move_player(game, next_x, next_y);
    }

    if (game->player->key_down)
    {
        next_x = game->player->x - cos_angle * speed;
        next_y = game->player->y - sin_angle * speed;
        try_move_player(game, next_x, next_y);
    }

    if (game->player->key_left)
    {
        next_x = game->player->x + sin_angle * speed;
        next_y = game->player->y - cos_angle * speed;
        try_move_player(game, next_x, next_y);
    }

    if (game->player->key_right)
    {
        next_x = game->player->x - sin_angle * speed;
        next_y = game->player->y + cos_angle * speed;
        try_move_player(game, next_x, next_y);
    }
}

void	 move_player(t_game *game)
{
	float	cos_angle; // moves the player along the X-axis based on their facing direction.
	float	sin_angle; //moves the player along the Y-axis based on their facing direction.

	cos_angle = cos(game->player->angle);
	sin_angle = sin(game->player->angle);
	rotate_player(game);
	move_in_direct(game, sin_angle, cos_angle);
}
