/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:38:20 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/10 12:41:45 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	debug_print_map_read(char **map)
{
	int	i;

	i = -1;
	while(map[++i])
		printf(">>%s<<\n", map[i]);
}

void	debug_copy_map(t_map_parameters *map_params)
{
	int map_line_count = ft_matrixlen(map_params->map);
	map_params->map_copy_for_debug = malloc((map_line_count + 1) * sizeof(char *));
	int i = -1;
	while (map_params->map[++i])
		map_params->map_copy_for_debug[i] = ft_strdup(map_params->map[i]);
	map_params->map_copy_for_debug[i] = NULL;
	return ;
}
