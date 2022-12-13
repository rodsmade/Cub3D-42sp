/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/13 13:43:12 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_mlx_struct(t_data *data)
{
	data->mlx.pointer = mlx_init();
	if (!data->mlx.pointer)
		print_err_exit(MLX_ERROR, data);
	data->mlx.img.pointer = mlx_new_image(data->mlx.pointer, WIDTH, HEIGHT);
	data->mlx.img.data = (int *)mlx_get_data_addr(data->mlx.img.pointer,
			&data->mlx.img.bits_per_pixel, &data->mlx.img.line_lenght,
			&data->mlx.img.endian);
	data->mlx.window = NULL;
	return ;
}

void	init_tex_parameters(t_data *data)
{
	int	i;
	int	j;

	clean_buf_with_zero(&data->ray);
	data->ray.texture = (int **)malloc(sizeof(int *) * NB_OF_TEXTURES);
	i = -1;
	while (++i < NB_OF_TEXTURES)
	{
		data->ray.texture[i] = (int *)malloc(sizeof(int)
				* (TEX_HEIGHT * TEX_WIDTH));
		j = -1;
		while (++j < TEX_HEIGHT * TEX_WIDTH)
			data->ray.texture[i][j] = 0;
	}
}

void	init_ray_parameters(t_data *data)
{
	data->ray.pos_x = data->map_data.starting_position.line;
	data->ray.pos_y = data->map_data.starting_position.col;
	data->map_data.floor_colour_hex = encode_rgb_to_hex
		(data->map_data.colours_rgb[FLOOR][R_VALUE],
			data->map_data.colours_rgb[FLOOR][G_VALUE],
			data->map_data.colours_rgb[FLOOR][B_VALUE]);
	data->map_data.ceiling_colour_hex = encode_rgb_to_hex
		(data->map_data.colours_rgb[CEILING][R_VALUE],
			data->map_data.colours_rgb[CEILING][G_VALUE],
			data->map_data.colours_rgb[CEILING][B_VALUE]);
	set_facing_direction_vector(data);
	set_camera_plane_vector(data);
	data->ray.re_buf = 0;
	data->ray.hit = 0;
	data->ray.move_speed = 0.1;
	data->ray.rot_speed = 0.05;
}

void	init_map_data(t_map_data *map_parameters)
{
	map_parameters->colours_rgb[FLOOR][0] = -42;
	map_parameters->colours_rgb[FLOOR][1] = -42;
	map_parameters->colours_rgb[FLOOR][2] = -42;
	map_parameters->colours_rgb[CEILING][0] = -42;
	map_parameters->colours_rgb[CEILING][1] = -42;
	map_parameters->colours_rgb[CEILING][2] = -42;
	map_parameters->input_fd = 0;
	map_parameters->params_count = 0;
	map_parameters->finished_reading_file = false;
}

void	null_mallocable_pointers(t_data *data)
{
	data->map_data.line = NULL;
	data->map_data.map = NULL;
	data->ray.texture = NULL;
	data->mlx.pointer = NULL;
	data->mlx.window = NULL;
	data->map_data.texture_paths[NO] = NULL;
	data->map_data.texture_paths[SO] = NULL;
	data->map_data.texture_paths[EA] = NULL;
	data->map_data.texture_paths[WE] = NULL;
}
