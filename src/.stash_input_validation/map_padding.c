/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_padding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 05:57:00 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/17 17:42:08 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	pad_lines_on_top_and_bottom(int map_length, t_data *data)
{
	char	**temp_map;
	int		map_size;
	int		i;

	temp_map = data->map.map;
	map_size = ft_matrixlen(temp_map);
	data->map.map = malloc((map_size + 2 + 1) * sizeof(char *));
	if (!data->map.map)
		print_err_exit(MEMORY_ALLOCATION, data);
	data->map.map[0] = ft_alloc_string(map_length, ' ');
	i = -1;
	while (temp_map[++i])
		data->map.map[i + 1] = ft_strdup(temp_map[i]);
	data->map.map[map_size + 2 - 1] = ft_alloc_string(map_length, ' ');
	data->map.map[map_size + 2] = NULL;
	ft_free_arr((void *)&temp_map);
}

void	pad_line_with_spaces(char **curr_line, int map_length, t_data *data)
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

void	add_leading_and_trailing_spaces(char **line, int map_len, t_data *data)
{
	char	*temp;

	temp = *line;
	*line = malloc((map_len + 2 + 1) * sizeof(char));
	if (!*line)
		print_err_exit(MEMORY_ALLOCATION, data);
	(*line)[0] = ' ';
	ft_memcpy(*line + 1, temp, map_len);
	(*line)[map_len + 1] = ' ';
	(*line)[map_len + 2] = '\0';
	ft_free_ptr((void *)&temp);
	return ;
}

void	pad_columns(int map_length, t_data *data)
{
	int		i;

	i = -1;
	while (data->map.map[++i])
	{
		if ((int) ft_strlen(data->map.map[i]) < map_length)
			pad_line_with_spaces(&(data->map.map[i]), map_length, data);
		add_leading_and_trailing_spaces(&(data->map.map[i]), map_length, data);
	}
	return ;
}

void	pad_map(t_data *data)
/*
	debug_print_map_read(data->map.map);
*/
{
	int		map_length;

	map_length = find_longest_line_length(data->map.map);
	pad_lines_on_top_and_bottom(map_length, data);
	pad_columns(map_length, data);
}
