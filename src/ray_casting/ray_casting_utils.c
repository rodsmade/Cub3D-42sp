/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:56:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/18 11:28:57 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	take_tex_num(t_data *data)
{
	if (data->ray.side == 0 && data->ray.ray_dir_x < 0)
		return (1);
	else if(data->ray.side == 0 && data->ray.ray_dir_x >= 0)
		return (2);
	else if(data->ray.side == 1 && data->ray.ray_dir_y < 0)
		return (3);
	else if (data->ray.side == 1 && data->ray.ray_dir_y >= 0)
		return (4);
	return(0);
}

void	clean_buf_with_zero(t_ray *ray)
{
	int	x;
	int	y;

	x = -1;
	while (++x < HEIGHT)
	{
		y = -1;
		while (++y < WIDTH)
			ray->buf[x][y] = 0;
	}
}
