/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:42 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/26 21:08:39 by gusalves         ###   ########.fr       */
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

# define KEY_ESC	65307		// ESC keycode
# define IMG_TEST			"./img/blueMacaw.xpm"
# define WIDTH	1024
# define HEIGHT 720
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

// ------------------------------------------------		STRUCTS		-----------

extern int	world_map[24][24];

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

typedef struct s_map_parameters
{
	int		fds[4];
	int		colours[2][3];
	int		params_count;
	char	*line;
}		t_map_parameters;

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
	int				**buf;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				texture[8][TEX_HEIGHT * TEX_WIDTH];
	int				re_buf;
	t_mlx_struct	*mlx;
	t_map_parameters *map;
}				t_ray;



// ------------------------------------------------		ENUMS		-----------

enum e_colours {CEILING, FLOOR};
enum e_directions {
	NO,
	SO,
	EA,
	WE
};
enum e_err_codes {
	SYSCALL_ERROR,
	WRONG_ARGS_NO,
	FILE_EXTENSION_ERROR,
	INVALID_TEXTURE_PARAMS,
	MISSING_PARAMETER,
	REDUNDANT_PARAMETER_FOUND,
	INVALID_COLOUR_PARAM
};

// ------------------------------------------------		PROTOTYPES	-----------
// error_handling.c
void	print_err_exit(int errcode, t_map_parameters *map_params);

// init_data.c
void	init_map_parameters(t_map_parameters *map_parameters);
void	init_ray_parameters(t_ray *ray, t_mlx_struct *mlx);

// input_validation_utils.c
char	*get_next_line_trimmed(int input_fd);
int		jump_spaces(const char *str);
int		convert_colour_to_int(char *colour, t_map_parameters *map_params);

// input_validation.c
void	validate_args(int argc, char *argv[], int *input_fd,
			t_map_parameters *map_params);
void	validate_input_file(int fd, t_map_parameters *map_params);

// window.c
void	window(t_mlx_struct *mlx);

// destroy.c
int		destroy(t_mlx_struct *mlx);

// key_press.c
int		keystrokes_management(int keycode, t_mlx_struct *mlx);

// map_params_checks.c
void	check_for_valid_path(t_map_parameters *map_params);
void	check_duplicate_parameter(t_map_parameters *map_params);
void	check_colour_params_count(char **colours_array,
			t_map_parameters *map_params);
void	check_for_valid_colour(t_map_parameters *map_params);

// params_utils.c
bool	is_direction_identifier(char identifier[2]);
int		get_direction_index(char d);
int		get_colour_index(char c);
bool	is_valid_parameter_char(char c);
bool	has_valid_param_identifier(char *str);

// raycasting.c
int		raycasting(t_ray *ray);
void	calc_rayCasting(t_ray *ray, int x);

// texture_rayCasting.c
double	wall_x_calc(t_ray *ray);
int	take_x_coord_on_texture(t_ray *ray);
double	pixel_perscreen(t_ray *ray);
double	tex_coordinate(t_ray *ray);
int	conv_text_coord_to_int(t_ray *ray);
void	color_more_dark_to_y_sides(t_ray *ray);


#endif
