/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:54:10 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/10 17:50:07 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initial_calculation(t_mlx_struct *mlx, int x)
{
	mlx->ray->camera_x = 2 * x / (double)WIDTH - 1;
	mlx->ray->ray_dir_x = mlx->ray->dir_x
		+ mlx->ray->plane_x * mlx->ray->camera_x;
	mlx->ray->ray_dir_y = mlx->ray->dir_y
		+ mlx->ray->plane_y * mlx->ray->camera_x;
	mlx->ray->map_x = (int)mlx->ray->pos_x;
	mlx->ray->map_y = (int)mlx->ray->pos_y;
	mlx->ray->delta_dist_x = fabs(1 / mlx->ray->ray_dir_x);
	mlx->ray->delta_dist_y = fabs(1 / mlx->ray->ray_dir_y);
	mlx->ray->hit = 0;
}
