/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:42 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/09 20:16:36 by roaraujo         ###   ########.fr       */
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

// ------------------------------------------------		MACROS		-----------
# define KEY_ESC		65307		// ESC keycode
# define VALID_CHARS	"10 NSEW"	// valid map chars
# define STARTING_CHARS	"NSEW"		// valid starting position chars
# define WIDTH	1024
# define HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

// ------------------------------------------------		STRUCTS		-----------

typedef struct s_position
{
	int		line;
	int		column;
}		t_position;

typedef struct s_mlx_img
{
	int		*data;
	void	*pointer;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_mlx_img;

typedef struct s_mlx_struct
{
	void		*pointer;
	void		*window;
	t_mlx_img	*img;
}				t_mlx_struct;

typedef struct s_raycasting
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
	int				**buf;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				texture[8][TEX_HEIGHT * TEX_WIDTH];
	int				re_buf;
}				t_raycasting;

typedef struct s_data
{
	int				input_fd;
	int				colours[2][3];
	int				texture_fds[4];
	int				params_count;
	char			*line;
	char			**map;
	char			**map_copy_for_debug;
	t_position		starting_position;
	t_mlx_struct	mlx_struct;
	t_raycasting	raycasting;
}		t_data;

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
	SO,
	EA,
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
	STARTING_POS_ERROR,
	MULTIPLE_POS_CHARS_FOUND,
	PLAYER_OFF_MAP,
	MLX_ERROR
};

// ------------------------------------------------		PROTOTYPES	-----------
// tests_debug ********** APAGAR DPS ***************
// void		debug_print_map_read(char **map);
// void		debug_copy_map(t_data *data);

// error_handling.c
void		print_err_exit(int errcode, t_data *data);

// init_data.c
void		init_data(t_data *data);
void		init_raycasting_parameters(t_data *data);

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

// free_memory.c
void		free_data(t_data *data);

// hooks.c
void		set_hooks(t_data *data);

// key_press.c
int			keystrokes_management(int keycode, t_data *data);

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

// map_validation_utils.c
bool		try_to_move_in_direction(t_position next_move, t_position *prev_pos,
				t_position *next_pos, t_data *data);
void		decide_where_to_go_next(t_data *data, t_position *prev_pos,
				t_position curr_pos, t_position *next_pos);
void		find_starting_point(t_position *starting_point, t_data *data);

// map_validation_player_position.c
void		check_player_position(t_data *data);

// params_utils.c
bool		is_direction_identifier(char identifier[2]);
int			get_direction_index(char d);
int			get_colour_index(char c);
bool		is_valid_parameter_char(char c);
bool		has_valid_param_identifier(char *str);

// raycasting.c
int			raycasting(t_raycasting *ray, t_data *data);
void		calc_ray_casting(t_raycasting *ray, int x, t_data *data);

// texture_ray_casting.c
double		wall_x_calc(t_raycasting *ray);
int			take_x_coord_on_texture(t_raycasting *ray);
double		pixel_perscreen(t_raycasting *ray);
double		tex_coordinate(t_raycasting *ray);
int			conv_text_coord_to_int(t_raycasting *ray);
void		color_more_dark_to_y_sides(t_raycasting *ray);

// t_position_utils.c
t_position	t_position_create_tuple(int line, int column);
bool		t_position_compare(t_position a, t_position b);
bool		t_position_compare_ptr(t_position *a, t_position *b);
void		t_position_copy(t_position *destination, const t_position source);

#endif
