/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:13:38 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/17 17:03:21 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_hooks(t_data *data)
{
	mlx_hook(data->mlx.window, 17, 0L, destroy, data);
	mlx_hook(data->mlx.window, 3, 1L << 1, keystrokes_management, data);
	mlx_loop_hook(data->mlx.ptr, &raycasting, data);
	return ;
}