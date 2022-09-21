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

void	window(t_mlx_struct *mlx)
{
	mlx->window = mlx_new_window(mlx->pointer, 300, 300, "cub3D");
	mlx_hook(mlx->window, 17, 0L, destroy, mlx);
	mlx_hook(mlx->window, 3, 1L << 1, keystrokes_management, mlx);
}
