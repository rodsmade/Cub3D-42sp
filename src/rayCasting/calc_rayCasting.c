/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_rayCasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:26:28 by gusalves          #+#    #+#             */
/*   Updated: 2022/10/19 18:01:55 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ver_line(t_data *data, int x, int y1, int y2, int color)
{
	int y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(data->mlx->pointer, data->mlx->window, x, y, color);
		y++;
	}
}

void	calc_rayCasting(t_data *data)
{
	int	screen_iterator;

	screen_iterator = 0;
	while (screen_iterator < WIDTH)
	{

		// calculate ray position and direction
		double camera_x = 2 * screen_iterator / (double)WIDTH - 1; //x-coordinate in camera space
		double ray_dir_x = data->dirX + data->planeX * camera_x;
		double ray_dir_y = data->dirY + data->planeY * camera_x;

		// which box of the map we're in
		int	map_x = (int)data->posX;
		int map_y = (int)data->posY;

		// length of ray from current position to next x or y-side
		double side_dist_x;
		double side_dist_y;

		// lenght of ray from one x or y-side to next x or y-side
		// fabs function takes the double argument and returns the absolute value and this is good to capture the distance between ray_dir_x to 0;
		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist;

		// what direction to step in x or y (+1 or -1)
		int	step_x;
		int	step_y;

		// was there a wall hit?
		int	hit = 0;
		// was a NS or a EW wall hit?
		int	side;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (data->posX - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - data->posX) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (data->posY - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - data->posY) * delta_dist_y;
		}

		while (hit == 0)
		{
			// jump to next map square, OR in x-direction, OR in y-direction
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			//check if ray has hit a wall
			if (world_map[map_x][map_y] > 0)
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (map_x - data->posX + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - data->posY + (1 - step_y) / 2) / ray_dir_y;

		// calculate height of line to draw on screen
		int	line_height = (int)(HEIGHT / perp_wall_dist);

		// calculate lowest and highest pixel to fill in current stripe
		int	draw_start = -line_height / 2 + HEIGHT / 2;

		if (draw_start < 0)
			draw_start = 0;
		int draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;

		int	color;
		if (world_map[map_y][map_x] == 1)
			color =  0xFF0000;
		else if (world_map[map_y][map_x] == 2)
			color = 0x00FF00;
		else if (world_map[map_y][map_x] == 3)
			color = 0x0000FF;
		else if (world_map[map_y][map_x] == 4)
			color = 0xFFFFFF;
		else
			color = 0xFFFF00;

		if (side == 1)
			color = color / 2;

		ver_line(data, screen_iterator, draw_start, draw_end, color);

		screen_iterator++;
	}
}
