/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:48:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/29 22:45:16 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	save_map(int input_fd, t_map_parameters *map_params)
{
	char	*map_stringified;
	char	*temp;

	map_params->line = ft_charjoin(map_params->line, '\n');
	map_stringified = ft_strdup("");
	while (map_params->line)
	{
		temp = map_stringified;
		map_stringified = ft_strjoin(map_stringified, map_params->line);
		ft_free_ptr((void *)&temp);
		ft_free_ptr((void *)&map_params->line);
		map_params->line = get_next_line(input_fd);
	}
	map_params->map = ft_split(map_stringified, '\n');
	ft_free_ptr((void *)&map_stringified);
}

bool	is_valid_map(char** map)
{
	(void) map;
	return false;
}

void	validate_map(int input_fd, t_map_parameters *map_params)
{
	int	i;
	(void) input_fd;

	save_map(input_fd, map_params);
	ft_free_ptr((void *)&map_params->line);
	i = -1;
	while(map_params->map[++i])
	{
		printf("linha do mapa: >>%s<<\n", map_params->map[i]);
	}
	close(input_fd);
	if (!is_valid_map(map_params->map))
		print_err_exit(INVALID_MAP, map_params);
	return ;
}