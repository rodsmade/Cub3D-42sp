/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_params_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:36:31 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/29 21:34:39 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_for_valid_path(t_map_parameters *map_params)
{
	int	i;
	int	fd;

	if (map_params->texture_fds[get_direction_index(map_params->line[0])] == -42)
		(map_params->params_count)++;
	else
		print_err_exit(REDUNDANT_PARAMETER_FOUND, map_params);
	i = 2 + jump_spaces(&(map_params->line[2]));
	fd = open(&(map_params->line[i]), O_RDONLY);
	if (fd == -1)
		print_err_exit(SYSCALL_ERROR, map_params);
	map_params->texture_fds[get_direction_index(map_params->line[0])] = fd;
	return ;
}

void	check_duplicate_parameter(t_map_parameters *map_params)
{
	if (map_params->colours[get_colour_index(map_params->line[0])][0] == -42)
		(map_params->params_count)++;
	else
		print_err_exit(REDUNDANT_PARAMETER_FOUND, map_params);
	return ;
}

void	check_colour_params_count(char **colours_array,
	t_map_parameters *map_params)
{
	int	comma_count;
	int	params_count;
	int	i;

	comma_count = 0;
	i = -1;
	while (map_params->line[++i])
		if (map_params->line[i] == ',')
			comma_count++;
	if (comma_count != 2)
		print_err_exit(INVALID_COLOUR_PARAM, map_params);
	params_count = 0;
	i = -1;
	while (colours_array[++i])
		params_count++;
	if (params_count != 3)
		print_err_exit(INVALID_COLOUR_PARAM, map_params);
	return ;
}

void	check_for_valid_colour(t_map_parameters *map_params)
{
	int		i;
	char	**colours_array;

	check_duplicate_parameter(map_params);
	colours_array = ft_split(&(map_params->line[1]), ',');
	check_colour_params_count(colours_array, map_params);
	i = -1;
	while (colours_array[++i])
	{
		map_params->colours[get_colour_index(map_params->line[0])][i] = \
			convert_colour_to_int(colours_array[i], map_params);
	}
	ft_free_ptr((void *)&colours_array);
	return ;
}
