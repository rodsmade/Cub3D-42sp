/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 22:39:13 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/11 19:17:17 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_facing_direction_vector(t_data *data)
{
	if (data->map_data.starting_pos_char == 'N')
	{
		data->ray.dir_x = -1;
		data->ray.dir_y = 0;
	}
	if (data->map_data.starting_pos_char == 'E')
	{
		data->ray.dir_x = 1;
		data->ray.dir_y = 0;
	}
	if (data->map_data.starting_pos_char == 'S')
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
	if (data->map_data.starting_pos_char == 'E')
	{
		data->ray.plane_x = 0;
		data->ray.plane_y = -0.33;
	}
	if (data->map_data.starting_pos_char == 'S')
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
