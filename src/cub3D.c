/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/18 16:19:57 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_mlx_struct			mlx;
	t_data					data;
	static t_map_parameters	map_params;
	int						input_fd;

	validate_args(argc, argv, &input_fd, &map_params);
	validate_input_file(input_fd, &map_params);
	mlx.pointer = mlx_init();
	window(&mlx);

	// start data content
	data.mlx = malloc(sizeof(t_mlx_struct));
	data.mlx = malloc(sizeof(t_map_parameters));
	data.posX = 2;
	data.posY = 2;
	data.dirX = -1;
	data.dirY = 0;
	data.planeX = 0;
	data.planeY = 0.66;
	data.moveSpeed = 0.05;
	data.rotSpeed = 0.05;

	mlx_loop_hook(mlx.pointer, &raycasting, &data);
	mlx_loop(mlx.pointer);
	return (0);
}
