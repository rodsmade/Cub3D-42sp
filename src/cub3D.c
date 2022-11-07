/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/07 12:33:05 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	// t_mlx_struct		mlx;
	t_data				data;

	init_data(&data);
	validate_args(argc, argv, &data);
	validate_input_file(&data);
	// mlx.pointer = mlx_init();
	// window(&mlx);
	// mlx_loop(mlx.pointer);
	free_data(&data);
	return (0);
}
