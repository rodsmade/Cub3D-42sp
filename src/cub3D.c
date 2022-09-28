/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/27 12:29:32 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_mlx_struct			mlx;
	static t_map_parameters	map_params;
	int						input_fd;

	validate_args(argc, argv, &input_fd, &map_params);
	validate_input_file(input_fd, &map_params);
	mlx.pointer = mlx_init();
	window(&mlx);
	mlx_loop(mlx.pointer);
	return (0);
}
