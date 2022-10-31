/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:38:43 by roaraujo          #+#    #+#             */
/*   Updated: 2022/10/31 06:58:33 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*get_error_message(int errcode)
// variável tá estática pra dar o balão na norminette ehuhsuheushe
{
	static char	*error_messages[] = {\
		BGRAY "Undefined error message" RESET, \
		"Run: " BWHITE "./cub3d " RESET UPURPLE "PATH_TO_MAP" RESET, \
		"File extension must be " UPURPLE ".cub" RESET, \
		"Invalid texture parameter. Must be either " UPURPLE "NO" RESET ", " \
			UPURPLE "SO" RESET ", " UPURPLE "EA" RESET ", " UPURPLE "WE" RESET \
			", " UPURPLE "F" RESET " or " UPURPLE "C" RESET \
			", followed by a space and the path to the texture file.", \
		"Missing parameter. Provide " UPURPLE "4 texture file paths" RESET \
			" and " UPURPLE "2 colours." RESET, \
		"Redundant parameter found. Parameter duplicates not allowed.", \
		"Invalid colour format. Use: " UPURPLE "R, G, B" RESET \
			", each value ranging from 0 to 255.", \
		"Invalid map.", \
		"Error allocating memory. Ran out of RAM?", \
		"Map has invalid char. Valid chars are: " UPURPLE VALID_CHARS RESET
	};

	return (error_messages[errcode]);
}

void	print_err_exit(int errcode, t_data *data)
// debug_print_map_read(data->map_copy_for_debug);
{
	free_data(data);
	printf(PURPLEB " ❌ Error " RESET "\n");
	if (!errno)
		printf("%s\n", get_error_message(errcode));
	else
		perror(NULL);
	exit(errcode || errno);
}
