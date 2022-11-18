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

static	void	init_img(t_data *data)
{
	data->mlx.img->pointer = mlx_new_image(data->mlx.pointer, WIDTH, HEIGHT);
	data->mlx.img->data = (int *)mlx_get_data_addr(data->mlx.img->pointer,
			&data->mlx.img->bits_per_pixel, &data->mlx.img->line_lenght,
			&data->mlx.img->endian);
}

void	open_window(t_data *data)
{
	data->mlx.window = mlx_new_window(data->mlx.pointer, WIDTH,
			HEIGHT, "cub3D");
	init_img(data);
	mlx_hook(data->mlx.window, 17, 0L, destroy, data);
	mlx_hook(data->mlx.window, 3, 1L << 1, keystrokes_management, data);
}
