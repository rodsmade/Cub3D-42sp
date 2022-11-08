/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_params_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:36:31 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/11 20:38:09 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_for_valid_path(t_data *data)
{
	int	i;
	int	fd;

	if (data->texture_fds[get_direction_index(data->line[0])]
		== -42)
		(data->params_count)++;
	else
		print_err_exit(REDUNDANT_PARAMETER_FOUND, data);
	i = 2 + jump_spaces(&(data->line[2]));
	fd = open(&(data->line[i]), O_RDONLY);
	if (fd == -1)
		print_err_exit(SYSCALL_ERROR, data);
	data->texture_fds[get_direction_index(data->line[0])] = fd;
	return ;
}

void	check_duplicate_parameter(t_data *data)
{
	if (data->colours[get_colour_index(data->line[0])][0] == -42)
		(data->params_count)++;
	else
		print_err_exit(REDUNDANT_PARAMETER_FOUND, data);
	return ;
}

void	check_colour_params_count(char **colours_array,
	t_data *data)
{
	int	comma_count;
	int	params_count;
	int	i;

	comma_count = 0;
	i = -1;
	while (data->line[++i])
		if (data->line[i] == ',')
			comma_count++;
	if (comma_count != 2)
		print_err_exit(INVALID_COLOUR_PARAM, data);
	params_count = 0;
	i = -1;
	while (colours_array[++i])
		params_count++;
	if (params_count != 3)
		print_err_exit(INVALID_COLOUR_PARAM, data);
	return ;
}

void	check_for_valid_colour(t_data *data)
{
	int		i;
	char	**colours_array;

	check_duplicate_parameter(data);
	colours_array = ft_split(&(data->line[1]), ',');
	check_colour_params_count(colours_array, data);
	i = -1;
	while (colours_array[++i])
	{
		data->colours[get_colour_index(data->line[0])][i] = \
			convert_colour_to_int(colours_array[i], data);
	}
	ft_free_ptr((void *)&colours_array);
	return ;
}
