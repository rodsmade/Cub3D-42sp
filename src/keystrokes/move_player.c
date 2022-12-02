/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 01:28:15 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/02 02:02:50 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	move_right_or_left(t_data *data, char side)
{
	if (side == 'R')
	{
		if (data->map_data.map[(int)(data->ray.pos_x
				+ data->ray.dir_y * data->ray.move_speed)]
				[(int)data->ray.pos_y] == '0')
			data->ray.pos_x += data->ray.dir_y * data->ray.move_speed;
		if (data->map_data.map[(int)data->ray.pos_x]
			[(int)(data->ray.pos_y - data->ray.dir_x
				* data->ray.move_speed)] == '0')
			data->ray.pos_y -= data->ray.dir_x * data->ray.move_speed;
	}
	if (side == 'L')
	{
		if (data->map_data.map[(int)(data->ray.pos_x
				- data->ray.dir_y * data->ray.move_speed)]
				[(int)data->ray.pos_y] == '0')
			data->ray.pos_x -= data->ray.dir_y * data->ray.move_speed;
		if (data->map_data.map[(int)data->ray.pos_x]
			[(int)(data->ray.pos_y + data->ray.dir_x
				* data->ray.move_speed)] == '0')
			data->ray.pos_y += data->ray.dir_x * data->ray.move_speed;
	}
}

static void	move_front_or_back(t_data *data, char side)
{
	if (side == 'F')
	{
		if (data->map_data.map[(int)(data->ray.pos_x
				+ data->ray.dir_x * data->ray.move_speed)]
				[(int)data->ray.pos_y] == '0')
			data->ray.pos_x += data->ray.dir_x * data->ray.move_speed;
		if (data->map_data.map[(int)data->ray.pos_x]
			[(int)(data->ray.pos_y + data->ray.dir_y
				* data->ray.move_speed)] == '0')
			data->ray.pos_y += data->ray.dir_y * data->ray.move_speed;
	}
	if (side == 'B')
	{
		if (data->map_data.map[(int)(data->ray.pos_x
				- data->ray.dir_x * data->ray.move_speed)]
				[(int)data->ray.pos_y] == '0')
			data->ray.pos_x -= data->ray.dir_x * data->ray.move_speed;
		if (data->map_data.map[(int)data->ray.pos_x]
			[(int)(data->ray.pos_y - data->ray.dir_y
				* data->ray.move_speed)] == '0')
			data->ray.pos_y -= data->ray.dir_y * data->ray.move_speed;
	}
}

void	move_player(int keycode, t_data *data)
{
	if (keycode == XK_w)
		move_front_or_back(data, 'F');
	if (keycode == XK_a)
		move_right_or_left(data, 'L');
	if (keycode == XK_s)
		move_front_or_back(data, 'B');
	if (keycode == XK_d)
		move_right_or_left(data, 'R');
}
