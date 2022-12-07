/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:42 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/07 20:34:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ------------------------------------------------		INCLUDES	-----------

# include "libft.h"				// libft
# include "mlx.h"				// minilibx
# include <stdio.h>				// printf(), perror()
# include <errno.h>				// errno (macro)
# include <string.h>			// strerror()
# include <sys/types.h>			// open()
# include <sys/stat.h>			// open()
# include <fcntl.h>				// open()
# include <stdlib.h> 			// exit()
# include "ansi_color_codes.h"	// colours 🌈
# include <stdbool.h>			// bool type
# include <math.h>				// math functions
# include <X11/keysym.h>		// X11 header - keyboard key codes
# include <X11/X.h>				// X11 headers

// ------------------------------------------------		MACROS		-----------

# define KEY_ESC	65307		// ESC keycode
# define WIDTH	1024
# define HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define NB_OF_TEXTURES 4
# define VALID_CHARS	"10 NSEW"	// valid map chars
# define STARTING_CHARS	"NSEW"		// valid starting position chars

// ------------------------------------------------		STRUCTS		-----------

typedef struct s_position
{
	int		line;
	int		col;
}		t_position;

typedef struct s_map_cursor
{
	t_position	*prev_pos;
	t_position	*curr_pos;
	t_position	*next_pos;
}				t_map_cursor;

typedef struct s_mlx_img
{
	void	*pointer;
	int		*data;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		img_width;
	int		img_height;
}				t_mlx_img;

typedef struct s_map_data
{
	int			input_fd;
	int			params_count;
	int			floor_colour_hex;
	char		starting_pos_char;
	int			ceiling_colour_hex;
	int			colours_rgb[2][3];
	char		*texture_paths[4];
	char		*line;
	char		**map;
	t_position	starting_position;
}			t_map_data;

typedef struct s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			move_speed;
	double			rot_speed;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perp_wall_dist;
	int				line_height;
	int				color;
	int				draw_start;
	int				draw_end;
	int				buf[HEIGHT][WIDTH];
	int				tex_num;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				**texture;
	int				re_buf;
	t_map_data		*map_data;
}				t_ray;

typedef struct s_mlx_struct
{
	void		*pointer;
	void		*window;
	t_mlx_img	img;
}				t_mlx_struct;

typedef struct s_data
{
	t_mlx_struct	mlx;
	t_ray			ray;
	t_map_data		map_data;
}	t_data;

// ------------------------------------------------		ENUMS		-----------

enum e_colours {
	CEILING,
	FLOOR
};

enum e_rgb_values {
	R_VALUE,
	G_VALUE,
	B_VALUE
};

enum e_directions {
	NO,
	EA,
	SO,
	WE
};

enum e_ups_and_downs {
	UP,
	DOWN
};

enum e_err_codes {
	SYSCALL_ERROR,
	WRONG_ARGS_NO,
	FILE_EXTENSION_ERROR,
	INVALID_TEXTURE_PARAMS,
	MISSING_PARAMETER,
	REDUNDANT_PARAMETER_FOUND,
	INVALID_COLOUR_PARAM,
	INVALID_MAP,
	MEMORY_ALLOCATION,
	INVALID_CHAR_FOUND,
	INVALID_MAP_SIZE,
	MISSING_STARTING_POS_CHAR_ERROR,
	MULTIPLE_POS_CHARS_FOUND,
	PLAYER_OFF_MAP,
	MLX_ERROR
};

// ------------------------------------------------		PROTOTYPES	-----------
// t_position_utils.c
t_position	t_position_create_tuple(int line, int col);
bool		t_position_compare(t_position a, t_position b);
bool		t_position_compare_ptr(t_position *a, t_position *b);
void		t_position_copy(t_position *destination, const t_position source);

// colour_encode_util.c
int			encode_rgb_to_hex(u_int8_t red, u_int8_t green, u_int8_t blue);

// error_handling.c
void		print_err_exit(int errcode, t_data *data);

// hooks.c
void		set_hooks(t_data *data);

// init_data.c
void		init_map_data(t_map_data *map_parameters);
void		init_ray_parameters(t_data *data);
void		init_tex_parameters(t_data *data);
void		init_mlx_struct(t_data *data);
void		null_mallocable_pointers(t_data *data);

// ray_casting_utils.c
void		set_facing_direction_vector(t_data *data);
void		set_camera_plane_vector(t_data *data);

// input_validation_utils.c
char		*get_next_line_trimmed(int input_fd);
int			jump_spaces(const char *str);
int			convert_colour_to_int(char *colour, t_data *data);

// input_validation.c
void		validate_args(int argc, char *argv[], t_data *data);
void		validate_input_file(t_data *data);

// window.c
void		open_window(t_data *data);

// destroy.c
int			destroy(t_data *data);

// keystrokes.c
int			keystrokes_management(int keycode, t_data *data);

// move_player.c
void		move_player(int keycode, t_data *data);

// rotate.c
void		rotate_view(int keycode, t_data *data);

// map_padding.c
void		pad_map(t_data *data);

// map_params_checks.c
void		check_for_valid_path(t_data *data);
void		check_duplicate_parameter(t_data *data);
void		check_colour_params_count(char **colours_array, t_data *data);
void		check_for_valid_colour(t_data *data);

// map_utils.c
int			find_longest_line_length(char **map);

// map_validation.c
void		validate_map(t_data *data);

// wall_tracing.c
void		trace_outer_walls(t_data *data);

// map_validation_player_position.c
void		check_player_position(t_data *data);

// memory_release.c
void		free_data(t_data *data);

// params_utils.c
bool		is_direction_identifier(char identifier[2]);
int			get_direction_index(char d);
int			get_colour_index(char c);
bool		is_valid_parameter_char(char c);
bool		has_valid_param_identifier(char *str);

// raycasting.c
int			raycasting(t_data *data);
void		calc_raycasting(t_data *data, int x);

//ray_casting_utils.c
void		clean_buf_with_zero(t_ray *ray);
int			take_tex_num(t_data *data);

//dda.c
void		dda_loop_with_check_hit(t_data *data);
void		calc_perp_wall_dist_from_camera_plane(t_data *data);
void		calc_ray_side_distance_and_next_block_step(t_data *data);

// texture_calcs_0.c
double		tex_coordinate(t_data *data);
int			conv_text_coord_to_int(t_data *data);
void		color_more_dark_to_y_sides(t_data *data);

// texture_calcs_1.c
double		wall_x_calc(t_data *data);
int			take_x_coord_on_texture(t_data *data);
double		pixel_perscreen(t_data *data);

//texture_load.c
void		load_textures(t_data *data);

#endif
