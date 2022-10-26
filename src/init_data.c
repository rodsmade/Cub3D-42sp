/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/26 15:45:50 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_tex_parameters(t_ray *ray)
{
	int	i;
	int	j;

	i = -1;
	ray->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	while (++i < HEIGHT)
		ray->buf[i] = (int *)malloc(sizeof(int) * WIDTH);
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < TEX_HEIGHT * TEX_WIDTH )
		{
			ray->buf[i][j] = 0;
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
	ray->mlx->pointer = mlx->pointer;
	ray->mlx->window = mlx->window;
	init_tex_parameters(ray);
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
