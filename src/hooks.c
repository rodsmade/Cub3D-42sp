/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:13:38 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/02 02:13:43 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx.window, 17, 0L, destroy, data);
	mlx_hook(data->mlx.window, 3, 1L << 1, keystrokes_management, data);
	mlx_loop_hook(data->mlx.pointer, &raycasting, data);
	return ;
}
