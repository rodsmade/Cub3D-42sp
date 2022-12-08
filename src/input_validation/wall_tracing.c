/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_tracing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:49:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/08 18:56:17 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_starting_point(t_position *starting_point, t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while ((data->map_data.map)[++(i)])
	{
		j = -1;
		while ((data->map_data.map)[i][++j])
		{
			if ((data->map_data.map)[i][j] == '1')
				break ;
		}
		if ((data->map_data.map)[i][j] && (data->map_data.map)[i][j] == '1')
			break ;
	}
	if (!(data->map_data.map)[i][j])
		print_err_exit(INVALID_MAP, data);
	starting_point->line = i;
	starting_point->col = j;
	return ;
}

void	trace_outer_walls(t_data *data)
{
	t_position	starting_point;
	t_position	*pivot;
	t_position	*goes_to;

	goes_to = malloc(sizeof(*goes_to));
	pivot = malloc(sizeof(*pivot));
	if (!goes_to || !pivot)
		return (print_err_exit(MEMORY_ALLOCATION, data));
	find_starting_point(&starting_point, data);
	decide_where_to_go_next(data, &starting_point, goes_to);
	t_position_copy(pivot, starting_point);
	while (goes_to->col != -1
		&& !t_position_compare_ptr(goes_to, &starting_point))
	{
		t_position_copy(pivot, *goes_to);
		decide_where_to_go_next(data, pivot, goes_to);
	}
	if (t_position_compare_ptr(goes_to, &starting_point) == false)
	{
		ft_free_ptr((void *)&goes_to);
		ft_free_ptr((void *)&pivot);
		print_err_exit(INVALID_MAP, data);
	}
	ft_free_ptr((void *)&goes_to);
	ft_free_ptr((void *)&pivot);
}
