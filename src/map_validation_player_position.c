/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_player_position.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:18:25 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/07 18:31:30 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	find_player_starting_position(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
			if (ft_strchr(STARTING_CHARS, data->map[i][j]))
				break ;
		if (data->map[i][j] && ft_strchr(STARTING_CHARS, data->map[i][j]))
			break ;
	}
	data->starting_position.line = i;
	data->starting_position.column = j;
	return ;
}

/*
                                                        
    1111111            11111    11111    11111    11111 
    1000001            10001    10001    10001    10001 
   1100000111        1110001    10001    10001    10001 
 11100E00000111    111000001111110001111110001111110001 
 100000000000011111100000000000000000000000000000000001 
 111111111110000000000000000000000000000000000000000001 
           11111000001111111111111111111111111111111111 
               1000001                                  
               1111111                                  
                                                        

*/

int	check_for_inflection_point(int i, int j, t_data *data)
{
	int	in;
	int	out;

	if (data->map[i - 1][j] == '1')
		in = UP;
	else
		in = DOWN;
	while (data->map[i][++j] == '1')
		continue ;
	if (data->map[i - 1][j - 1] == '1')
		out = UP;
	else
		out = DOWN;
	if (in != out)
		return (1);
	return (0);
}

void	check_player_is_inside_map(t_data *data)
{
	int	i;
	int	j;
	int	intersection_count;

	intersection_count = 0;
	i = data->starting_position.line;
	j = data->starting_position.column;
	while (data->map[i][++j])
	{
		if (data->map[i][j] != '1')
			continue ;
		if (data->map[i][j] == '1' && data->map[i][j + 1] != '1')
			intersection_count++;
		else
		{
			intersection_count += check_for_inflection_point(i, j, data);
			while (data->map[i][++j] == '1')
				continue ;
		}
	}
	if (intersection_count % 2 == 0)
		print_err_exit(PLAYER_OFF_MAP, data);
	return ;
}

void	check_player_position(t_data *data)
{
	find_player_starting_position(data);
	check_player_is_inside_map(data);
	return ;
}
