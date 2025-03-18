#include "cub3d.h"

static void	rotate_player(t_game *game)
{
	if (game->player->left_rotate)
		game->player->angle -= game->player->angle_speed;
	if (game->player->right_rotate)
		game->player->angle += game->player->angle_speed;
	if (game->player->angle > 2 * PI) //it means that the angle it's bigger than 360 and get reset to 0;
		game->player->angle = 0;
	if (game->player->angle < 0) //less than 0, gets 360
		game->player->angle = 2 * PI;
    game->player->cos_angle = cos(game->player->angle);
    game->player->sin_angle = sin(game->player->angle);
}

static void try_move_player(t_game *game, float next_x, float next_y)
{
    if (game->map[(int)(next_y / BLOCK)][(int)(next_x / BLOCK)] != '1' && // TOP LEFT
        game->map[(int)(next_y / BLOCK)][(int)((next_x + game->player->player_size) / BLOCK)] != '1' && //TOP RIGHT
        game->map[(int)((next_y + game->player->player_size) / BLOCK)][(int)(next_x / BLOCK)] != '1' && //BOTTOM LEFT
        game->map[(int)((next_y + game->player->player_size) / BLOCK)][(int)((next_x + game->player->player_size) / BLOCK)] != '1') //BOTTOM RIGHT
    {
        game->player->x = next_x;
        game->player->y = next_y;
    }
}

static void calculate_next_position(t_game  *game, float *next_x, float *next_y, int direction)
{
    int speed;
    t_player    *player;

    player = game->player;
    speed = player->speed;
    if (direction == 1)//UP
    {
        *next_x = player->x + player->cos_angle * speed;
        *next_y = player->y + player->sin_angle * speed;
    }
    if (direction == 2)//DOWN
    {
        *next_x = player->x - player->cos_angle * speed;
        *next_y = player->y - player->sin_angle * speed;
    }
    if (direction == 3)//LEFT
    {
        *next_x = player->x + player->sin_angle * speed;
        *next_y = player->y - player->cos_angle * speed;
    }
    if (direction == 4)//RIGHT
    {
        *next_x = player->x - player->sin_angle * speed;
        *next_y = player->y + player->cos_angle * speed;
    }
}

static void move_in_direct(t_game *game)
{

    float   next_x;
    float   next_y;

    if (game->player->key_up)
    {
        calculate_next_position(game, &next_x, &next_y, 1);
        try_move_player(game, next_x, next_y);
    }
    if (game->player->key_down)
    {
        calculate_next_position(game, &next_x, &next_y, 2);
        try_move_player(game, next_x, next_y);
    }
    if (game->player->key_left)
    {
        calculate_next_position(game, &next_x, &next_y, 3);
        try_move_player(game, next_x, next_y);
    }
    if (game->player->key_right)
    {
        calculate_next_position(game, &next_x, &next_y, 4);
        try_move_player(game, next_x, next_y);
    }
}

void	 move_player(t_game *game)
{
	rotate_player(game);
	move_in_direct(game);
}
