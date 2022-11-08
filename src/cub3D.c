/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/08 16:47:09 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initialise_minilibx(t_data *data)
{
	data->mlx_struct.pointer = mlx_init();
	if (data->mlx_struct.pointer == NULL)
		print_err_exit(MLX_ERROR, data);
	return ;
}

int	main(int argc, char **argv)
/*
	- [] integrar whichever data structure dele com minha
	- [] integrar código do raycasting aqui
	- [] copiar estrutura da main do so long pra cá
	- [] alterar a cor do céu e do chão
*/
{
	// t_ray				ray;
	t_data				data;

	init_data(&data);
	validate_args(argc, argv, &data);
	validate_input_file(&data);
	initialise_minilibx(&data);
	window(&data.mlx_struct);
	// init_ray_parameters(&ray, &(data.mlx_struct), &data);
	// raycasting(&ray);
	mlx_loop(data.mlx_struct.pointer);
	free_data(&data);
	return (0);
}
