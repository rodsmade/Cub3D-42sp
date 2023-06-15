/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:13:38 by roaraujo          #+#    #+#             */
/*   Updated: 2023/06/14 22:15:44 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx.window, DestroyNotify, NoEventMask, destroy, data);
	mlx_hook(data->mlx.window, KeyPress, KeyPressMask, \
											keystrokes_management, data);
	mlx_loop_hook(data->mlx.pointer, &raycasting, data);
	return ;
}
