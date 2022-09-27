/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:58:10 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/27 09:14:05 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	get_colour_index(char c)
{
	if (c == 'C')
		return (CEILING);
	if (c == 'F')
		return (FLOOR);
	return (-1);
}

bool	is_valid_parameter_char(char  c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W'
			|| c == 'F' || c == 'C');
}

bool has_valid_param_identifier(char *str)
{
	return (ft_strncmp(str, "NO ", 3) == 0
		|| ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0
		|| ft_strncmp(str, "EA ", 3) == 0
		|| ft_strncmp(str, "F ", 2) == 0
		|| ft_strncmp(str, "C ", 2) == 0);
}
