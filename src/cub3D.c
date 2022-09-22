/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/21 20:39:02 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	// t_mlx_struct	mlx;
	int				input_fd;

	validate_args(argc, argv, &input_fd);
	validate_input_file(input_fd);
	// mlx.pointer = mlx_init();
	// window(&mlx);
	// mlx_loop(mlx.pointer);
	return (0);
}
