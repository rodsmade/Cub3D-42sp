/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roaraujo <roaraujo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:52:14 by gusalves          #+#    #+#             */
/*   Updated: 2022/09/21 10:18:04 by roaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char *err_nbr_to_string(int err_nbr)
{
	char *strings[] = {
		"",
		"Wrong number of arguments. Run: " BWHITE "./cub3d " RESET \
		UPURPLE "PATH_TO_MAP" RESET
	};
	return (strings[err_nbr]);
}

void	printerr_exit(int err_nbr)
{
	printf(PURPLEB " ❌ Error \n" RESET);
	printf("%s\n", err_nbr_to_string(err_nbr));
	// cleanup();
	exit(err_nbr);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		printerr_exit(1);
	fd = open("exoterico.txt", O_RDONLY);
	if (fd == -1)
	{
		perror(NULL);
		printf("errno: %i\n", errno);
		printf("%s\n", strerror(errno));
		exit(errno);
	}
	printf("%s\n", argv[1]);
	return (0);
}
