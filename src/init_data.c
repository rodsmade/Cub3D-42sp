/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/16 16:08:42 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_tex_parameters(t_mlx_struct *mlx, int i, int j)
{
	clean_buf_with_zero(mlx, 0);
	mlx->ray->texture = (int **)malloc(sizeof(int *) * 8);
	i = 0;
	while (i < 8)
	{
		j = 0;
		mlx->ray->texture[i] = (int *)malloc(sizeof(int)
				* (TEX_HEIGHT * TEX_WIDTH));
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			mlx->ray->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	set_facing_direction_vector(t_mlx_struct *mlx)
{
	if (mlx->map_data.starting_pos_char == 'N')
	{
		mlx->ray->dir_x = -1;
		mlx->ray->dir_y = 0;
	}
	if (mlx->map_data.starting_pos_char == 'S')
	{
		mlx->ray->dir_x = 1;
		mlx->ray->dir_y = 0;
	}
	if (mlx->map_data.starting_pos_char == 'E')
	{
		mlx->ray->dir_x = 0;
		mlx->ray->dir_y = 1;
	}
	if (mlx->map_data.starting_pos_char == 'W')
	{
		mlx->ray->dir_x = 0;
		mlx->ray->dir_y = -1;
	}
}

void	set_camera_plane_vector(t_mlx_struct *mlx)
{
	if (mlx->map_data.starting_pos_char == 'N')
	{
		mlx->ray->plane_x = 0;
		mlx->ray->plane_y = 0.66;
	}
	if (mlx->map_data.starting_pos_char == 'S')
	{
		mlx->ray->plane_x = 0;
		mlx->ray->plane_y = -0.33;
	}
	if (mlx->map_data.starting_pos_char == 'E')
	{
		mlx->ray->plane_x = 0.33;
		mlx->ray->plane_y = 0;
	}
	if (mlx->map_data.starting_pos_char == 'W')
	{
		mlx->ray->plane_x = -0.66;
		mlx->ray->plane_y = 0;
	}
}

void	init_ray_parameters(t_mlx_struct *mlx)
{
	mlx->img = malloc(sizeof(t_mlx_img));
	mlx->ray = malloc(sizeof(t_ray));
	mlx->ray->pos_x = 5;
	mlx->ray->pos_y = 10.5;
	// mlx->ray->dir_x = -1;
	// mlx->ray->dir_y = 0;
	// mlx->ray->plane_x = 0;
	// mlx->ray->plane_y = 0.66;
	mlx->map_data.starting_pos_char = 'W'; // linkar com validacao do mapa dps
	mlx->map_data.floor_colour_hex = 0xFF4F79; // linkar com validacao do mapa dps
	mlx->map_data.ceiling_colour_hex = 0xA11692; // linkar com validacao do mapa dps
	// mlx->map_data.floor_colour_hex = 16732025; // linkar com validacao do mapa dps
	// mlx->map_data.ceiling_colour_hex = 10557074; // linkar com validacao do mapa dps
	set_facing_direction_vector(mlx);
	set_camera_plane_vector(mlx);
	mlx->ray->re_buf = 0;
	mlx->ray->hit = 0;
	mlx->ray->move_speed = 0.1;
	mlx->ray->rot_speed = 0.05;
	init_tex_parameters(mlx, 0, 0);
}

void	init_map_parameters(t_map_parameters *map_parameters)
{
	map_parameters->fds[NO] = -42;
	map_parameters->fds[SO] = -42;
	map_parameters->fds[EA] = -42;
	map_parameters->fds[WE] = -42;
	map_parameters->colours[FLOOR][0] = -42;
	map_parameters->colours[FLOOR][1] = -42;
	map_parameters->colours[FLOOR][2] = -42;
	map_parameters->colours[CEILING][0] = -42;
	map_parameters->colours[CEILING][1] = -42;
	map_parameters->colours[CEILING][2] = -42;
	map_parameters->params_count = 0;
	map_parameters->line = NULL;
}
