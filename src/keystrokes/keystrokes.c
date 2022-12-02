/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keystrokes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:04:38 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/01 18:04:38 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_player(int keycode, t_data *data)
{
	if (keycode == XK_w)
	{
		if(data->map_data.map[(int)(data->ray.pos_x + data->ray.dir_x * data->ray.move_speed)][(int)data->ray.pos_y] == '0')
			data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
		if(data->map_data.map[(int)data->ray.pos_x][(int)(data->ray.pos_y + data->ray.dir_y * data->ray.move_speed)] == '0')
			data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
	}
	if (keycode == XK_s)
	{
		if(data->map_data.map[(int)(data->ray.pos_x - data->ray.dir_x * data->ray.move_speed)][(int)data->ray.pos_y] == '0')
			data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
		if(data->map_data.map[(int)data->ray.pos_x][(int)(data->ray.pos_y - data->ray.dir_y * data->ray.move_speed)] == '0')
			data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
	}
	if (keycode == XK_a)
	{
		if(data->map_data.map[(int)(data->ray.pos_x - data->ray.dir_y * data->ray.move_speed)][(int)data->ray.pos_y] == '0')
			data->ray.pos_x -= data->ray.dir_y * data->ray.move_speed;
		if(data->map_data.map[(int)data->ray.pos_x][(int)(data->ray.pos_y + data->ray.dir_x * data->ray.move_speed)] == '0')
			data->ray.pos_y += data->ray.dir_x * data->ray.move_speed;
	}
	if (keycode == XK_d)
	{
		if(data->map_data.map[(int)(data->ray.pos_x + data->ray.dir_y * data->ray.move_speed)][(int)data->ray.pos_y] == '0')
			data->ray.pos_x += data->ray.dir_y * data->ray.move_speed;
		if(data->map_data.map[(int)data->ray.pos_x][(int)(data->ray.pos_y - data->ray.dir_x * data->ray.move_speed)] == '0')
			data->ray.pos_y -= data->ray.dir_x * data->ray.move_speed;
	}
}

int	keystrokes_management(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		destroy(data);
	if (keycode == XK_Left || keycode == XK_Right)
		rotate_view(keycode, data);
	if (keycode == XK_a || keycode == XK_w
		|| keycode == XK_d || keycode == XK_s)
		move_player(keycode, data);
	return (0);
}
