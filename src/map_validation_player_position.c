/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_player_position.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:18:25 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/07 17:08:15 by roaraujo         ###   ########.fr       */
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
                                          
    1111111                               
    100N001                               
   1100000111        11111111111111111111 
 11100000000111    1110000000000000000001 
 1000000000000111111000000011111111111111 
 111111111110000000000000001              
           11111000001111111              
               1000001                    
               1111111                    
                                          

*/

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
		if (data->map[i][j] == '1' && data->map[i][j + 1] != '1')
			intersection_count++;
		// if (data->map[i][j + 1])
		// 	j++;
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