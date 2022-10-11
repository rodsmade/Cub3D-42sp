/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:38:20 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/10 21:30:36 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	debug_print_map_read(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		printf(">>%s<<\n", map[i]);
}

void	debug_copy_map(t_map_parameters *data)
{
	int	map_line_count;
	int	i;

	map_line_count = ft_matrixlen(data->map);
	data->map_copy_for_debug = malloc((map_line_count + 1) * sizeof(char *));
	i = -1;
	while (data->map[++i])
		data->map_copy_for_debug[i] = ft_strdup(data->map[i]);
	data->map_copy_for_debug[i] = NULL;
	return ;
}

void	debug_print_locale(char **map, int line, int column)
{
	printf("\nLOCALE:\n");
	// LINE - 1
	printf("[ ");
	if (line > 0 && column > 0 && map[line - 1][column - 1])
		printf("%c", map[line - 1][column - 1]);
	else
		printf("x");
	printf(",    ");
	if (line > 0 && map[line - 1][column])
		printf("%c", map[line - 1][column]);
	else
		printf("x");
	printf("   , ");
	if (line > 0 && map[line - 1][column + 1])
		printf("%c", map[line - 1][column + 1]);
	else
		printf("x");
	printf("]\n");
	
	// LINE
	printf("[ ");
	if (map[line] && map[line][column - 1])
		printf("%c", map[line][column - 1]);
	else
		printf("x");
	printf(", ");
	if (map[line] && map[line][column])
		printf(" ( %c ) ", map[line][column]);
	else
		printf("x");
	printf(", ");
	if (map[line] && map[line][column + 1])
		printf("%c", map[line][column + 1]);
	else
		printf("x");
	printf("]\n");

	// LINE + 1
	printf("[ ");
	if (map[line + 1] && map[line + 1][column - 1])
		printf("%c", map[line + 1][column - 1]);
	else
		printf("x");
	printf(",    ");
	if (map[line + 1] && map[line + 1][column])
		printf("%c", map[line + 1][column]);
	else
		printf("x");
	printf("   , ");
	if (map[line + 1] && map[line + 1][column + 1])
		printf("%c", map[line + 1][column + 1]);
	else
		printf("x");
	printf("]\n");
}
