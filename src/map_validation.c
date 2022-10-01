/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusalves <gusalves@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:48:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/30 22:37:33 by gusalves         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	is_map_surrounded_by_one(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((i == 0 || !map[i + 1]) && map[i][j] != '1')
				return false;
			if ((j == 0 || !map[i][j + 1]) && map[i][j] != '1')
				return false;
			j++;
		}
		i++;
	}
	return true;
}

bool	is_valid_map(char** map)
{
	if (!is_map_surrounded_by_one(map))
		return false;
	return true;
}

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
