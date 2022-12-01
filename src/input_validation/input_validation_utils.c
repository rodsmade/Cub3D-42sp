/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:52:15 by roaraujo          #+#    #+#             */
/*   Updated: 2022/11/17 12:15:55 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	check_conversion_chars(char *str, t_data *data)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '+' && str[i] != '-' && !ft_isdigit(str[i]))
			print_err_exit(INVALID_COLOUR_PARAM, data);
	}
	return ;
}

int	convert_colour_to_int(char *colour, t_data *data)
{
	int		colour_code;
	char	*trimmed;

	trimmed = ft_strtrim(colour, " \t\v\r");
	ft_free_ptr((void *)&colour);
	check_conversion_chars(trimmed, data);
	colour_code = ft_atoi(trimmed);
	if (colour_code < 0 || colour_code > 255)
		print_err_exit(INVALID_COLOUR_PARAM, data);
	ft_free_ptr((void *)&trimmed);
	return (colour_code);
}

char	*get_next_line_trimmed(int input_fd)
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
