/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/18 16:29:43 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
