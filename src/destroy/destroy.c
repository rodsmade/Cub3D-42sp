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

int	destroy(t_data *data)
{
	printf("Closing the game...\n");
	mlx_loop_end(data->mlx.pointer);
	mlx_clear_window(data->mlx.pointer, data->mlx.window);
	mlx_destroy_image(data->mlx.pointer, data->mlx.img->pointer);
	mlx_destroy_window(data->mlx.pointer, data->mlx.window);
	mlx_destroy_display(data->mlx.pointer);
	free(data->mlx.pointer);
	free_data(data);
	exit (42);
}
