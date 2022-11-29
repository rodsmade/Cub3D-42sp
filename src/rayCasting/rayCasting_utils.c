/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rayCasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:56:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/28 22:17:08 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	take_tex_num(t_mlx_struct *mlx)
{
	if (mlx->ray->side == 0 && mlx->ray->ray_dir_x < 0)
		return (1);
	else if(mlx->ray->side == 0 && mlx->ray->ray_dir_x >= 0)
		return (2);
	else if(mlx->ray->side == 1 && mlx->ray->ray_dir_y < 0)
		return (3);
	else if (mlx->ray->side == 1 && mlx->ray->ray_dir_y >= 0)
		return (4);
	return(0);
}

void	clean_buf_with_zero(t_mlx_struct *mlx, int x)
{
	int	y;

	while (x < HEIGHT)
	{
		y = 0;
		while (y < WIDTH)
		{
			mlx->ray->buf[x][y] = 0;
			y++;
		}
		x++;
	}
}
