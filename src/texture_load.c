/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_load.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:42:40 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/10 17:51:04 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	load_image(t_mlx_struct *mlx, int *texture,
	char *path, t_mlx_img *img)
{
	int	i;
	int	j;

	i = 0;
	img->pointer = mlx_xpm_file_to_image(mlx->pointer, path,
			&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->pointer,
			&img->bits_per_pixel, &img->line_lenght, &img->endian);
	while (i < img->img_height)
	{
		j = 0;
		while (j < img->img_width)
		{
			texture[img->img_width * i + j]
				= img->data[img->img_width * i + j];
			j++;
		}
		i++;
	}
	mlx_destroy_image(mlx->pointer, img->pointer);
}

void	load_texture(t_mlx_struct *mlx)
{
	t_mlx_img	img;

	load_image(mlx, mlx->ray->texture[0], "./textures/eagle.xpm", &img);
	load_image(mlx, mlx->ray->texture[1], "./textures/redbrick.xpm", &img);
	load_image(mlx, mlx->ray->texture[2], "./textures/purplestone.xpm", &img);
	load_image(mlx, mlx->ray->texture[3], "./textures/greystone.xpm", &img);
	load_image(mlx, mlx->ray->texture[4], "./textures/bluestone.xpm", &img);
	load_image(mlx, mlx->ray->texture[5], "./textures/mossy.xpm", &img);
	load_image(mlx, mlx->ray->texture[6], "./textures/wood.xpm", &img);
	load_image(mlx, mlx->ray->texture[7], "./textures/colorstone.xpm", &img);
}
