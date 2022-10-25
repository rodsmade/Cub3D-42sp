/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rayCasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:26:28 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/25 17:39:00 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw(t_ray *ray, int x)
{
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	if (world_map[ray->map_y][ray->map_x] == 1)
		ray->color = 0xFF0000;
	else if (world_map[ray->map_y][ray->map_x] == 2)
		ray->color = 0x00FF00;
	else if (world_map[ray->map_y][ray->map_x] == 3)
		ray->color = 0x0000FF;
	else if (world_map[ray->map_y][ray->map_x] == 4)
		ray->color = 0xFFFFFF;
	else
		ray->color = 0xFFFF00;
	if (ray->side == 1)
		ray->color = ray->color / 2;
	while (ray->draw_start <= ray->draw_end)
	{
		mlx_pixel_put(ray->mlx->pointer, ray->mlx->window, x, ray->draw_start, ray->color);
		ray->draw_start++;
	}
}

static void	init_ray(t_ray *ray, int x)
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

static void	ray_direction(t_ray *ray)
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

static void	ray_hit(t_ray *ray)
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
		if (world_map[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

static void	ray_size(t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - ray->pos_x +
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - ray->pos_y +
			(1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void	calc_rayCasting(t_ray *ray, int x)
{
	while (x < WIDTH)
	{
		init_ray(ray, x);
		ray_direction(ray);
		ray_hit(ray);
		ray_size(ray);
		draw(ray, x);
		x++;
	}
}
