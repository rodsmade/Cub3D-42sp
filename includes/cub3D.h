/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:42 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/18 16:29:40 by gusalves         ###   ########.fr       */
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
# define PI 3.142857

// ------------------------------------------------		STRUCTS		-----------

typedef struct s_mlx_img
{
	void	*pointer;
	char	*addr;
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

typedef struct s_data
{
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			moveSpeed;
	double			rotSpeed;
	t_mlx_struct	*mlx;
	t_map_parameters *map;
}				t_data;


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
int	raycasting(t_data *data);

#endif
