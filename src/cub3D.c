/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/01 10:46:49 by roaraujo         ###   ########.fr       */
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

void	null_mallocable_pointers(t_data *data)
{
	data->map_data.line = NULL;
	data->ray.texture = NULL;
	data->mlx.pointer = NULL;
	data->mlx.window = NULL;
}

void	init_data(t_data *data)
{
	null_mallocable_pointers(data);
	init_mlx_struct(data);
	init_map_data(&data->map_data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	validate_args(argc, argv, &data);
	validate_input_file(&data);
	init_ray_parameters(&data);
	init_tex_parameters(&data);
	load_textures(&data);
	open_window(&data);
	set_hooks(&data);
	mlx_loop(data.mlx.pointer);
	return (0);
}
