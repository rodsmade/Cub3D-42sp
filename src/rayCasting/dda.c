/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:15:26 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/15 11:32:09 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calc_ray_side_distance_and_next_block_step(t_mlx_struct *mlx)
{
	if (mlx->ray->ray_dir_x < 0)
	{
		mlx->ray->step_x = -1;
		mlx->ray->side_dist_x = (mlx->ray->pos_x
				- mlx->ray->map_x) * mlx->ray->delta_dist_x;
	}
	else
	{
		mlx->ray->step_x = 1;
		mlx->ray->side_dist_x = (mlx->ray->map_x
				+ 1.0 - mlx->ray->pos_x) * mlx->ray->delta_dist_x;
	}
	if (mlx->ray->ray_dir_y < 0)
	{
		mlx->ray->step_y = -1;
		mlx->ray->side_dist_y = (mlx->ray->pos_y
				- mlx->ray->map_y) * mlx->ray->delta_dist_y;
	}
	else
	{
		mlx->ray->step_y = 1;
		mlx->ray->side_dist_y = (mlx->ray->map_y
				+ 1.0 - mlx->ray->pos_y) * mlx->ray->delta_dist_y;
	}
}

void	calc_perp_wall_dist_from_camera_plane(t_mlx_struct *mlx)
{
	if (mlx->ray->side == 0)
		mlx->ray->perp_wall_dist = (mlx->ray->map_x
				- mlx->ray->pos_x + (1 - mlx->ray->step_x)
				/ 2) / mlx->ray->ray_dir_x;
	else
		mlx->ray->perp_wall_dist = (mlx->ray->map_y
				- mlx->ray->pos_y + (1 - mlx->ray->step_y)
				/ 2) / mlx->ray->ray_dir_y;
}

void	dda_loop_with_check_hit(t_mlx_struct *mlx)
{
	while (mlx->ray->hit == 0)
	{
		if (mlx->ray->side_dist_x < mlx->ray->side_dist_y)
		{
			mlx->ray->side_dist_x += mlx->ray->delta_dist_x;
			mlx->ray->map_x += mlx->ray->step_x;
			mlx->ray->side = 0;
		}
		else
		{
			mlx->ray->side_dist_y += mlx->ray->delta_dist_y;
			mlx->ray->map_y += mlx->ray->step_y;
			mlx->ray->side = 1;
		}
		if (world_map_char[mlx->ray->map_x][mlx->ray->map_y] > '0')
			mlx->ray->hit = 1;
	}
}
