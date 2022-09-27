/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:24:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/27 11:25:47 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_args(int argc, char *argv[], int *input_fd, t_map_parameters *map_params)
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

int	jump_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
			break ;
	}
	return (i);
}

void	check_for_valid_path(t_map_parameters *map_params)
{
	int	i;
	int	fd;

	if (map_params->fds[get_direction_index(map_params->line[0])] == -42)
		(map_params->params_count)++;
	else
		print_err_exit(REDUNDANT_PARAMETER_FOUND, map_params);
	i = 2 + jump_spaces(&(map_params->line[2]));
	fd = open(&(map_params->line[i]), O_RDONLY);
	if (fd == -1)
		print_err_exit(SYSCALL_ERROR, map_params);
	map_params->fds[get_direction_index(map_params->line[0])] = fd;
	return ;
}

// todo: REFATORAR PRA SERVIR PRA TEXTURES TB ?
void check_duplicate_parameter(t_map_parameters *map_params)
{
	if (map_params->colours[get_colour_index(map_params->line[0])][0] == -42)
		(map_params->params_count)++;
	else
		print_err_exit(REDUNDANT_PARAMETER_FOUND, map_params);
	return ;
}

void check_parameter_count(char **colours_array, t_map_parameters *map_params)
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

void	check_conversion_chars(char *str, t_map_parameters *map_params)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '+' && str[i] != '-' && !ft_isdigit(str[i]))
			print_err_exit(INVALID_COLOUR_PARAM, map_params);
	}
	return ;
}

int	convert_colour_to_int(char *colour, t_map_parameters *map_params)
{
	int	colour_code;
	char *trimmed;

	trimmed = ft_strtrim(colour, " \t\v\r");
	ft_free_ptr((void*)&colour);
	check_conversion_chars(trimmed, map_params);
	colour_code = ft_atoi(trimmed);
	if (colour_code < 0 || colour_code > 255)
		print_err_exit(INVALID_COLOUR_PARAM, map_params);
	ft_free_ptr((void *)&trimmed);
	return (colour_code);
}

void	check_for_valid_colour(t_map_parameters *map_params)
{
	int		i;
	char	**colours_array;

	check_duplicate_parameter(map_params);
	colours_array = ft_split(&(map_params->line[1]), ',');
	check_parameter_count(colours_array, map_params);
	i = -1;
	while (colours_array[++i])
		map_params->colours[get_colour_index(map_params->line[0])][i] = convert_colour_to_int(colours_array[i], map_params);
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

char *get_next_line_trimmed(int input_fd)
{
	char	*line_read;
	char	*trimmed_line;

	line_read = get_next_line(input_fd);
	if (line_read && ft_strrchr(line_read, '\n') != NULL)
	{
		trimmed_line = ft_substr(line_read, 0, ft_strlen(line_read) - 1);
		ft_free_ptr((void *)&line_read);
		return (trimmed_line);
	}
	return (line_read);
}

void	validate_map_parameters(int input_fd, t_map_parameters *map_params)
{
	// REFATORAR DEPOIS
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
