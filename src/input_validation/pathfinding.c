/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:52:43 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/08 18:54:20 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	has_valid_move_direction(t_position *curr_pos, char **map)
{
	return (is_valid_move_direction(find_next_move(curr_pos, NO), map)
		|| is_valid_move_direction(find_next_move(curr_pos, SO), map)
		|| is_valid_move_direction(find_next_move(curr_pos, EA), map)
		|| is_valid_move_direction(find_next_move(curr_pos, WE), map));
}

t_position	get_next_move(t_position *curr_pos, char **map)
{
	t_position	next_move;

	if (is_valid_move_direction(find_next_move(curr_pos, NO), map))
		next_move = find_next_move(curr_pos, NO);
	else if (is_valid_move_direction(find_next_move(curr_pos, EA), map))
		next_move = find_next_move(curr_pos, EA);
	else if (is_valid_move_direction(find_next_move(curr_pos, SO), map))
		next_move = find_next_move(curr_pos, SO);
	else
		next_move = find_next_move(curr_pos, WE);
	return (next_move);
}

bool	can_reverse(t_position *curr_pos, t_data *data, t_position *next_pos)
{
	t_position	x_pos;
	char		**map;

	map = data->map_data.map;
	while (!has_neighbouring_one(*curr_pos, map))
	{
		x_pos = find_x_pos(*curr_pos, map);
		if (x_pos.line == 0 && x_pos.col == 0)
			return (false);
		map[curr_pos->line][curr_pos->col] = 'y';
		t_position_copy(curr_pos, x_pos);
	}
	if (has_valid_move_direction(curr_pos, map))
	{
		*next_pos = get_next_move(curr_pos, map);
		data->map_data.map[next_pos->line][next_pos->col] = 'x';
		return (true);
	}
	return (false);
}

void	decide_where_to_go_next(t_data *data, t_position *curr_pos,
			t_position *next_pos)
{
	char	**map;

	map = data->map_data.map;
	if (has_valid_move_direction(curr_pos, map))
	{
		*next_pos = get_next_move(curr_pos, map);
		map[next_pos->line][next_pos->col] = 'x';
	}
	else
	{
		if (!can_reverse(curr_pos, data, next_pos))
			next_pos->col = -1;
	}
	return ;
}
