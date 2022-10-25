/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rayCasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:26:28 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/25 00:06:35 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ver_line(t_ray *ray, int x, int y1, int y2, int color)
{
	int y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(ray->mlx->pointer, ray->mlx->window, x, y, color);
		y++;
	}
}

void	calc_rayCasting(t_ray *ray)
{
	int	x;

	x = 0;
	// that loop draw a whole frame and read the input every time
	while (x < WIDTH)
	{

		// calculate ray position and direction
		//x-coordinate in camera space
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		ray->ray_dir_x = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->ray_dir_y = ray->dir_y + ray->plane_y * ray->camera_x;

		// essas variaveis abaixo sao relevantes para o DDA
		// which box of the map we're in
		ray->map_x = (int)ray->pos_x;
		ray->map_y = (int)ray->pos_y;

		// length of ray from current position to next x or y-side
		// double side_dist_x;
		// double side_dist_y;

		// lenght of ray from one x or y-side to next x or y-side
		// fabs function takes the double argument and returns the absolute value and this is good to capture the distance between ray_dir_x to 0;
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);

		// calculate the lenght of the ray
		// double perp_wall_dist;

		// what direction to step in x or y (+1 or -1)
		// int	step_x;
		// int	step_y;

		// was there a wall hit?
		// was a NS or a EW wall hit?
		// int	side;

		// calculate step and initial side_dist
		if (ray->ray_dir_x < 0)
		{
			ray->step_x = -1;
			ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
			// then multiply by delta_dist to get the actual euclidean distance
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

		// dda algorithm ()
		ray->hit = 0;
		while (ray->hit == 0)
		{
			// jump to next map square, OR in x-direction, OR in y-direction
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
			//check if ray has hit a wall
			if (world_map[ray->map_x][ray->map_y] > 0)
				ray->hit = 1;
		}

		// this step above is for calculate the size of wall and if you need change the whay of see the game, change here (fish eye)
		if (ray->side == 0)
			ray->perp_wall_dist = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
		else
			ray->perp_wall_dist = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;

		// calculate height of line to draw on screen
		int	line_height = (int)(HEIGHT / ray->perp_wall_dist);

		// calculate lowest and highest pixel to fill in current stripe
		int	draw_start = -line_height / 2 + HEIGHT / 2;

		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;

		int	color;
		if (world_map[ray->map_y][ray->map_x] == 1)
			color =  0xFF0000;
		else if (world_map[ray->map_y][ray->map_x] == 2)
			color = 0x00FF00;
		else if (world_map[ray->map_y][ray->map_x] == 3)
			color = 0x0000FF;
		else if (world_map[ray->map_y][ray->map_x] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;

		if (ray->side == 1)
			color = color / 2;

		ver_line(ray, x, draw_start, draw_end, color);

		x++;
	}
}
