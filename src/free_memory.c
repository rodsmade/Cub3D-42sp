/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 22:15:24 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/11 20:40:41 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_data(t_data *data)
{
	int	i;

	ft_free_ptr((void *)&data->line);
	ft_free_arr((void *)&data->map);
	i = -1;
	while (++i < 4)
	{
		if (data->texture_fds[i] != -42)
			close(data->texture_fds[i]);
	}
	return ;
}
