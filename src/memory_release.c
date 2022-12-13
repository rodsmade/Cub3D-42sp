/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:15:24 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/13 13:43:19 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map_data(t_map_data *map)
{
	if (map->input_fd && !map->finished_reading_file)
	{
		ft_free_ptr((void *)&map->line);
		map->line = get_next_line(map->input_fd);
		while (map->line)
		{
			ft_free_ptr((void *)&map->line);
			map->line = get_next_line(map->input_fd);
		}
		ft_free_ptr((void *)&map->line);
	}
	close(map->input_fd);
	ft_free_ptr((void *)&map->texture_paths[NO]);
	ft_free_ptr((void *)&map->texture_paths[SO]);
	ft_free_ptr((void *)&map->texture_paths[EA]);
	ft_free_ptr((void *)&map->texture_paths[WE]);
	ft_free_ptr((void *)&map->line);
	ft_free_arr((void *)&map->map);
	return ;
}

void	free_data(t_data *data)
{
	int	i;

	free_map_data(&data->map_data);
	i = -1;
	if (data->ray.texture)
	{
		while (++i < NB_OF_TEXTURES)
			ft_free_ptr((void *)&data->ray.texture[i]);
		ft_free_ptr((void *)&data->ray.texture);
	}
	if (data->map_data.line)
		ft_free_ptr((void *)data->map_data.line);
	return ;
}
