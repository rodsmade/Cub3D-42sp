/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:48:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/11 20:29:47 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	line_above_is_long_enough(t_position curr_pos, t_map_parameters *data)
{
	if (curr_pos.line > 0)
		return (ft_strlen(data->map[curr_pos.line - 1])
			>= (size_t) curr_pos.column + 1);
	return (false);
}

bool	line_below_is_long_enough(t_position curr_pos, t_map_parameters *data)
{
	if (curr_pos.line < ft_matrixlen(data->map) - 1)
		return (ft_strlen(data->map[curr_pos.line + 1])
			>= (size_t) curr_pos.column + 1);
	return (false);
}

void	decide_where_to_go_next(t_map_parameters *data, t_position *prev_pos, t_position curr_pos, t_position *next_pos)
/* pra debugar colocar a seguinte linha antes de retornar: 
	data->map_copy_for_debug[curr_pos.line][curr_pos.column] = '-';

adicionar sangria no mapa pra facilitar a vida na validação;
só validar um mapa fechado sem buracos dentro;
        1111111111111
    11111000000000001
    10000000000000001
    11111111111111111
*/
{
	t_position	next_move;

	if (line_above_is_long_enough(curr_pos, data) && (data->map)[curr_pos.line - 1][curr_pos.column] == '1')
	{
		next_move = t_position_create_tuple(curr_pos.line - 1, curr_pos.column);
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
			return (t_position_copy(next_pos, next_move));
	}
	if ((data->map)[curr_pos.line][curr_pos.column + 1] && (data->map)[curr_pos.line][curr_pos.column + 1] == '1')
	{
		next_move = t_position_create_tuple(curr_pos.line, curr_pos.column + 1);
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
			return (t_position_copy(next_pos, next_move));
	}
	if (line_below_is_long_enough(curr_pos, data) && (data->map)[curr_pos.line + 1][curr_pos.column] == '1')
	{
		next_move = t_position_create_tuple(curr_pos.line + 1, curr_pos.column);
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
			return (t_position_copy(next_pos, next_move));
	}
	if (curr_pos.column > 0 && (data->map)[curr_pos.line][curr_pos.column - 1] == '1')
	{
		next_move = t_position_create_tuple(curr_pos.line, curr_pos.column - 1);
		if (t_position_compare_ptr(&next_move, prev_pos) == false)
			return (t_position_copy(next_pos, next_move));
	}
	print_err_exit(INVALID_MAP, data);
}

void	find_starting_point(t_position *pivot, t_map_parameters *map_params)
{
	int	i;
	int	j;

	i = -1;
	while ((map_params->map)[++(i)])
	{
		j = -1;
		while ((map_params->map)[i][++j])
		{
			if ((map_params->map)[i][j] == '1')
				break ;
		}
		if ((map_params->map)[i][j] && (map_params->map)[i][j] == '1')
			break ;
	}
	if (!(map_params->map)[i][j])
		print_err_exit(INVALID_MAP, map_params);
	pivot->line = i;
	pivot->column = j;
	return ;
}

void	trace_contour(t_map_parameters *data)
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
	find_starting_point(&starting_point, data);
	decide_where_to_go_next(data, NULL, starting_point, goes_to);
	t_position_copy(pivot, starting_point);
	while (goes_to && !t_position_compare_ptr(goes_to, &starting_point))
	{
		t_position_copy(came_from, *pivot);
		t_position_copy(pivot, *goes_to);
		decide_where_to_go_next(data, came_from, *pivot, goes_to);
	}
	if (t_position_compare_ptr(goes_to, &starting_point) == false)
		print_err_exit(INVALID_MAP, data);
}

int	find_longest_line_length(char **map)
{
	int	max_length;
	int	line_length;
	int	i;

	max_length = 0;
	i = -1;
	while (map[++i])
	{
		line_length = (int) ft_strlen(map[i]);
		if (line_length > max_length)
			max_length = line_length;
	}
	return (max_length);
}

char	*ft_alloc_string(int str_size, int init_value)
/**
 * @brief allocs `str_size` bytes for a string, appends a terminating '\0', and
 * initialises every byte in the string to `init_value`.
 */
{
	char	*str;
	int		i;

	str = malloc((str_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < str_size)
		str[i] = init_value;
	str[i] = '\0';
	return (str);
}

void	pad_lines_on_top_and_bottom(int map_length, t_map_parameters *data)
{
	char	**temp_map;
	int		map_size;
	int		i;

	temp_map = data->map;
	map_size = ft_matrixlen(temp_map);
	data->map = malloc((map_size + 2 + 1) * sizeof(char *));
	if (!data->map)
		print_err_exit(MEMORY_ALLOCATION, data);
	data->map[0] = ft_alloc_string(map_length, ' ');
	i = -1;
	while (temp_map[++i])
		data->map[i + 1] = ft_strdup(temp_map[i]);
	data->map[map_size + 2 - 1] = ft_alloc_string(map_length, ' ');
	data->map[map_size + 2] = NULL;
	ft_free_arr((void *)&temp_map);
}

void	pad_line_with_spaces(char **curr_line, int map_length, t_map_parameters *data)
{
	int		old_line_len;
	char	*padded_line;
	char	*temp;

	temp = *curr_line;
	old_line_len = ft_strlen(*curr_line);
	padded_line = ft_alloc_string(map_length, ' ');
	if (!padded_line)
		print_err_exit(MEMORY_ALLOCATION, data);
	ft_memcpy(padded_line, *curr_line, old_line_len);
	*curr_line = padded_line;
	ft_free_ptr((void *)&temp);
	return ;
}

void	pad_columns(int map_length, t_map_parameters *data)
{
	int		i;

	i = -1;
	while (data->map[++i])
		if ((int) ft_strlen(data->map[i]) < map_length)
			pad_line_with_spaces(&(data->map[i]), map_length, data);
		
	return ;
}

void	pad_map(t_map_parameters *data)
{
	int		map_length;

	map_length = find_longest_line_length(data->map);
	pad_lines_on_top_and_bottom(map_length, data);
	pad_columns(map_length, data);
	debug_print_map_read(data->map);
	print_err_exit(MEMORY_ALLOCATION, data);
}

void	save_map(t_map_parameters *map_params)
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
		map_params->line = get_next_line(map_params->input_fd);
	}
	map_params->map = ft_split(map_stringified, '\n');
	ft_free_ptr((void *)&map_stringified);
	ft_free_ptr((void *)&map_params->line);
	close(map_params->input_fd);
	pad_map(map_params);
}

void	validate_map(t_map_parameters *map_params)
/*
	funções de debug q puxei pra cá pra ñ deletar e perder a ref:
		debug_print_map_read(map_params);
		debug_copy_map(map_params);
	TODO:
		validate_chars(map);
		validate_map_size(map);
*/
{
	save_map(map_params);
	trace_contour(map_params);
	return ;
}
