/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:42:40 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/02 10:36:51 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	load_texture(t_data *data, int direction)
{
	int			i;
	int			j;
	t_mlx_img	img;

	i = 0;
	img.pointer = mlx_xpm_file_to_image(data->mlx.pointer,
			data->map_data.texture_paths[direction],
			&img.img_width, &img.img_height);
	img.data = (int *)mlx_get_data_addr(img.pointer,
			&img.bits_per_pixel, &img.line_lenght, &img.endian);
	while (i < img.img_height)
	{
		j = 0;
		while (j < img.img_width)
		{
			data->ray.texture[direction][img.img_width * i + j]
				= img.data[img.img_width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx.pointer, img.pointer);
}

void	load_textures(t_data *data)
{
	load_texture(data, NO);
	load_texture(data, SO);
	load_texture(data, EA);
	load_texture(data, WE);
}
