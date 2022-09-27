/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:24:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/27 12:00:15 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_args(int argc, char *argv[], int *input_fd,
	t_map_parameters *map_params)
{
	if (argc != 2)
		print_err_exit(WRONG_ARGS_NO, map_params);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		print_err_exit(FILE_EXTENSION_ERROR, map_params);
	*input_fd = open(argv[1], O_RDONLY);
	if (*input_fd == -1)
		print_err_exit(SYSCALL_ERROR, map_params);
	return ;
}

void	retrieve_parameter(t_map_parameters *map_params)
{
	char	identifier[2];

	if (!has_valid_param_identifier(map_params->line))
		print_err_exit(INVALID_TEXTURE_PARAMS, map_params);
	ft_strlcpy(identifier, map_params->line, 3);
	if (is_direction_identifier(identifier))
		check_for_valid_path(map_params);
	else
		check_for_valid_colour(map_params);
}

void	validate_map_parameters(int input_fd, t_map_parameters *map_params)
{
	init_map_parameters(map_params);
	(map_params->line) = get_next_line_trimmed(input_fd);
	while ((map_params->line))
	{
		if ((map_params->line)[0])
		{
			if (is_valid_parameter_char((map_params->line)[0]))
				retrieve_parameter(map_params);
			else
				break ;
		}
		ft_free_ptr((void *)&(map_params->line));
		(map_params->line) = get_next_line_trimmed(input_fd);
	}
	ft_free_ptr((void *)&(map_params->line));
	if (map_params->params_count != 6)
		print_err_exit(MISSING_PARAMETER, map_params);
}

void	validate_input_file(int input_fd, t_map_parameters *map_params)
/*
	idealmente vai ter tb as funçoes:
		open_texture_files()
		validate_map()
*/
{
	validate_map_parameters(input_fd, map_params);
}
