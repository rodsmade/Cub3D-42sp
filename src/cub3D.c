/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/10 22:18:10 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	// t_mlx_struct		mlx;
	t_map_parameters	map_params;

	init_map_parameters(&map_params);
	validate_args(argc, argv, &map_params);
	validate_input_file(&map_params);
	// mlx.pointer = mlx_init();
	// window(&mlx);
	// mlx_loop(mlx.pointer);
	free_map_params(&map_params);
	return (0);
}
