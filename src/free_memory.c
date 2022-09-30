/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:15:24 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/30 20:17:50 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map_params(t_map_parameters *map_params)
{
	int	i;

	ft_free_ptr((void *)&map_params->line);
	ft_free_arr((void *)&map_params->map);
	i = -1;
	while (++i < 4)
	{
		if (map_params->texture_fds[i] != -42)
			close(map_params->texture_fds[i]);
	}
	return ;
}
