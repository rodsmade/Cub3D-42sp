/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:13:53 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/10 17:53:28 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render(t_mlx_struct *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx->img->data[i * WIDTH + j] = mlx->ray->buf[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->pointer, mlx->window, mlx->img->pointer, 0, 0);
}

int	raycasting(t_mlx_struct *mlx)
{
	calc_raycasting(mlx, 0);
	render(mlx);
	return (0);
}
