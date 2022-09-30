/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:48:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/29 21:37:14 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_map(int input_fd, t_map_parameters *map_params)
{
	(void) input_fd;
	printf("linha em q parou: >>%s<<\n", map_params->line);
	ft_free_ptr((void *)&map_params->line);
	return ;
}