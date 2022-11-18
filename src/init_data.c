/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/18 12:13:04 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	set_facing_direction_vector(t_data *data)
{
	if (data->map_data.starting_pos_char == 'N')
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
	}
	if (data->map_data.starting_pos_char == 'S')
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
	}
	if (data->map_data.starting_pos_char == 'E')
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = 1;
	}
	if (data->map_data.starting_pos_char == 'W')
	{
		data->ray.dir_x = 0;
		data->ray.dir_y = -1;
	}
}

void	set_camera_plane_vector(t_data *data)
{
	if (data->map_data.starting_pos_char == 'N')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = 0.66;
	}
	if (data->map_data.starting_pos_char == 'S')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = -0.33;
	}
	if (data->map_data.starting_pos_char == 'E')
	{
		data->ray.plane_x = 0.33;
		data->ray.plane_y = 0;
	}
	if (data->map_data.starting_pos_char == 'W')
	{
		data->ray.plane_x = -0.66;
		data->ray.plane_y = 0;
	}
}

void	init_ray_parameters(t_data *data)
{
	data->ray.pos_x = 5; // linkar com validacao do mapa dps
	data->ray.pos_y = 10.5; // linkar com validacao do mapa dps
	data->map_data.starting_pos_char = 'W'; // linkar com validacao do mapa dps
	data->map_data.floor_colour_hex = 0xFF4F79; // linkar com validacao do mapa dps
	data->map_data.ceiling_colour_hex = 0xA11692; // linkar com validacao do mapa dps
	set_facing_direction_vector(data);
	set_camera_plane_vector(data);
	data->ray.re_buf = 0;
	data->ray.hit = 0;
	data->ray.move_speed = 0.1;
	data->ray.rot_speed = 0.05;
}

void	init_map_data(t_map_data *map_parameters)
{
	map_parameters->fds[NO] = -42;
	map_parameters->fds[SO] = -42;
	map_parameters->fds[EA] = -42;
	map_parameters->fds[WE] = -42;
	map_parameters->colours[FLOOR][0] = -42;
	map_parameters->colours[FLOOR][1] = -42;
	map_parameters->colours[FLOOR][2] = -42;
	map_parameters->colours[CEILING][0] = -42;
	map_parameters->colours[CEILING][1] = -42;
	map_parameters->colours[CEILING][2] = -42;
	map_parameters->params_count = 0;
	map_parameters->line = NULL;
}
