/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/09 20:17:10 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	put_tex_in_matrix(t_raycasting *ray, int x, int y)
{
	int	xor_color;
	int	y_color;
	int	xy_color;

	while (x < TEX_WIDTH)
	{
		y = 0;
		while (y < TEX_HEIGHT)
		{
			xor_color = (x * 256 / TEX_WIDTH) ^ (y * 256 / TEX_HEIGHT);
			y_color = y * 256 / TEX_HEIGHT;
			xy_color = y * 128 / TEX_HEIGHT + x * 128 / TEX_WIDTH;
			ray->texture[0][TEX_WIDTH * y + x] = 65536 * 254
				* (x != y && x != TEX_WIDTH - y);
			ray->texture[1][TEX_WIDTH * y + x] = xy_color + 256
				* xy_color + 65536 * xy_color;
			ray->texture[2][TEX_WIDTH * y + x] = 256 * xy_color
				+ 65536 * xy_color;
			ray->texture[3][TEX_WIDTH * y + x] = xor_color + 256
				* xor_color + 65536 * xor_color;
			ray->texture[4][TEX_WIDTH * y + x] = 256 * xor_color;
			ray->texture[5][TEX_WIDTH * y + x] = 65536 * 192
				* (x % 16 && y % 16);
			ray->texture[6][TEX_WIDTH * y + x] = 65536 * y_color;
			ray->texture[7][TEX_WIDTH * y + x] = 128 + 256 * 128
				+ 65536 * 128;
			y++;
		}
		x++;
	}
}

static void	init_tex_parameters(t_raycasting *ray, int i, int j)
{
	i = -1;
	ray->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	while (++i < HEIGHT)
		ray->buf[i] = (int *)malloc(sizeof(int) * WIDTH);
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ray->buf[i][j] = 0;
			j++;
		}
		i++;
	}
	while (i < 8)
	{
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			ray->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_raycasting_parameters(t_data *data)
{
	data->raycasting.pos_x = 22;
	data->raycasting.pos_y = 11.5;
	data->raycasting.dir_x = -1;
	data->raycasting.dir_y = 0;
	data->raycasting.plane_x = 0;
	data->raycasting.plane_y = 0.66;
	data->raycasting.move_speed = 0.05;
	data->raycasting.rot_speed = 0.05;
	data->raycasting.hit = 0;
	init_tex_parameters(&data->raycasting, 0, 0);
	put_tex_in_matrix(&data->raycasting, 0, 0);
}

void	init_data(t_data *data)
{
	data->input_fd = -42;
	data->texture_fds[NO] = -42;
	data->texture_fds[SO] = -42;
	data->texture_fds[EA] = -42;
	data->texture_fds[WE] = -42;
	data->colours[FLOOR][0] = -42;
	data->colours[FLOOR][1] = -42;
	data->colours[FLOOR][2] = -42;
	data->colours[CEILING][0] = -42;
	data->colours[CEILING][1] = -42;
	data->colours[CEILING][2] = -42;
	data->params_count = 0;
	data->line = NULL;
	data->map = NULL;
	data->mlx_struct.pointer = NULL;
	data->mlx_struct.img = NULL;
}
