/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_tracing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:49:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/08 18:42:23 by roaraujo         ###   ########.fr       */
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

bool	check_tile_locale(t_position next_move, char **map)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			if (map[(next_move.line - 1) + i][(next_move.col - 1) + j] == ' ')
				return (true);
	}
	return (false);
}

bool	is_valid_move_direction(t_position position, char **map)
{
	if (map[position.line][position.col] != '1')
		return (false);
	return (check_tile_locale(position, map));
}

t_position	find_next_move(t_position *curr_pos, int direction)
{
	if (direction == NO)
		return (t_position_create_tuple(curr_pos->line - 1, curr_pos->col));
	else if (direction == EA)
		return (t_position_create_tuple(curr_pos->line, curr_pos->col + 1));
	else if (direction == SO)
		return (t_position_create_tuple(curr_pos->line + 1, curr_pos->col));
	else
		return (t_position_create_tuple(curr_pos->line, curr_pos->col - 1));
}

void	prioritise_clockwise_movement(t_position *next_move, bool *move_dir,
			t_position *curr_pos)
{
	if (move_dir[NO])
		t_position_copy(next_move, find_next_move(curr_pos, NO));
	else if (move_dir[EA])
		t_position_copy(next_move, find_next_move(curr_pos, EA));
	else if (move_dir[SO])
		t_position_copy(next_move, find_next_move(curr_pos, SO));
	else if (move_dir[WE])
		t_position_copy(next_move, find_next_move(curr_pos, WE));
	return ;
}

bool	has_neighbouring_one(t_position pos, char **map)
{
	return (map[pos.line - 1][pos.col] == '1'
		|| map[pos.line][pos.col + 1] == '1'
		|| map[pos.line + 1][pos.col] == '1'
		|| map[pos.line][pos.col - 1] == '1');
}

t_position	find_x_pos(t_position curr_pos, char **map)
{
	if (map[curr_pos.line - 1][curr_pos.col] == 'x')
		return (t_position_create_tuple(curr_pos.line - 1, curr_pos.col));
	if (map[curr_pos.line][curr_pos.col + 1] == 'x')
		return (t_position_create_tuple(curr_pos.line, curr_pos.col + 1));
	if (map[curr_pos.line + 1][curr_pos.col] == 'x')
		return (t_position_create_tuple(curr_pos.line + 1, curr_pos.col));
	if (map[curr_pos.line][curr_pos.col - 1] == 'x')
		return (t_position_create_tuple(curr_pos.line, curr_pos.col - 1));
	return (t_position_create_tuple(0, 0));
}

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
