/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:49:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/02 10:42:24 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	try_to_move_in_direction(t_position next_move, t_position *prev_pos,
	t_position *next_pos, t_data *data)
{
	if ((data->map_data.map)[next_move.line][next_move.col] == '1')
	{
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
		{
			t_position_copy(next_pos, next_move);
			data->map_data.map[next_move.line][next_move.col] = 'x';
			return (true);
		}
	}
	return (false);
}

void	decide_where_to_go_next(t_data *data, t_position *prev_pos,
			t_position curr_pos, t_position *next_pos)
/* pra debugar colocar a seguinte linha antes de retornar: 
	data->map_copy_for_debug[curr_pos.line][curr_pos.col] = '-';
*/
{
	if (!try_to_move_in_direction(t_position_create_tuple(curr_pos.line - 1,
				curr_pos.col), prev_pos, next_pos, data)
		&& !try_to_move_in_direction(t_position_create_tuple(curr_pos.line,
				curr_pos.col + 1), prev_pos, next_pos, data)
		&& !try_to_move_in_direction(t_position_create_tuple(curr_pos.line + 1,
				curr_pos.col), prev_pos, next_pos, data)
		&& !try_to_move_in_direction(t_position_create_tuple(curr_pos.line,
				curr_pos.col - 1), prev_pos, next_pos, data))
		print_err_exit(INVALID_MAP, data);
}

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
