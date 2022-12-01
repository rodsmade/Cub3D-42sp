/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ray_casting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:26:28 by gusalves          #+#    #+#             */
/*   Updated: 2022/11/18 11:46:31 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	display_draw(t_data *data, int x, int y)
// x = coordenada x da linha vertical sendo desenhada; y = draw_start.
{
	int	i;

	i = -1;
	while (++i < y)
		data->ray.buf[i][x] = data->map_data.ceiling_colour_hex;
	while (y < data->ray.draw_end)
	{
		data->ray.tex_y = conv_text_coord_to_int(data);
		data->ray.tex_pos += data->ray.step;
		data->ray.color = data->ray.texture[data->ray.tex_num][TEX_HEIGHT
			* data->ray.tex_y + data->ray.tex_x];
		color_more_dark_to_y_sides(data);
		data->ray.buf[y][x] = data->ray.color;
		data->ray.re_buf = 1;
		y++;
	}
	i = y;
	while (++i < HEIGHT)
		data->ray.buf[i][x] = data->map_data.floor_colour_hex;
}

static void	display_and_text_calcs(t_data *data, int x)
{
	data->ray.line_height = (int)(HEIGHT / data->ray.perp_wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + HEIGHT / 2;
	if (data->ray.draw_end >= HEIGHT)
		data->ray.draw_end = HEIGHT - 1;
	data->ray.tex_num = 1;
	data->ray.wall_x = wall_x_calc(data);
	data->ray.tex_x = take_x_coord_on_texture(data);
	data->ray.step = pixel_perscreen(data);
	data->ray.tex_pos = tex_coordinate(data);
	display_draw(data, x, data->ray.draw_start);
}

static void	handle_initial_data(t_data *data, int x)
{
	data->ray.camera_x = 2 * x / (double)WIDTH - 1;
	data->ray.ray_dir_x = data->ray.dir_x
		+ data->ray.plane_x * data->ray.camera_x;
	data->ray.ray_dir_y = data->ray.dir_y
		+ data->ray.plane_y * data->ray.camera_x;
	data->ray.map_x = (int)data->ray.pos_x;
	data->ray.map_y = (int)data->ray.pos_y;
	data->ray.delta_dist_x = fabs(1 / data->ray.ray_dir_x);
	data->ray.delta_dist_y = fabs(1 / data->ray.ray_dir_y);
	data->ray.hit = 0;
}

void	calc_raycasting(t_data *data, int x)
{
	if (data->ray.re_buf == 1)
		clean_buf_with_zero(&data->ray);
	while (x < WIDTH)
	{
		handle_initial_data(data, x);
		calc_ray_side_distance_and_next_block_step(data);
		dda_loop_with_check_hit(data);
		calc_perp_wall_dist_from_camera_plane(data);
		display_and_text_calcs(data, x);
		x++;
	}
}
