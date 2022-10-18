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

// static int	put_test_image(t_mlx_struct *mlx)
// {
// 	mlx_put_image_to_window(mlx->pointer, mlx->window,
// 		mlx->img->pointer, 250, 250);
// 	return (0);
// }

// static void	image_test(t_mlx_struct *mlx)
// {
// 	int	x;
// 	int	y;

// 	mlx->img = malloc(sizeof(t_mlx_img));
// 	x = 32;
// 	y = 32;
// 	mlx->img->pointer = mlx_xpm_file_to_image
// 		(mlx->pointer, IMG_TEST, &x, &y);
// 	mlx_loop_hook(mlx->pointer, put_test_image, mlx);
// }

void	window(t_mlx_struct *mlx)
{
	mlx->window = mlx_new_window(mlx->pointer, WIDTH, HEIGHT, "cub3D");
	// image_test(mlx);
	// mlx_hook(mlx->window, 17, 0L, destroy, mlx);
	// mlx_hook(mlx->window, 3, 1L << 1, keystrokes_management, mlx);
}
