/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:18:46 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/02 00:57:19 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	rotate_camera_direction(double old_dir_x, t_data *data, char dir)
{
	if (dir == 'R')
	{
		data->ray.dir_x = data->ray.dir_x * cos(-data->ray.rot_speed)
			- data->ray.dir_y * sin(-data->ray.rot_speed);
		data->ray.dir_y = old_dir_x * sin(-data->ray.rot_speed)
			+ data->ray.dir_y * cos(-data->ray.rot_speed);
	}
	if (dir == 'L')
	{
		data->ray.dir_x = data->ray.dir_x * cos(data->ray.rot_speed)
			- data->ray.dir_y * sin(data->ray.rot_speed);
		data->ray.dir_y = old_dir_x * sin(data->ray.rot_speed)
			+ data->ray.dir_y * cos(data->ray.rot_speed);
	}
}

static void	rotate_camera_plane(double old_plane_x, t_data *data, char dir)
{
	if (dir == 'R')
	{
		data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rot_speed)
			- data->ray.plane_y * sin(-data->ray.rot_speed);
		data->ray.plane_y = old_plane_x * sin(-data->ray.rot_speed)
			+ data->ray.plane_y * cos(-data->ray.rot_speed);
	}
	if (dir == 'L')
	{
		data->ray.plane_x = data->ray.plane_x * cos(data->ray.rot_speed)
			- data->ray.plane_y * sin(data->ray.rot_speed);
		data->ray.plane_y = old_plane_x * sin(data->ray.rot_speed)
			+ data->ray.plane_y * cos(data->ray.rot_speed);
	}
}

void	rotate_view(int keycode, t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (keycode == XK_Right)
	{
		old_dir_x = data->ray.dir_x;
		rotate_camera_direction(old_dir_x, data, 'R');
		old_plane_x = data->ray.plane_x;
		rotate_camera_plane(old_plane_x, data, 'R');
	}
	if (keycode == XK_Left)
	{
		old_dir_x = data->ray.dir_x;
		rotate_camera_direction(old_dir_x, data, 'L');
		old_plane_x = data->ray.plane_x;
		rotate_camera_plane(old_plane_x, data, 'L');
	}
}
