/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:48:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/06 18:12:36 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
