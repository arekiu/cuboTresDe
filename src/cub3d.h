#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/src/libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
# include <mlx.h>

//VALUES THAT WE CAN MODIFY
#define WIDTH 1280
#define HEIGHT 720
#define BLOCK 64
#define PLAYER_SIZE 30
#define PLAYER_SPEED 3
#define PLAYER_ANGLE_SPEED 0.05

//CONSTANT VALUES
#define PI 3.1415926535

#define	ESC 65307
#define	W 119
#define A 97
#define S 115
#define D 100
#define LEFT 65361
#define RIGHT 65363

#define	NO (3*PI/2)
#define SO (PI/2)
#define WE (PI)
#define EA 0


typedef struct s_data{
	//parsed map with needed information
	char	**map_data;
	int		player_x;
	int		player_y;
	char	player_orient;
	char	*text_NO;
	char	*text_SO;
	char	*text_WE;
	char	*text_EA;
	char	*text_F;
	char	*text_C;

}	t_data;


typedef struct s_player{
	int		x;
	int		y;
	int		player_size;
	float	angle; //its going to be determined by parsing ---> PD: NO and SO were switched because of gaming cardinal things*
	//NO == PI/2 (90)
	//SO == 3PI/2 (270)
	//WE == PI (180)
	//EA == 0
	float	cos_angle; // moves the player along the X-axis based on their facing direction.
	float	sin_angle; // moves the player along the Y-axis based on their facing direction.
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
	int		speed;
	float	angle_speed;

}	t_player;

typedef struct s_game{

	void		*mlx;
	void		*window;
	void		*img;
	char		**map;
	char		*buffer; //store the pixels
	int			bpp; //bits per pixel
	int			stride; //BYtes per row
	int			endian; //How values are stored
	t_player	*player;
	t_data		*data;

}	t_game;

//PARSE FILE
int	parse_file(char	*file_name);

//INIT
void	init_game(t_game *game);
void	init_player(t_player *player, float orientation, int x, int y);

//UTILS
void	put_pixel(int x, int y, int color, t_game *game);
void	clear(t_game *game);
void	draw_square(int x, int y, int size, int color, t_game *game);


//PLAYER UTILS
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

//MOVE PLAYER
void	 move_player(t_game *game);
int		draw_loop(t_game *game);
bool	reach_wall(float ray_x, float ray_y, t_game *game);
void	draw_line(t_game *game, float stat_x);

//MAP
void	draw_map(t_game *game);
char	**get_map(void);

//END
int		on_destroy(t_game *game);

#endif
