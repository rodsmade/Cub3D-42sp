/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calcs_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:42:40 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/10 17:49:33 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	tex_coordinate(t_mlx_struct *mlx)
{
	double	tex_pos;

	tex_pos = (mlx->ray->draw_start - HEIGHT / 2
			+ mlx->ray->line_height / 2) * mlx->ray->step;
	return (tex_pos);
}

int	conv_text_coord_to_int(t_mlx_struct *mlx)
{
	int	tex_y;

	tex_y = (int)mlx->ray->tex_pos & (TEX_HEIGHT - 1);
	return (tex_y);
}

void	color_more_dark_to_y_sides(t_mlx_struct *mlx)
{
	if (mlx->ray->side == 1)
		mlx->ray->color = (mlx->ray->color >> 1) & 8355711;
}
