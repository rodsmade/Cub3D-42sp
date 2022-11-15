/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rayCasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:26:28 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/15 11:32:21 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	display_draw(t_mlx_struct *mlx, int x, int y)
{
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

static void	display_and_text_calcs(t_mlx_struct *mlx, int x)
{
	mlx->ray->line_height = (int)(HEIGHT / mlx->ray->perp_wall_dist);
	mlx->ray->draw_start = -mlx->ray->line_height / 2 + HEIGHT / 2;
	if (mlx->ray->draw_start < 0)
		mlx->ray->draw_start = 0;
	mlx->ray->draw_end = mlx->ray->line_height / 2 + HEIGHT / 2;
	if (mlx->ray->draw_end >= HEIGHT)
		mlx->ray->draw_end = HEIGHT - 1;
	mlx->ray->tex_num = world_map_char[mlx->ray->map_x][mlx->ray->map_y] - 48;
	mlx->ray->wall_x = wall_x_calc(mlx);
	mlx->ray->tex_x = take_x_coord_on_texture(mlx);
	mlx->ray->step = pixel_perscreen(mlx);
	mlx->ray->tex_pos = tex_coordinate(mlx);
	display_draw(mlx, x, mlx->ray->draw_start);
}

static void	handle_initial_data(t_mlx_struct *mlx, int x)
{
	mlx->ray->camera_x = 2 * x / (double)WIDTH - 1;
	mlx->ray->ray_dir_x = mlx->ray->dir_x
		+ mlx->ray->plane_x * mlx->ray->camera_x;
	mlx->ray->ray_dir_y = mlx->ray->dir_y
		+ mlx->ray->plane_y * mlx->ray->camera_x;
	mlx->ray->map_x = (int)mlx->ray->pos_x;
	mlx->ray->map_y = (int)mlx->ray->pos_y;
	mlx->ray->delta_dist_x = fabs(1 / mlx->ray->ray_dir_x);
	mlx->ray->delta_dist_y = fabs(1 / mlx->ray->ray_dir_y);
	mlx->ray->hit = 0;
}

void	calc_raycasting(t_mlx_struct *mlx, int x)
{
	if (mlx->ray->re_buf == 1)
		clean_buf_with_zero(mlx, 0);
	while (x < WIDTH)
	{
		handle_initial_data(mlx, x);
		calc_ray_side_distance_and_next_block_step(mlx);
		dda_loop_with_check_hit(mlx);
		calc_perp_wall_dist_from_camera_plane(mlx);
		display_and_text_calcs(mlx, x);
		x++;
	}
}
