/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 09:14:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/11 20:36:32 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_data(t_data *data)
{
	data->input_fd = -42;
	data->texture_fds[NO] = -42;
	data->texture_fds[SO] = -42;
	data->texture_fds[EA] = -42;
	data->texture_fds[WE] = -42;
	data->colours[FLOOR][0] = -42;
	data->colours[FLOOR][1] = -42;
	data->colours[FLOOR][2] = -42;
	data->colours[CEILING][0] = -42;
	data->colours[CEILING][1] = -42;
	data->colours[CEILING][2] = -42;
	data->params_count = 0;
	data->line = NULL;
	data->map = NULL;
}
