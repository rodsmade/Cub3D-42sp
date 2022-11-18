/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:13:53 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/18 11:45:29 by roaraujo         ###   ########.fr       */
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
			data->mlx.img->data[i * WIDTH + j] = data->ray.buf[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.pointer, data->mlx.window, data->mlx.img->pointer, 0, 0);
}

int	raycasting(t_data *data)
{
	calc_raycasting(data, 0);
	render(data);
	return (0);
}
