/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:24:02 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/22 22:01:32 by roaraujo         ###   ########.fr       */
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

typedef struct s_textures 
{
	int		fds[4];
	int		colours[2][3];
	int		params_count;
}		t_textures;

enum e_directions {NO, SO, EA, WE};
enum e_colours {CEILING, FLOOR};

void	init_textures(t_textures *textures)
{
	textures->fds[NO] = -42;
	textures->fds[SO] = -42;
	textures->fds[EA] = -42;
	textures->fds[WE] = -42;
	textures->colours[FLOOR][0] = -42;
	textures->colours[CEILING][0] = -42;
	textures->params_count = 0;
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

bool	is_direction_identifier(char identifier[2])
{
	return (ft_strncmp(identifier, "NO", 2) == 0
			|| ft_strncmp(identifier, "SO", 2) == 0
			|| ft_strncmp(identifier, "WE", 2) == 0
			|| ft_strncmp(identifier, "EA", 2) == 0);
}

int	get_direction_index(char d)
{
	if (d == 'N')
		return (NO);
	if (d == 'S')
		return (SO);
	if (d == 'E')
		return (EA);
	if (d == 'W')
		return (WE);
	return (-1);
}

int	get_colour_index(char d)
{
	if (d == 'C')
		return (CEILING);
	if (d == 'F')
		return (FLOOR);
	return (-1);
}

void	redundant_parameter_exit(char *line)
{
	ft_free_ptr((void *)&line);
	print_err_exit(REDUNDANT_PARAMETER_FOUND);
}

void	check_for_valid_path(char *line, t_textures *textures)
{
	int	i;
	int	fd;

	printf("line: >>%s<<\n", line);
	if (textures->fds[get_direction_index(line[0])] == -42)
		(textures->params_count)++;
	else
		redundant_parameter_exit(line);
	i = 2 + jump_spaces(&line[2]);
	fd = open(&line[i], O_RDONLY);
	if (fd == -1)
	{
		ft_free_ptr((void *)&line);
		print_err_exit(SYSCALL_ERROR);
	}
	textures->fds[get_direction_index(line[0])] = fd;
	return ;
}

void	check_for_valid_colour(char *line, t_textures *textures)
{
	int	i;
	int	n;

	if (textures->colours[get_colour_index(line[0])][0] == -42)
		(textures->params_count)++;
	else
		redundant_parameter_exit(line);
	i = 1 + jump_spaces(&line[1]);
	if (!ft_isdigit(line[i]))
		print_err_exit(INVALID_COLOUR_PARAM);
	n = 0;
	i--;
	while (ft_isdigit(line[++i]))
		n++;
	if (n > 3)
		print_err_exit(INVALID_COLOUR_PARAM);
	char	temp_a[3];
	int		temp_i;
	ft_strlcpy(temp_a, &line[i - n], n + 1);
	temp_i = ft_atoi(temp_a);
	if (temp_i > 255 || temp_i < 0)
		print_err_exit(INVALID_COLOUR_PARAM);
	textures->colours[get_colour_index(line[0])][0] = temp_i;
	// test failed, check again.

	// i = 1 + jump_spaces(&line[1]);
	// if (line[i] != ',')
	// 	print_err_exit(INVALID_COLOUR_PARAM);




	// TODO: implement actual colour logic:
	// textures->colours[get_colour_index(line[0])][0] = 0;
	return ;
}

void	check_for_valid_identifier(char *line, t_textures *textures)
{
	char	identifier[2];

	if (ft_strncmp(line, "NO ", 3) != 0
		&& ft_strncmp(line, "SO ", 3) != 0
		&& ft_strncmp(line, "WE ", 3) != 0
		&& ft_strncmp(line, "EA ", 3) != 0
		&& ft_strncmp(line, "F ", 2) != 0
		&& ft_strncmp(line, "C ", 2) != 0)
	{
		ft_free_ptr((void *)&line);
		print_err_exit(INVALID_TEXTURE_PARAMS);
	}
	ft_strlcpy(identifier, line, 3);
	if (is_direction_identifier(identifier))
		check_for_valid_path(line, textures);
	else
		check_for_valid_colour(line, textures);
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

void	validate_texture_parameters(int input_fd)
{
	static t_textures	textures;
	// line tem q estar dentro do structzão
	char				*line;

	// REFATORAR DEPOIS
	init_textures(&textures);

	line = get_next_line_trimmed(input_fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 2) != 0)
		{
			// achou algo diferente de \n
			if (line[0] == 'N' || line[0] == 'S' || line[0] == 'E' || line[0] == 'W' || line[0] == 'F' || line[0] == 'C')
				check_for_valid_identifier(line, &textures);
			else
				break ;
		}
		ft_free_ptr((void *)&line);
		line = get_next_line_trimmed(input_fd);
	}
	ft_free_ptr((void *)&line);
	if (textures.params_count != 6)
		print_err_exit(MISSING_PARAMETER);
	// sai dessa função com line na posição onde (inicia o mapa)
}

void	open_texture_files(void)
{
	
}

void	validate_map(void)
{
	
}

void	validate_input_file(int input_fd)
{
	validate_texture_parameters(input_fd);
	open_texture_files();
	validate_map();
}
//  Except for the map content, each type of element can be separated by one or more empty line(s).
//  Except for the map, each type of information from an element can be separated by one or more space(s).
//  Except for the map content which always has to be the last, each type of element can be set in any order in the file.

// NO                                         ./path_to_the_north_texture
// SO ./path_to_the_south_texture
//
// 
// 
// Fnumeros
// 
// WE ./path_to_the_west_texture
// EA ./path_to_the_east_texture
// 
// C numeros
// 
//         1111111111
// 111111111000000011
// 111000000000000011
// 110000000000000011
// 110000000000000011
// 111111111111111111


// lê o arquivo de uma vez
// 1. se começa com E W N S F ou C, parte pra capturar o identifier. 
// 		1. valida a linha de identifier (throws INVALID_TEXTURE_PARAMS)
// 		2. se tudo ok, copia o path. (ainda não valida existência do arquivo? ou se pá já valida tb.)
// 2. encontrou a primeira alguma coisa diferente de \n ou NSEWFC, eu conto os identifiers q tenho. se estiver faltando, missing identifier. (MISSING_PARAMETER)
//  se não, o resto é considerado mapa.
// depois valida o mapa.

// {
// 	char	*line;
// 	int		i;
// 	int		temp_fd;
// 	char	identifier[2];


// 	line = get_next_line(input_fd);
// 	printf("line: >>%s<<\n", line);
	
// 	while (line)
// 	{
// 		line = get_next_line(input_fd)
// 	}

	
// 	check_for_valid_identifier(line);
// 	ft_strlcpy(identifier, line, 3);
// 	printf("identifier: >>%s<<\n", identifier);
// 	i = 2;
// 	while (line[i])
// 	{
// 		if (line[i] == ' ')
// 			i++;
// 		else
// 			break ;
// 	}
// 	printf("texture file: >>%s<<\n", &line[i]);
// 	temp_fd = open(&line[i], O_RDONLY);
// 	if (temp_fd == -1)
// 	{
// 		ft_free_ptr((void *)&line);
// 		print_err_exit(SYSCALL_ERROR);
// 	}
// 	printf("path to texture of identifier %s: %s\n", identifier, &line[i]);
// 	return ;
// }