/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 19:38:43 by roaraujo          #+#    #+#             */
/*   Updated: 2022/09/21 21:19:00 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*get_error_message(int errcode)
{
	static char	*error_messages[] = {\
		BGRAY "Undefined error message" RESET, \
		"Run: " BWHITE "./cub3d " RESET UPURPLE "PATH_TO_MAP" RESET, \
		"File extension must be " UPURPLE ".cub" RESET, \
		"Wrong texture parameter. Must be either " UPURPLE "NO" RESET ", " \
			UPURPLE "SO" RESET ", " UPURPLE "EA" RESET " or " \
			UPURPLE "WE" RESET ", followed by a space and the path to " \
			"the texture file." \
		};

	return (error_messages[errcode]);
}

void	print_err_exit(int errcode)
{
	printf(PURPLEB " ❌ Error " RESET "\n");
	if (!errno)
		printf("%s\n", get_error_message(errcode));
	else
		perror(NULL);
	exit(errcode || errno);
}
