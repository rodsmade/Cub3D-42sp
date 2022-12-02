/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:48:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/02 10:32:59 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	trace_outer_walls(t_data *data)
{
	t_position	starting_point;
	t_position	*pivot;
	t_position	*came_from;
	t_position	*goes_to;

	came_from = malloc(sizeof(*came_from));
	goes_to = malloc(sizeof(*goes_to));
	pivot = malloc(sizeof(*pivot));
	if (!came_from || !goes_to || !pivot)
		return print_err_exit(MEMORY_ALLOCATION, data);
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
	ft_free_ptr((void *)&came_from);
	ft_free_ptr((void *)&goes_to);
	ft_free_ptr((void *)&pivot);
}

void	save_map(t_data *data)
{
	char	*map_stringified;
	char	*temp;

	data->map_data.line = ft_charjoin(data->map_data.line, '\n');
	map_stringified = ft_strdup("");
	while (data->map_data.line)
	{
		temp = map_stringified;
		map_stringified = ft_strjoin(map_stringified, data->map_data.line);
		ft_free_ptr((void *)&temp);
		ft_free_ptr((void *)&data->map_data.line);
		data->map_data.line = get_next_line(data->map_data.input_fd);
	}
	data->map_data.map = ft_split(map_stringified, '\n');
	ft_free_ptr((void *)&map_stringified);
	ft_free_ptr((void *)&data->map_data.line);
	close(data->map_data.input_fd);
	pad_map(data);
}

void	validate_characters(t_data *data)
{
	int		i;
	int		j;
	bool	starting_char;

	starting_char = false;
	i = -1;
	while (data->map_data.map[++i])
	{
		j = -1;
		while (data->map_data.map[i][++j])
		{
			if (!ft_strchr(VALID_CHARS, data->map_data.map[i][j]))
				return (print_err_exit(INVALID_CHAR_FOUND, data));
			if (ft_strchr(STARTING_CHARS, data->map_data.map[i][j]))
			{
				if (!starting_char)
					starting_char = true;
				else
					return (print_err_exit(MULTIPLE_POS_CHARS_FOUND, data));
			}
		}
	}
	if (!starting_char)
		return (print_err_exit(MISSING_STARTING_POS_CHAR_ERROR, data));
	return ;
}

void	validate_map_size(t_data *data)
{
	if (ft_matrixlen(data->map_data.map) < 3
		|| ft_strlen(data->map_data.map[0]) < 5)
		print_err_exit(INVALID_MAP_SIZE, data);
	return ;
}

void	validate_map(t_data *data)
{
	save_map(data);
	validate_map_size(data);
	validate_characters(data);
	trace_outer_walls(data);
	check_player_position(data);
	return ;
}
