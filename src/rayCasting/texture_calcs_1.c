/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calcs_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:42:40 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/10 17:40:59 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	wall_x_calc(t_mlx_struct *mlx)
{
	double	wall_x;

	if (mlx->ray->side == 0)
		wall_x = mlx->ray->pos_y + mlx->ray->perp_wall_dist
			* mlx->ray->ray_dir_y;
	else
		wall_x = mlx->ray->pos_x + mlx->ray->perp_wall_dist
			* mlx->ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	take_x_coord_on_texture(t_mlx_struct *mlx)
{
	int	tex_x;

	tex_x = (int)(mlx->ray->wall_x * (double)TEX_WIDTH);
	if (mlx->ray->side == 0 && mlx->ray->ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (mlx->ray->side == 1 && mlx->ray->ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	return (tex_x);
}

double	pixel_perscreen(t_mlx_struct *mlx)
{
	double	step;

	step = 1.0 * TEX_HEIGHT / mlx->ray->line_height;
	return (step);
}
