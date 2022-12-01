/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:31:48 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/31 06:32:30 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	find_longest_line_length(char **map)
{
	int	max_length;
	int	line_length;
	int	i;

	max_length = 0;
	i = -1;
	while (map[++i])
	{
		line_length = (int) ft_strlen(map[i]);
		if (line_length > max_length)
			max_length = line_length;
	}
	return (max_length);
}
