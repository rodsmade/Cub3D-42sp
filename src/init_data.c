/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/10 17:31:06 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_tex_parameters(t_mlx_struct *mlx, int i, int j)
{
	clean_buf_with_zero(mlx, 0);
	mlx->ray->texture = (int **)malloc(sizeof(int *) * 8);
	i = 0;
	while (i < 8)
	{
		j = 0;
		mlx->ray->texture[i] = (int *)malloc(sizeof(int)
				* (TEX_HEIGHT * TEX_WIDTH));
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			mlx->ray->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	init_ray_parameters(t_mlx_struct *mlx)
{
	mlx->img = malloc(sizeof(t_mlx_img));
	mlx->ray = malloc(sizeof(t_ray));
	mlx->ray->pos_x = 22;
	mlx->ray->pos_y = 11.5;
	mlx->ray->dir_x = -1;
	mlx->ray->dir_y = 0;
	mlx->ray->plane_x = 0;
	mlx->ray->plane_y = 0.66;
	mlx->ray->re_buf = 0;
	mlx->ray->hit = 0;
	mlx->ray->move_speed = 0.05;
	mlx->ray->rot_speed = 0.05;
	init_tex_parameters(mlx, 0, 0);
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
