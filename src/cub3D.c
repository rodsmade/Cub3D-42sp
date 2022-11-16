/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/16 17:14:16 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char    world_map_char[24][24] =    {
  "111111111111111111111111",
  "100000000000000010000001",
  "100000000010000010000001",
  "100000000000000010000001",
  "100000000000000000000001",
  "100000000000000000000001",
  "100000000000110000010001",
  "111111111111111111111111"
};

int	main(int argc, char **argv)
{
	int						input_fd;
	t_mlx_struct			mlx;
	static t_map_parameters	map_params;

	mlx.pointer = mlx_init();
	validate_args(argc, argv, &input_fd, &map_params);
	validate_input_file(input_fd, &map_params);
	init_ray_parameters(&mlx);
	load_texture(&mlx);
	window(&mlx);
	mlx_loop_hook(mlx.pointer, &raycasting, &mlx);
	mlx_loop(mlx.pointer);
	return (0);
}
