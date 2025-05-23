/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschmidt <aschmidt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:13:47 by aschmidt          #+#    #+#             */
/*   Updated: 2025/05/23 15:43:02 by aschmidt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/src/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <limits.h>
# include <mlx.h>
# include <sys/time.h>

//COLORS - for debugging and printing pretty ;)
# define RESET_T "\033[0m"
# define RED_T "\033[31m"
# define BLUE_T "\033[0;94m"
# define PURPLE_T "\033[35m"
# define YELLOW_T "\033[33m"
# define GREEN_T "\033[32m"

//VALUES THAT WE CAN MODIFY
# define WIN_WIDTH 1200
# define WIN_HEIGHT 700
# define BLOCK 64
# define PLAYER_SIZE 7
# define PLAYER_SPEED 150
# define PLAYER_ANGLE_SPEED 1.0
# define MINI_BLOCK 20
# define MINIMAP_OFFSET_X 5
# define MINIMAP_OFFSET_Y 5

//CONSTANT VALUES
# define PI 3.1415926535

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

//This is for the movement, walking
# define WEST  0
# define EAST  1
# define NORTH 2
# define SOUTH 3

typedef struct s_data{
	int		fd;
	char	**map;
	int		player_x;
	int		player_y;
	char	player_orient;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int		*r_rgb;
	int		*c_rgb;
	int		no_found;
	int		so_found;
	int		we_found;
	int		ea_found;
	int		c_found;
	int		f_found;
	int		rgb_amount;
	bool	parse_err;
	bool	map_started;

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
	double	wall_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		text_x;
	int		text_y;
	int		text_start;
	int		step;
}	t_ray;

/* how much we move in the texture
vertically per screen pixel.
So if the wall slice is 64 pixels tall and the texture is 64
 pixels tall, the step is 1.0 (1 texel per screen pixel).*/

typedef struct s_player{
	float		x;
	float		y;
	char		orientation;
	int			player_size;
	float		angle;
	float		dir_x;
	float		dir_y;
	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;
	bool		left_rotate;
	bool		right_rotate;
	float		speed;
	float		angle_speed;
	float		plane_x;
	float		plane_y;
}	t_player;

typedef struct s_texture {
	void	*img;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_texture;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
}	t_line;

typedef struct s_square
{
	int		x;
	int		y;
	int		size;
	int		color;
}	t_square;

typedef struct s_game{
	void		*mlx;
	void		*window;
	void		*img;
	char		*buffer;
	int			bpp;
	int			stride;
	int			endian;
	t_player	*player;
	t_data		*data;
	t_ray		*ray;
	t_texture	*no_text;
	t_texture	*so_text;
	t_texture	*ea_text;
	t_texture	*we_text;
	double		last_frame_time;
	double		delta_time;
}	t_game;

// freeing
void			free_game(t_game *game);

//PARSE FILE
//PARSING FUNCTIONS
// Assets are contents in a game, so we can parse/check everything here
int				check_fd(char *file, char *type, t_data *data, char *obj);
bool			has_file_extension(char *file, char *extension);
bool			parse_assets(char	*file_name, t_game *game);
bool			collect_map_data(int fd, char ***map, t_game *game);
char			*ft_get_line(int fd);
bool			process_line(char *line, t_game *game, int *array_i);
bool			parse_textures(t_data *data);
bool			parse_map(t_data *data, t_player *player);
bool			is_shaped(char **map, int last_r, int last_c);
bool			has_required_text(char **map, t_player *player);
bool			has_enough_sprites(char **map);
bool			collect_coordinates(char *line, int *i, t_game *game);
bool			collect_rgb(char *line, int *i, t_game *game);
char			*store_texture(int *i, char *line, char *path);
bool			match_texture(char *id, int *counter, int *i, char *line);
int				*store_rgb( int *i, char *line);
void			assign_to_map(char *line, char ***map, int *array_i);

//debugging
void			print_map(t_data *data, t_player *player);

//INIT
void			init_game(t_game *game);
void			init_player(t_player *player, float orientation, int x, int y);
void			init_textures(t_game *game);

//UTILS
void			put_pixel(int x, int y, int color, t_game *game);
void			clear(t_game *game);
unsigned int	rgb_to_hex(int rgb[3]);
double			get_time_in_ms(void);
int				get_map_width(char **map);

//PLAYER UTILS
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);

//MOVE PLAYER
void			move_player(t_game *game);
void			move_in_direct(t_game *game);
void			rotate_player(t_game *game);

//RAY CASTING
int				draw_loop(t_game *game);
void			raycaster(t_game *game);
void			perform_dda(t_game *game);
void			calc_delta_dist(t_ray *ray);
void			calc_side_dist(t_game *game);

//DRAW
void			ray_drawer(t_game *game);
int				paint_line(t_game *game, int y, int i, int color);
int				get_pixel(t_texture *texture, int x, int y);

//TEXTURE
void			load_texture(t_game *game, t_texture *tex, char *path);
void			set_texture(t_game *game, t_texture *texture);
t_texture		*get_wall_texture(t_game *game);
int				draw_texture(t_game *game);
int				render_text_line(t_game *game, t_texture *texture, \
					double step, double tex_pos);
void			prep_text_drawing(t_game *game, t_texture **texture, \
					double *step, double *tex_pos);

//END
int				on_destroy(t_game *game);

//BONUS
void			draw_square(t_square sq, t_game *game);
void			draw_minimap(t_game *game);
void			draw_player(t_game *game, int square_size);
void			draw_line(t_game *game);
void			init_line_data(t_game *game, t_line *line);
void			step_line(t_line *line);
int				set_square_size(char **map);

#endif
