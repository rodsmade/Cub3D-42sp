/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/08 19:45:13 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void	paint_floor_and_ceiling(t_data *data)
{
	int	i;
	int	j;

	if (!data->mlx_struct.window)
		return ;
	i = -1;
	while (++i < WIDTH)
	{
		j = -1;
		while (++j < HEIGHT)
		{
			if (j < HEIGHT / 2)
				mlx_pixel_put(data->mlx_struct.pointer, data->mlx_struct.window,
								i, j,
								encode_rgb(data->colours[CEILING][R_VALUE],
									data->colours[CEILING][G_VALUE],
									data->colours[CEILING][B_VALUE]));
			else
				mlx_pixel_put(data->mlx_struct.pointer, data->mlx_struct.window,
								i, j,
								encode_rgb(data->colours[FLOOR][R_VALUE],
									data->colours[FLOOR][G_VALUE],
									data->colours[FLOOR][B_VALUE]));
		}
	}
}

void	initialise_minilibx(t_data *data)
{
	data->mlx_struct.pointer = mlx_init();
	if (data->mlx_struct.pointer == NULL)
		print_err_exit(MLX_ERROR, data);
	return ;
}

int	main(int argc, char **argv)
/*
	- [x] integrar whichever data structure dele com minha
	- [x] trazer código do raycasting praqui
	- [x] integrar código do raycasting aqui - ok, mas ñ tô usando ainda.
	- [x] copiar estrutura da main do so long pra cá
	- [x] alterar a cor do céu e do chão
	------------------------
	- [ ] entender +- o raycasting codado
	- [ ] como parametrizar pra entrar numa posição específica?
	- [ ] como parametrizar pra olhar pra uma direção específica?
	- [ ] como mexer a câmera?
	- [ ] como andar?
*/
{
	t_data				data;

	init_data(&data);
	validate_args(argc, argv, &data);
	validate_input_file(&data);
	initialise_minilibx(&data);
	open_window(&data);
	paint_floor_and_ceiling(&data);
	set_hooks(&data);
	// init_raycasting_parameters(&data);
	// raycasting(&ray);
	mlx_loop(data.mlx_struct.pointer);
	free_data(&data);
	return (0);
}
