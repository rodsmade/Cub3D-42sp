/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ray_casting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:42:40 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/26 21:31:57 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	- calculate value of wallX
*/
double	wall_x_calc(t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = ray->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ray->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

/*
	- x coordinate on the texture
*/
int	take_x_coord_on_texture(t_ray *ray)
{
	int	tex_x;

	tex_x = (int)(ray->wall_x * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = TEX_WIDTH - tex_x - 1;
	return (tex_x);
}

/*
	- How much to increase the texture coordinate perscreen pixel
*/
double	pixel_perscreen(t_ray *ray)
{
	double	step;

	step = 1.0 * TEX_HEIGHT / ray->line_height;
	return (step);
}

/*
	- Starting texture coordinate
*/
double	tex_coordinate(t_ray *ray)
{
	double tex_pos;

	tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) * ray->step;
	return (tex_pos);
}

/*
	- Cast the texture coordinate y to integer, and mask with (texHeight - 1) in case of overflow
*/
int	conv_text_coord_to_int(t_ray *ray)
{
	int	tex_y;

	tex_y = (int)ray->tex_pos & (TEX_HEIGHT - 1);
	return (tex_y);
}

/*
	- make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
*/
void	color_more_dark_to_y_sides(t_ray *ray)
{
	if (ray->side == 1)
		ray->color = (ray->color >> 1) & 8355711;
}
