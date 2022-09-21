/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 09:43:56 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/21 11:02:29 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	my_mlx_pixel_put(t_mlx_struct *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img->addr + (y * mlx->img->line_lenght + x
			* (mlx->img->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}

static void	image(t_mlx_struct *mlx)
{
	mlx->img->pointer = mlx_new_image(mlx->pointer, 200, 200);
	mlx->img->addr = mlx_get_data_addr(mlx->img->pointer,
			&mlx->img->bits_per_pixel,
			&mlx->img->line_lenght, &mlx->img->endian);
	my_mlx_pixel_put(mlx, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx->pointer, mlx->window,
		mlx->img->pointer, 0, 0);
}

void	window(t_mlx_struct *mlx)
{
	mlx->window = mlx_new_window(mlx->pointer, 500, 720, "cub3D");
	image(mlx);
	mlx_hook(mlx->window, 17, 0L, destroy, mlx);
	mlx_hook(mlx->window, 3, 1L << 1, keystrokes_management, mlx);
}
