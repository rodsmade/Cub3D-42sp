/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_release.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:15:24 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/18 12:00:41 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map_data(t_map_data *map)
{
	// int	i;

	ft_free_ptr((void *)&map->line);

	// i = -1;
	// while (++i < NB_OF_TEXTURES)
	// {
	// 	if (map->texture_paths[i] != NULL)
	// 		ft_free_ptr((void *)&map->texture_paths[i]);
	// }
	return ;
}

void	free_data(t_data *data)
{
	free_map_data(&data->map_data);
	// free_mlx_struct();
	// free_tex_parameters();
	return ;
}
