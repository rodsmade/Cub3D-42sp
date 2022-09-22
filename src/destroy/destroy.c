/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:17:59 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/21 11:12:33 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	destroy(t_mlx_struct *mlx)
{
	printf("Closing the game...\n");
	mlx_loop_end(mlx->pointer);
	mlx_clear_window(mlx->pointer, mlx->window);
	mlx_destroy_image(mlx->pointer, mlx->img->pointer);
	mlx_destroy_window(mlx->pointer, mlx->window);
	mlx_destroy_display(mlx->pointer);
	free(mlx->pointer);
	exit (42);
}
