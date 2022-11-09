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
	mlx_loop_end(data->mlx_struct.pointer);
	mlx_clear_window(data->mlx_struct.pointer, data->mlx_struct.window);
	mlx_destroy_window(data->mlx_struct.pointer, data->mlx_struct.window);
	mlx_destroy_display(data->mlx_struct.pointer);
	free(data->mlx_struct.pointer);
	free_data(data);
	exit (0);
}
