/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:15:24 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/29 22:15:42 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map_params(t_map_parameters *map_params)
{
	ft_free_ptr((void *)&map_params->line);
	ft_free_arr((void *)&map_params->map);
	return ;
}
