#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/src/libft.h"

# include <stdbool.h> // jess: I use this so instead of using 1/0 we can return true/false (easier to not get confused)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
# include <mlx.h>

//COLORS - for debugging and printing pretty ;)
# define RESET_T "\033[0m"
# define RED_T "\033[31m"
# define BLUE_T "\033[0;94m"
# define PURPLE_T "\033[35m"
# define YELLOW_T "\033[33m"
# define GREEN_T "\033[32m"

//VALUES THAT WE CAN MODIFY
#define	WIN_WIDTH 1200
#define WIN_HEIGHT 700
#define BLOCK 64
#define PLAYER_SIZE 10
#define PLAYER_SPEED 1
#define PLAYER_ANGLE_SPEED 0.005
#define MINI_BLOCK 20
#define MINIMAP_OFFSET_X 10 //position in the screen
#define MINIMAP_OFFSET_Y 10 //position in the screen

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
	char	**map;
	int		player_x;
	int		player_y;
	char	player_orient;
	char	*NO_path;
	char	*SO_path;
	char	*WE_path;
	char	*EA_path;
	int		*F_rgb; // jess: i think this should be int array
	int		*C_rgb; // jess: i think this should be int array
	int		no_found; // jess: uding these int to check if
	int		so_found; // all textures are available
	int		we_found; // and if they appear more than once
	int		ea_found;
	int		c_found;
	int		f_found;
	int		rgb_amount; // number of values passed as rgb, if >3 it is error
	bool	parse_err; // flags the system if parsing error present to make thinsg easier
	bool	map_started; // jess: a check i use to skip empty lines before start of map

}	t_data;

typedef struct s_ray {
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
	int		step_x;
	int		step_y;
	double	side_x;
	double	side_y;
	int		side;
	int		hit_side;
	double	wall_dist;
	double	camera_x;
	int		current_x;
	double	wall_x; //x-axis where ray hit wall
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
} t_ray;

typedef struct s_player{
	float		x;
	float		y;
	int		player_size;
	float	angle; //its going to be determined by parsing ---> PD: NO and SO were switched because of gaming cardinal things*
	//NO == PI/2 (90)
	//SO == 3PI/2 (270)
	//WE == PI (180)
	//EA == 0
	float	dir_x; // moves the player along the X-axis based on their facing direction.
	float	dir_y; // moves the player along the Y-axis based on their facing direction.
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
	float		speed;
	float	angle_speed;
	float	plane_x;
	float	plane_y;

}	t_player;

typedef struct s_game{

	void		*mlx;
	void		*window;
	void		*img;
	char		*buffer; //store the pixels
	int			bpp; //bits per pixel
	int			stride; //BYtes per row
	int			endian; //How values are stored
	t_player	*player;
	t_data		*data;
	t_ray		*ray;

}	t_game;


//PARSE FILE
//PARSING FUNCTIONS
// Assets are contents in a game, so we can parse/check everything here
bool	parse_assets(char	*file_name, t_game *game);
char	*ft_get_line(int fd);
bool	collect_map(int fd, char ***map, t_game *game);
bool	texture_data(char *line, t_game *game, int *line_n, bool *err);

//debugging
void print_map(t_data *data);


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
void	move_player(t_game *game);
void	move_in_direct(t_game *game);
void	rotate_player(t_game *game);


//RAY CASTING
int		draw_loop(t_game *game);
void	raycaster(t_game *game);
void	perform_DDA(t_game *game);
void	calc_delta_dist(t_ray *ray);
void	calc_side_dist(t_game *game);
void	ray_drawer(t_game *game);
int		paint_line(t_game *game, int y, int i, int color);

//MAP
void	draw_map(t_game *game);
int		get_map_height(char **map);
int		get_map_width(char **map);
void	draw_line(t_game *game, int x0, int y0, int x1, int y1, int color);
//MINIMAP
void	draw_minimap(t_game *game);
void	draw_player(t_game *game);
void	draw_player_dir(t_game *game);

//END
int		on_destroy(t_game *game);

#endif
