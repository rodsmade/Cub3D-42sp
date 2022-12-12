/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:52:15 by roaraujo          #+#    #+#             */
/*   Updated: 2022/12/12 20:15:25 by roaraujo         ###   ########.fr       */
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

bool	check_conversion_chars(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '+' && str[i] != '-' && !ft_isdigit(str[i]))
		{
			ft_free_ptr((void *)&str);
			return (false);
		}
	}
	return (true);
}

int	convert_colour_to_int(char *colour)
{
	int		colour_code;
	char	*trimmed;

	trimmed = ft_strtrim(colour, " \t\v\r");
	if (!check_conversion_chars(trimmed))
		return (-1);
	colour_code = ft_atoi(trimmed);
	ft_free_ptr((void *)&trimmed);
	if (colour_code < 0 || colour_code > 255)
		return (-1);
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
