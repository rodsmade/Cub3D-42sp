/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/26 16:37:22 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	put_tex_in_matrix(t_ray *ray, int x, int y)
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

static void	init_tex_parameters(t_ray *ray, int i, int j)
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

void	init_ray_parameters(t_ray *ray, t_mlx_struct *mlx)
{
	ray->pos_x = 22;
	ray->pos_y = 11.5;
	ray->dir_x = -1;
	ray->dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0.66;
	ray->move_speed = 0.05;
	ray->rot_speed = 0.05;
	ray->hit = 0;
	ray->mlx = mlx;
	init_tex_parameters(ray, 0, 0);
	put_tex_in_matrix(ray, 0, 0);
}

void	init_map_parameters(t_map_parameters *map_parameters)
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
