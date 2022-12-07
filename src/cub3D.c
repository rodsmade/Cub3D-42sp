/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/07 23:18:39 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_data *data)
{
	null_mallocable_pointers(data);
	// init_mlx_struct(data);
	init_map_data(&data->map_data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	// printf("DEBUG: vai pra init_data\n");
	init_data(&data);
	// printf("DEBUG: passou da init_data\n");
	// printf("DEBUG: vai pra validate_args\n");
	validate_args(argc, argv, &data);
	// printf("DEBUG: passou da validate_args\n");
	// printf("DEBUG: vai pra validate_input_file\n");
	validate_input_file(&data);
	// printf("DEBUG: passou da validate_input_file\n");
	// printf("DEBUG: vai pra init_ray_parameters\n");
	printf("MAPA TA OK\n");
	init_ray_parameters(&data);
	// printf("DEBUG: passou da init_ray_parameters\n");
	// printf("DEBUG: vai pra init_tex_parameters\n");
	init_tex_parameters(&data);
	// printf("DEBUG: passou da init_tex_parameters\n");
	// printf("DEBUG: vai pra load_textures\n");
	load_textures(&data);
	// printf("DEBUG: passou da load_textures\n");
	// printf("DEBUG: vai pra open_window\n");
	open_window(&data);
	// printf("DEBUG: passou da open_window\n");
	// printf("DEBUG: vai pra set_hooks\n");
	set_hooks(&data);
	// printf("DEBUG: passou da set_hooks\n");
	mlx_loop(data.mlx.pointer);
	return (0);
}
