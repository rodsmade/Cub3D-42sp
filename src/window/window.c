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

static void	image(t_mlx_struct *mlx)
{
	int x;
	int y;

	mlx->img = malloc(sizeof(t_mlx_img));
	x = 0;
	y = 0;
	mlx->img->pointer = mlx_xpm_file_to_image
		(mlx->pointer, IMG_TEST, &x, &y);
	while (x < 150) 
	{
		while (y < 150)
		{
			mlx_put_image_to_window(mlx->pointer, mlx->window, mlx->img->pointer, x, y);
			y++;
		}
		x++;
	}
}

void	window(t_mlx_struct *mlx)
{
	mlx->window = mlx_new_window(mlx->pointer, 150, 150, "cub3D");
	image(mlx);
	mlx_hook(mlx->window, 17, 0L, destroy, mlx);
	mlx_hook(mlx->window, 3, 1L << 1, keystrokes_management, mlx);
}
