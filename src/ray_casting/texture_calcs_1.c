/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calcs_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:42:40 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/18 11:46:48 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	wall_x_calc(t_data *data)
{
	double	wall_x;

	if (data->ray.side == 0)
		wall_x = data->ray.pos_y + data->ray.perp_wall_dist
			* data->ray.ray_dir_y;
	else
		wall_x = data->ray.pos_x + data->ray.perp_wall_dist
			* data->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	take_x_coord_on_texture(t_data *data)
{
	int	tex_x;

	tex_x = (int)(data->ray.wall_x * (double)TEX_WIDTH);
	if (data->ray.side == 0 && data->ray.ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (data->ray.side == 1 && data->ray.ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	return (tex_x);
}

double	pixel_perscreen(t_data *data)
{
	double	step;

	step = 1.0 * TEX_HEIGHT / data->ray.line_height;
	return (step);
}
