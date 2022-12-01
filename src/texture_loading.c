/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:42:40 by gusalves          #+#    #+#             */
/*   Updated: 2022/12/01 16:01:15 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	load_image(t_data *data, int *texture, char *path)
{
	int			i;
	int			j;
	t_mlx_img	img;

	i = 0;
	img.pointer = mlx_xpm_file_to_image(data->mlx.pointer, path,
			&img.img_width, &img.img_height);
	img.data = (int *)mlx_get_data_addr(img.pointer,
			&img.bits_per_pixel, &img.line_lenght, &img.endian);
	while (i < img.img_height)
	{
		j = 0;
		while (j < img.img_width)
		{
			texture[img.img_width * i + j]
				= img.data[img.img_width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx.pointer, img.pointer);
}

void	load_textures(t_data *data)
{
	load_image(data, data->ray.texture[NO], "./assets/textures/bluestone.xpm");
	load_image(data, data->ray.texture[SO], "./assets/textures/redbrick.xpm");
	load_image(data, data->ray.texture[EA], "./assets/textures/purplestone.xpm");
	load_image(data, data->ray.texture[WE], "./assets/textures/greystone.xpm");
}
