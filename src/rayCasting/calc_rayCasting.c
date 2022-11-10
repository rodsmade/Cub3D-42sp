/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rayCasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:26:28 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/07 17:59:27 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	display_and_text_calcs(t_mlx_struct *mlx, int x)
{
	int	y;

	mlx->ray->line_height = (int)(HEIGHT / mlx->ray->perp_wall_dist);
	mlx->ray->draw_start = -mlx->ray->line_height / 2 + HEIGHT / 2;
	if (mlx->ray->draw_start < 0)
		mlx->ray->draw_start = 0;
	mlx->ray->draw_end = mlx->ray->line_height / 2 + HEIGHT / 2;
	if (mlx->ray->draw_end >= HEIGHT)
		mlx->ray->draw_end = HEIGHT - 1;
	mlx->ray->tex_num = world_map[mlx->ray->map_x][mlx->ray->map_y];
	mlx->ray->wall_x = wall_x_calc(mlx);
	mlx->ray->tex_x = take_x_coord_on_texture(mlx);
	mlx->ray->step = pixel_perscreen(mlx);
	mlx->ray->tex_pos = tex_coordinate(mlx);
	y = mlx->ray->draw_start;
	while (y < mlx->ray->draw_end)
	{
		mlx->ray->tex_y = conv_text_coord_to_int(mlx);
		mlx->ray->tex_pos += mlx->ray->step;
		mlx->ray->color = mlx->ray->texture[mlx->ray->tex_num][TEX_HEIGHT
			* mlx->ray->tex_y + mlx->ray->tex_x];
		color_more_dark_to_y_sides(mlx);
		mlx->ray->buf[y][x] = mlx->ray->color;
		mlx->ray->re_buf = 1;
		y++;
	}
}

static void	init_ray(t_mlx_struct *mlx, int x)
{
	mlx->ray->camera_x = 2 * x / (double)WIDTH - 1;
	mlx->ray->ray_dir_x = mlx->ray->dir_x + mlx->ray->plane_x * mlx->ray->camera_x;
	mlx->ray->ray_dir_y = mlx->ray->dir_y + mlx->ray->plane_y * mlx->ray->camera_x;
	mlx->ray->map_x = (int)mlx->ray->pos_x;
	mlx->ray->map_y = (int)mlx->ray->pos_y;
	mlx->ray->delta_dist_x = fabs(1 / mlx->ray->ray_dir_x);
	mlx->ray->delta_dist_y = fabs(1 / mlx->ray->ray_dir_y);
	mlx->ray->hit = 0;
}

static void	ray_direction(t_mlx_struct *mlx)
{
	if (mlx->ray->ray_dir_x < 0)
		{
			mlx->ray->step_x = -1;
			mlx->ray->side_dist_x = (mlx->ray->pos_x - mlx->ray->map_x) * mlx->ray->delta_dist_x;
		}
		else
		{
			mlx->ray->step_x = 1;
			mlx->ray->side_dist_x = (mlx->ray->map_x + 1.0 - mlx->ray->pos_x) * mlx->ray->delta_dist_x;
		}
		if (mlx->ray->ray_dir_y < 0)
		{
			mlx->ray->step_y = -1;
			mlx->ray->side_dist_y = (mlx->ray->pos_y - mlx->ray->map_y) * mlx->ray->delta_dist_y;
		}
		else
		{
			mlx->ray->step_y = 1;
			mlx->ray->side_dist_y = (mlx->ray->map_y + 1.0 - mlx->ray->pos_y) * mlx->ray->delta_dist_y;
		}
}

static void	ray_hit(t_mlx_struct *mlx)
{
	while (mlx->ray->hit == 0)
	{
		if (mlx->ray->side_dist_x < mlx->ray->side_dist_y)
		{
			mlx->ray->side_dist_x += mlx->ray->delta_dist_x;
			mlx->ray->map_x += mlx->ray->step_x;
			mlx->ray->side = 0;
		}
		else
		{
			mlx->ray->side_dist_y += mlx->ray->delta_dist_y;
			mlx->ray->map_y += mlx->ray->step_y;
			mlx->ray->side = 1;
		}
		if (world_map[mlx->ray->map_x][mlx->ray->map_y] > 0)
			mlx->ray->hit = 1;
	}
}

static void	ray_size(t_mlx_struct *mlx)
{
	if (mlx->ray->side == 0)
		mlx->ray->perp_wall_dist = (mlx->ray->map_x - mlx->ray->pos_x +
			(1 - mlx->ray->step_x) / 2) / mlx->ray->ray_dir_x;
	else
		mlx->ray->perp_wall_dist = (mlx->ray->map_y - mlx->ray->pos_y +
			(1 - mlx->ray->step_y) / 2) / mlx->ray->ray_dir_y;
}

void	calc_rayCasting(t_mlx_struct *mlx, int x)
{
	int	y;

	if (mlx->ray->re_buf == 1)
	{
		while (x < HEIGHT)
		{
			y = 0;
			while (y < WIDTH)
			{
				mlx->ray->buf[x][y] = 0;
				y++;
			}
			x++;
		}
	}
	x = 0;
	while (x < WIDTH)
	{
		init_ray(mlx, x);
		ray_direction(mlx);
		ray_hit(mlx);
		ray_size(mlx);
		display_and_text_calcs(mlx, x);
		x++;
	}
}
