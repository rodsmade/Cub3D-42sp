/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:24:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/01 10:47:34 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_args(int argc, char *argv[], t_data *data)
{
	if (argc != 2)
		print_err_exit(WRONG_ARGS_NO, data);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		print_err_exit(FILE_EXTENSION_ERROR, data);
	data->map_data.input_fd = open(argv[1], O_RDONLY);
	if (data->map_data.input_fd == -1)
		print_err_exit(SYSCALL_ERROR, data);
	return ;
}

void	retrieve_parameter(t_data *data)
{
	char	identifier[2];

	if (!has_valid_param_identifier(data->map_data.line))
		print_err_exit(INVALID_TEXTURE_PARAMS, data);
	ft_strlcpy(identifier, data->map_data.line, 3);
	if (is_direction_identifier(identifier))
		check_for_valid_path(data);
	else
		check_for_valid_colour(data);
}

void	validate_map_parameters(t_data *data)
{
	(data->map_data.line) = get_next_line_trimmed(data->map_data.input_fd);
	while ((data->map_data.line))
	{
		if ((data->map_data.line)[0])
		{
			if (is_valid_parameter_char((data->map_data.line)[0]))
				retrieve_parameter(data);
			else
				break ;
		}
		ft_free_ptr((void *)&(data->map_data.line));
		(data->map_data.line) = get_next_line_trimmed(data->map_data.input_fd);
	}
	if (data->map_data.params_count != 6)
		print_err_exit(MISSING_PARAMETER, data);
}

void	validate_input_file(t_data *data)
/*
	idealmente vai ter tb as funçoes:
		open_texture_files()
		validate_map()
*/
{
	validate_map_parameters(data);
	validate_map(data);
}
