/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calcs_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:42:40 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/18 11:46:48 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

double	tex_coordinate(t_data *data)
{
	double	tex_pos;

	tex_pos = (data->ray.draw_start - HEIGHT / 2
			+ data->ray.line_height / 2) * data->ray.step;
	return (tex_pos);
}

int	conv_text_coord_to_int(t_data *data)
{
	int	tex_y;

	tex_y = (int)data->ray.tex_pos & (TEX_HEIGHT - 1);
	return (tex_y);
}

void	color_more_dark_to_y_sides(t_data *data)
{
	if (data->ray.side == 1)
		data->ray.color = (data->ray.color >> 1) & 8355711;
}
