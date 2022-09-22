/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:24:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/21 21:24:11 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_args(int argc, char *argv[], int *input_fd)
{
	if (argc != 2)
		print_err_exit(WRONG_ARGS_NO);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		print_err_exit(FILE_EXTENSION_ERROR);
	*input_fd = open(argv[1], O_RDONLY);
	if (*input_fd == -1)
		print_err_exit(SYSCALL_ERROR);
	return ;
}

void	validate_input_file(int input_fd)
//  Except for the map content, each type of element can be separated by one or more empty line(s).
//  Except for the map, each type of information from an element can be separated by one or more space(s).
//  Except for the map content which always has to be the last, each type of element can be set in any order in the file.

// NO                                         ./path_to_the_north_texture
// SO ./path_to_the_south_texture
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture
{
	char	*line;
	int		i;
	int		temp_fd;
	char	identifier[2];

	line = get_next_line(input_fd);
	printf("line: >>%s<<\n", line);
	
	if (ft_strncmp(line, "NO ", 3) != 0
		&& ft_strncmp(line, "SO ", 3) != 0
		&& ft_strncmp(line, "WE ", 3) != 0
		&& ft_strncmp(line, "EA ", 3) != 0)
		print_err_exit(INVALID_TEXTURE_PARAMS);
	ft_strlcpy(identifier, line, 3);
	printf("identifier: >>%s<<\n", identifier);
	i = 2;
	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else
			break ;
	}
	printf("texture file: >>%s<<\n", &line[i]);
	temp_fd = open(&line[i], O_RDONLY);
	if (temp_fd == -1)
	{
		ft_free_ptr((void *)&line);
		print_err_exit(SYSCALL_ERROR);
	}
	printf("path to texture of identifier %s: %s\n", identifier, &line[i]);
	return ;
}