/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:48:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/10 12:42:25 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_map_surrounded_by_one(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || !map[i + 1]) && (map[i][j] != '1'
				&& map[i][j] != ' '))
				return false;
			if ((j == 0 || !map[i][j + 1]) && (map[i][j] != '1'
				&& map[i][j] != ' '))
				return false;
			j++;
		}
		i++;
	}
	return true;
}

void	print_locale(char **map, int line, int column)
{
	printf("\nLOCALE:\n");
	// LINE - 1
	printf("[ ");
	if (line > 0 && column > 0 && map[line - 1][column - 1])
		printf("%c", map[line - 1][column - 1]);
	else
		printf("x");
	printf(",    ");
	if (line > 0 && map[line - 1][column])
		printf("%c", map[line - 1][column]);
	else
		printf("x");
	printf("   , ");
	if (line > 0 && map[line - 1][column + 1])
		printf("%c", map[line - 1][column + 1]);
	else
		printf("x");
	printf("]\n");
	
	// LINE
	printf("[ ");
	if (map[line] && map[line][column - 1])
		printf("%c", map[line][column - 1]);
	else
		printf("x");
	printf(", ");
	if (map[line] && map[line][column])
		printf(" ( %c ) ", map[line][column]);
	else
		printf("x");
	printf(", ");
	if (map[line] && map[line][column + 1])
		printf("%c", map[line][column + 1]);
	else
		printf("x");
	printf("]\n");

	// LINE + 1
	printf("[ ");
	if (map[line + 1] && map[line + 1][column - 1])
		printf("%c", map[line + 1][column - 1]);
	else
		printf("x");
	printf(",    ");
	if (map[line + 1] && map[line + 1][column])
		printf("%c", map[line + 1][column]);
	else
		printf("x");
	printf("   , ");
	if (map[line + 1] && map[line + 1][column + 1])
		printf("%c", map[line + 1][column + 1]);
	else
		printf("x");
	printf("]\n");
}

bool	line_above_is_long_enough(t_position curr_pos, t_map_parameters *map_params)
{
	if (curr_pos.line > 0)
		return (ft_strlen(map_params->map[curr_pos.line - 1]) >= (size_t) curr_pos.column + 1);
	return (false);
}

bool	line_below_is_long_enough(t_position curr_pos, t_map_parameters *map_params)
{
	if (curr_pos.line < ft_matrixlen(map_params->map) - 1)
		return (ft_strlen(map_params->map[curr_pos.line + 1]) >= (size_t) curr_pos.column + 1);
	return (false);
}

void	decide_where_to_go_next(t_map_parameters *map_params, t_position *prev_pos, t_position curr_pos, t_position *next_pos)
{
	t_position next_move;

	if (line_above_is_long_enough(curr_pos, map_params) && (map_params->map)[curr_pos.line - 1][curr_pos.column] == '1')
	{
		next_move = t_position_create_tuple(curr_pos.line - 1, curr_pos.column);
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
			return (t_position_copy(next_pos, next_move));
	}
	if ((map_params->map)[curr_pos.line][curr_pos.column + 1] && (map_params->map)[curr_pos.line][curr_pos.column + 1] == '1')
	{
		next_move = t_position_create_tuple(curr_pos.line, curr_pos.column + 1);
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
			return (t_position_copy(next_pos, next_move));
	}
	if (line_below_is_long_enough(curr_pos, map_params) && (map_params->map)[curr_pos.line + 1][curr_pos.column] == '1')
	{
		next_move = t_position_create_tuple(curr_pos.line + 1, curr_pos.column);
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
			return (t_position_copy(next_pos, next_move));
	}
	if (curr_pos.column > 0 && (map_params->map)[curr_pos.line][curr_pos.column - 1] == '1')
	{
		next_move = t_position_create_tuple(curr_pos.line, curr_pos.column - 1);
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
			return (t_position_copy(next_pos, next_move));
	}
	print_err_exit(INVALID_MAP, map_params);
}

void	find_starting_point(t_position *pivot, t_map_parameters *map_params)
// tvz declarar int *i, j e usar pra ficar mais claro dentro do loop
{
	pivot->line = -1;
	while ((map_params->map)[++(pivot->line)])
	{
		pivot->column = -1;
		while ((map_params->map)[pivot->line][++pivot->column])
		{
			if ((map_params->map)[pivot->line][pivot->column] == '1')
				break;
		}
		if ((map_params->map)[pivot->line][pivot->column] && (map_params->map)[pivot->line][pivot->column] == '1')
			break;
	}
	if (!(map_params->map)[pivot->line][pivot->column])
		print_err_exit(INVALID_MAP, map_params);
	// print_locale((*map), (*line), (*column));
}

void	trace_contour(t_map_parameters *map_params)
{
	t_position	starting_point;
	t_position	*pivot;
	t_position	*came_from;
	t_position	*goes_to;

	came_from = malloc(sizeof(*came_from));
	goes_to = malloc(sizeof(*goes_to));
	pivot = malloc(sizeof(*pivot));
	if (!came_from || !goes_to || !pivot)
		return ;
	find_starting_point(&starting_point, map_params);
	decide_where_to_go_next(map_params, NULL, starting_point, goes_to);
	map_params->map_copy_for_debug[starting_point.line][starting_point.column] = '-';
	t_position_copy(pivot, starting_point);
	while (goes_to && !t_position_compare_ptr(goes_to, &starting_point))
	{
		t_position_copy(came_from, *pivot);
		t_position_copy(pivot, *goes_to);
		decide_where_to_go_next(map_params, came_from, *pivot, goes_to);
		map_params->map_copy_for_debug[pivot->line][pivot->column] = '-';
	}
	if (t_position_compare_ptr(goes_to, &starting_point))
		printf ("✅ mapa válido\n");
	else
		print_err_exit(INVALID_MAP, map_params);
}

bool	is_valid_map(t_map_parameters *map_params)
{
	// if (!is_map_surrounded_by_one(map))
	// 	return false;
	// TODO:
	// validate_chars(map);
	// validate_map_size(map);
	trace_contour(map_params);
	return true;
}

void	save_map(int input_fd, t_map_parameters *map_params)
{
	char	*map_stringified;
	char	*temp;

	map_params->line = ft_charjoin(map_params->line, '\n');
	map_stringified = ft_strdup("");
	while (map_params->line)
	{
		temp = map_stringified;
		map_stringified = ft_strjoin(map_stringified, map_params->line);
		ft_free_ptr((void *)&temp);
		ft_free_ptr((void *)&map_params->line);
		map_params->line = get_next_line(input_fd);
	}
	map_params->map = ft_split(map_stringified, '\n');
	ft_free_ptr((void *)&map_stringified);
}

void	validate_map(int input_fd, t_map_parameters *map_params)
{
	(void) input_fd;

	save_map(input_fd, map_params);
	ft_free_ptr((void *)&map_params->line);
	// debug_print_map_read(map_params);
	close(input_fd);
	debug_copy_map(map_params);
	if (!is_valid_map(map_params))
		print_err_exit(INVALID_MAP, map_params);
	return ;
}
