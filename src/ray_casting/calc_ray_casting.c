/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray_casting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:26:28 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/26 21:32:24 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	display_and_text_calcs(t_raycasting *ray, int x, t_data *data)
{
	int	y;

	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	ray->tex_num = data->map[ray->map_x][ray->map_y];
	ray->wall_x = wall_x_calc(ray);
	ray->tex_x = take_x_coord_on_texture(ray);
	ray->step = pixel_perscreen(ray);
	ray->tex_pos = tex_coordinate(ray);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		ray->tex_y = conv_text_coord_to_int(ray);
		ray->tex_pos += ray->step;
		ray->color = ray->texture[ray->tex_num][TEX_HEIGHT
			* ray->tex_y + ray->tex_x];
		color_more_dark_to_y_sides(ray);
		ray->buf[y][x] = ray->color;
		ray->re_buf = 1;
		y++;
	}
}

static void	init_raycasting(t_raycasting *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

static void	ray_direction(t_raycasting *ray)
{
	if (ray->ray_dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
		}
		if (ray->ray_dir_y < 0)
		{
			ray->step_y = -1;
			ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
		}
}

static void	ray_hit(t_raycasting *ray, t_data *data)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (data->map[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

static void	ray_size(t_raycasting *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->pos_x +
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ray->pos_y +
			(1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void	draw(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			data->mlx_struct.img->data[i * WIDTH + j] = data->raycasting.buf[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_struct.pointer, data->mlx_struct.window, data->mlx_struct.img->pointer, 0, 0);
}

void	calc_ray_casting(t_raycasting *ray, int x, t_data *data)
{
	while (x < WIDTH)
	{
		init_raycasting(ray, x);
		ray_direction(ray);
		// passar data aqui:
		ray_hit(ray, data);
		ray_size(ray);
		// passar data aqui:
		display_and_text_calcs(ray, x, data);
		draw(data);
		x++;
	}
}
