/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 02:09:53 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/02 02:11:15 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->mlx.img.data[i * WIDTH + j] = data->ray.buf[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.pointer,
		data->mlx.window, data->mlx.img.pointer, 0, 0);
}

int	raycasting(t_data *data)
{
	calc_raycasting(data, 0);
	render(data);
	return (0);
}
