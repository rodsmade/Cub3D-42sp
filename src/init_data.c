/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/25 00:47:42 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray_parameters(t_ray *ray, t_mlx_struct *mlx)
{
	// start ray content
	ray->pos_x = 12; 		// start position
	ray->pos_y = 5;			// start position
	ray->dir_x = -1;			// initial direction vector
	ray->dir_y = 0;			// initial direction vector
	ray->plane_x = 0;		// camera plane
	ray->plane_y = 0.66;		// camera plane iss 66º
	ray->move_speed = 0.05;
	ray->rot_speed = 0.05;
	ray->hit = 0;
	ray->mlx->pointer = mlx->pointer;
	ray->mlx->window = mlx->window;
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
