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

static	void	init_img(t_mlx_struct *mlx)
{
	mlx->img->pointer = mlx_new_image(mlx->pointer, WIDTH, HEIGHT);
	mlx->img->data = (int *)mlx_get_data_addr(mlx->img->pointer,
		&mlx->img->bits_per_pixel, &mlx->img->line_lenght,
		&mlx->img->endian);
}

void	window(t_mlx_struct *mlx)
{
	mlx->window = mlx_new_window(mlx->pointer, WIDTH, HEIGHT, "cub3D");
	mlx->img = malloc(sizeof(t_mlx_struct));
	init_img(mlx);
	mlx_hook(mlx->window, 17, 0L, destroy, mlx);
	mlx_hook(mlx->window, 3, 1L << 1, keystrokes_management, mlx);
}
