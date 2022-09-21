/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/21 10:51:36 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char *errcode_to_string(int errcode)
{
	char *strings[] = {
		BGRAY "Undefined error message" RESET,
		"Run: " BWHITE "./cub3d " RESET UPURPLE "PATH_TO_MAP" RESET,
		"File extension must be " UPURPLE ".cub" RESET
	};
	return (strings[errcode]);
}

void	print_err_exit(int errcode)
{
	printf(PURPLEB " ❌ Error " RESET "\n");
	if (!errno)
		printf("%s\n", errcode_to_string(errcode));
	else
		perror(NULL);
	// cleanup();
	exit(errcode || errno);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		print_err_exit(1);
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		print_err_exit(2);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_err_exit(0);
	printf("%s\n", argv[1]);
	return (0);
}
